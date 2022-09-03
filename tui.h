#include "libtmt/tmt.h"

#include <locale.h>
#include <signal.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#define MAX_COMPONENTS 64
#define MAX_CHILDREN 64

typedef struct {
  uint16_t new_width, new_height;
} ResizeEvent;

typedef struct {
  uint16_t mouse_x, mouse_y;
  enum {
    MOUSE_BUTTON_1,
    MOUSE_BUTTON_2,
    MOUSE_BUTTON_3,
    MOUSE_MOVE,
  } mouse_action;
} MouseEvent;

typedef struct {
  wchar_t key;
} KeyEvent;

typedef enum { END, RESIZE, MOUSE, KEY } EventKind;

typedef struct {
  bool handled;
  EventKind kind;
  union {
    ResizeEvent resizeEvent;
    MouseEvent mouseEvent;
    KeyEvent keyEvent;
  };
} Event;

struct Component;
typedef struct Component Component;

typedef struct {
  TMT *screen;

  uint16_t window_width;
  uint16_t window_height;

  bool _needs_resize;
  bool _exiting;

  // Things towards the back of the list
  // are on top of the ones at the front.
  uint16_t num_components;
  Component *componentList[MAX_COMPONENTS];
  Component *rootComponent;
} GlobalContext;

static GlobalContext *globalcontext;

typedef struct {
  uint16_t x, y;
  uint16_t width, height;
} Position;

struct Component {
  GlobalContext *context;
  Component *parent;

  Position pos;

  uint16_t num_children;
  Component *children[MAX_CHILDREN];

  int (*onClick)(MouseEvent event);  // Returns if the event was handled by one
                                     // of its children or not.
  int (*onKeypress)(KeyEvent event); // Returns if the event was handled by one
                                     // of its children or not.
  void (*render)(TMT *screen);       // Calls the render() of any subcomponents.
  void (*resize)(Position new_pos);  // Calls the resize() of any subcomponents.

  enum {
    Kind1,
    Kind2,
    // For each kind of component
  } kind;
  union {
    struct {
      // ...
    } ComponentKind1Data;
    struct {
      // ...
    } ComponentKind2Data;
    // For all the stuff each kind of component has to store
  };
};

static inline bool inComponent(Component *c, uint16_t x, uint16_t y) {
  Position p = c->pos;
  return (x >= p.x) & (x <= p.x + p.width) & (y >= p.y) & (y <= p.y + p.height);
}

// Move component to the front of the list
static void raiseComponent(Component *c) {
  uint16_t nc = globalcontext->num_components;
  Component **components = globalcontext->componentList;

  if (nc <= 1)
    return;
  Component *tmp = components[0];
  if (tmp == c)
    return;
  components[0] = c;

  for (size_t i = 1; i < nc; i++) {
    Component *despot = components[i];
    if (despot == c) {
      components[i] = tmp;
      break;
    } else {
      components[i] = tmp;
      tmp = despot;
    }
  }
}

static inline void updateSize(void) {
  struct winsize ws;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
#if (USHRT_MAX > UINT16_MAX)
  if ((ws.ws_row > UINT16_MAX) | (ws.ws_col > UINT16_MAX)) {
    const char errmsg[] = "Tui can't handle a terminal this big.\n";
    fprintf(stderr, errmsg);
    exit(1);
  }
#endif
  globalcontext->window_width = (uint16_t)ws.ws_col;
  globalcontext->window_height = (uint16_t)ws.ws_row;
}

// Resize signals
static void sigwinch_handler(int sig) {
  // Need to have this be a legit global variable.
  // Can't get a reference to it inside a signal handler otherwise.
  (void)sig;
  if (!globalcontext)
    return;
  globalcontext->_needs_resize = true;
}

// Same as above, but handles SIGINT and sets '_exiting'
static void sigint_handler(int sig) {
  (void)sig;
  if (!globalcontext)
    return;
  globalcontext->_exiting = true;
}

typedef void (*tuisighandler_t)(int);
static struct termios _tio_old;
static tuisighandler_t _old_sigwinch;
static char *_old_locale;

static inline void lib_init(void) {
  // Install signal handlers, save what they used to be.
  // Get term size
  // Initialize global context
  // Initialize memory for screenbuffer
  // Initialize memory allocator

  // Swap to alt screenbuffer
  tcgetattr(1, &_tio_old);
  struct termios _tio_new = _tio_old;
  _tio_new.c_lflag &= (~ECHO & ~ICANON);
  tcsetattr(1, TCSANOW, &_tio_new);

  // Clear the terminal
  char clear_cmd[] = "\x1b[2J";
  write(1, clear_cmd, sizeof(clear_cmd));

  // Copy the current locale, set new one
  _old_locale = setlocale(LC_CTYPE, NULL);
  if (!_old_locale) {
    if (!setlocale(LC_ALL, "C.UTF-8")) {
      if (!setlocale(LC_ALL, "en_US.UTF-8")) {
        fprintf(stderr, "Could not set locale to utf8.\n");
        exit(1);
      }
    }
  }

  // Initialize the global context
  globalcontext->_exiting = 0;
  globalcontext->_needs_resize = 0;

  // Get the terminal size, init tmt
  updateSize();
  globalcontext->screen =
      tmt_open(globalcontext->window_height, globalcontext->window_width, NULL,
               NULL, NULL);

  // Init component list
  globalcontext->rootComponent = NULL;
  globalcontext->num_components = 0;
  for (size_t i = 0; i < MAX_COMPONENTS; i++)
    globalcontext->componentList[i] = NULL;
}

