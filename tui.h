
struct Event {
  bool handled;
  enum {END, RESIZE, MOUSE, KEY} kind;
  union {
    struct ResizeEvent {
      uint16_t new_width, new_height;
    };
    struct MouseEvent {
      uint16_t mouse_x, mouse_y;
      enum {MOUSE_BUTTON_1, MOUSE_BUTTON_2, MOUSE_BUTTON_3, MOUSE_MOVE} mouse_action;
    };
    struct KeyEvent {
      unichar_t key;
    };
  };
}

struct GlobalContext {
  ScreenBuffer screen;

  MemoryAllocator alloc;

  uint16_t window_width;
  uint16_t window_height;

  bool _needs_resize;
  bool _exiting;

  // Things towards the back of the list
  // are on top of the ones at the front.
  uint16_t num_components;
  Component* componentList[MAX_COMPONENTS];
  Component* rootComponent;
};

GlobalContext* globalcontext;

struct Position {
  uint16_t x, y;
  uint16_t width, height;
};

struct Component {
  GlobalContext* context;
  Component* parent;

  Position pos;

  uint16_t num_children;
  Component* children[MAX_CHILDREN];

  int  (*onClick)(ClickEvent event);    // Returns if the event was handled by one of its children or not.
  int  (*onKeypress)(KeyEvent event);   // Returns if the event was handled by one of its children or not.
  void (*render)(ScreenBuffer* screen); // Calls the render() of any subcomponents.
  void (*resize)(Position new_pos);     // Calls the resize() of any subcomponents.

  enum {
    Kind1,
    Kind2,
    // For each kind of component
  }; kind;
  union {
    struct { ... } ComponentKind1Data;
    struct { ... } ComponentKind2Data;
    // For all the stuff each kind of component has to store
  };
};

bool inComponent(Component* c, uint16_t x, uint16_t y) {
  Position p = c->pos;
  return (x >= p.x) & (x <= p.x + p.width) & (y >= p.y) & (y <= p.y + p.height)
}

// Resize signals
void sigwinch_handler(int sig) {
  // Need to have this be a legit global variable.
  // Can't get a reference to it inside a signal handler otherwise.
  (void)sig;
  if (!global_context) return;
  global_context->_needs_resize = true;
}

// Same as above, but handles SIGINT and sets '_exiting'
void sigint_handler(int sig);

// Move component to the front of the list
void raiseComponent(Component* c) {
  uint16_t nc = globalcontext->num_components;
  Component** components = globalContext->components;

  if (nc <= 1) return;
  Component* tmp = components[0];
  if (tmp == c) return;
  components[0] = c;

  for (size_t i = 1; i < nc; i++) {
    Component* despot = components[i];
    if (despot == c) {
      components[i] = tmp;
      break;
    } else {
      components[i] = tmp;
      tmp = despot;
    }
  }
}

void lib_init(void) {
  // Install signal handlers, save what they used to be.
  // Get term size
  // Initialize global context
  // Swap to alt screenbuffer
  // Initialize memory for screenbuffer
  // Initialize memory allocator
}

Event handle_event(void) {
  Event e;
  if (globalcontext->_exiting)
    return (e.kind = END, e.handled = 0), e;

  Component** components = globalcontext->components;

  // Resize in response to SIGWINCH
  if (globalcontext->_needs_resize) {
    // Check for SIGWINCH
    globalcontext->_needs_resize = 0;

    // Ask the OS for the new size
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    global_context->window_width = ws.ws_col;
    global_context->window_height = ws.ws_row;

    // Bubble resizes down
    global_context->root_component->resize((Position){0, 0, ws.ws_col, ws.ws_row});

    // return resize info
    e.kind = RESIZE;
    e.handled = 1;
    e.new_height = ws.ws_row;
    e.new_width  = ws.ws_col;
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
        e.handled = components[i]->onClick(e);
        if (e.handled) break;
      }
    }
    else if (e.kind == MOUSE) {
      if (components[i]->onClick) {
        if(inComponent(components[i], e.mouse_x, e.mouse_y)) {
          e.handled = components[i]->onClick(e);
          if (e.handled) break;
        }
      }
    }
  }

  return e;
}

void render_window(void) {
  globalcontext->root_component->render(globalcontext->screen);
  writescreen(globalcontext->screen);
}

void lib_deinit(void) {
  // Swap back in old signal handlers
  // Free all memory
  // Swap back to normal screenbuffer
}


int main(void) {
  // Render loop
  lib_init();

  // Build out component tree

  for (;;) {
    Event e = handle_event();
    if (e.kind == END) break;

    // Do whatever we want based on events
    // and if they've already been handled
    // by callbacks or not. Generally speaking,
    // components should be in charge of changing
    // themselves.

    render_window();
  }
  lib_deinit();
}