static inline void lib_deinit(void) {
  // Swap back in old signal handlers
  // Free all memory
  // Swap back to normal screenbuffer

  tcsetattr(1, TCSANOW, &_tio_old);
  signal(SIGWINCH, _old_sigwinch);
}

static inline Event handle_event(void) {
  Event e;
  if (globalcontext->_exiting)
    return (e.kind = END, e.handled = 0), e;

  Component **components = globalcontext->componentList;

  // Resize in response to SIGWINCH
  if (globalcontext->_needs_resize) {
    // Check for SIGWINCH
    globalcontext->_needs_resize = 0;

    // Ask the OS for the new size
    updateSize();

    // Bubble resizes down
    globalcontext->rootComponent->resize((Position){
        0, 0, globalcontext->window_width, globalcontext->window_height});

    // return resize info
    e.kind = RESIZE;
    e.handled = 1;
    e.resizeEvent.new_height = globalcontext->window_height;
    e.resizeEvent.new_width = globalcontext->window_width;
    return e;
  }

  // Get event from some dependency

  // Handle the event (This depends on the kind of event.)

  // For KEY and MOUSE events, find the topmost component that it applies
  // to (overlaps the (x,y) coordinate where the event happened, and has
  // the applicable event handler).
  // That event handler will give the event to its parent if it doesn't
  // want to handle, it, then it to its parent, etc. At the end, we mark
  // it as handled or not.

  for (uint16_t i = 0; i < globalcontext->num_components; i++) {
    if (e.kind == KEY) {
      if (components[i]->onKeypress) {
        e.handled = components[i]->onKeypress(e.keyEvent);
        if (e.handled)
          break;
      }
    } else if (e.kind == MOUSE) {
      if (components[i]->onClick) {
        if (inComponent(components[i], e.mouseEvent.mouse_x,
                        e.mouseEvent.mouse_y)) {
          e.handled = components[i]->onClick(e.mouseEvent);
          if (e.handled)
            break;
        }
      }
    }
  }

  return e;
}

// First: Are the attrs equal?
// If yes, return _unused1 = true immediately.
// Second: Are there any bits set in b1 that are not set in b2?
// If yes, return _unused2 = true immediately.
// Third: What bits are present in b2 that are not present in b1?
// Return that.
static inline TMTATTRS subtract_attr_bits(TMTATTRS b1, TMTATTRS b2) {

  b1._unused1 = 0;
  b1._unused2 = 0;
  b2._unused1 = 0;
  b2._unused2 = 0;

  uint8_t b1attrs, b2attrs;
  memcpy(&b1attrs, (char *)&b1 + offsetof(TMTATTRS, attrs), sizeof(uint8_t));
  memcpy(&b2attrs, (char *)&b2 + offsetof(TMTATTRS, attrs), sizeof(uint8_t));

  return b1;
}

static inline void writescreen(TMT *tmt) {
  // For every dirty line in the screen, render the line.
  const TMTSCREEN *screen = tmt_screen(globalcontext->screen);
  size_t nline = screen->nline, ncol = screen->ncol;
  for (size_t lnum = 0; lnum < nline; lnum++) {
    TMTLINE *line = screen->lines[lnum];
    if (!line->dirty)
      continue;

    TMTATTRS last;
    last.fg = (tmt_color_t){0, 0, 0, TMT_ANSI_COLOR_DEFAULT};
    last.bg = (tmt_color_t){0, 0, 0, TMT_ANSI_COLOR_DEFAULT};
    last.attrs = 0;
    for (size_t cnum = 0; cnum < ncol; cnum++) {
      wchar_t c = line->chars[cnum].c;
      TMTATTRS attrs = line->chars[cnum].a;
      if (attrs.reverse) {
        tmt_color_t tmp = attrs.bg;
        attrs.bg = attrs.fg;
        attrs.fg = tmp;
        attrs.reverse = 0;
      }

      size_t cbuflen = 0;
      char cbuffer[64];

      // Apply colors and attributes

      // Finally append the character and write.
      // If wctomb doesn't know about that character,
      // use the unicode replacement character.
      int wcret = wctomb(cbuffer, c);
      if (wcret == -1) {
        const char replacement_char[] = "\uFFFD";
        wcret = sprintf(cbuffer, replacement_char);
      }
      cbuflen += wcret;
      tmt_write(tmt, cbuffer, cbuflen);
    }
  }
}

static inline void render_window(void) {
  globalcontext->rootComponent->render(globalcontext->screen);
  writescreen(globalcontext->screen);
}

static inline int example_main(void) {
  // Render loop
  lib_init();

  // Build out component tree

  for (;;) {
    Event e = handle_event();
    if (e.kind == END)
      break;

    // Do whatever we want based on events
    // and if they've already been handled
    // by callbacks or not. Generally speaking,
    // components should be in charge of changing
    // themselves.

    render_window();
  }
  lib_deinit();

  return 0;
}
