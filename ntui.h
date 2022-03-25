#ifndef NTUI_INCLUDE
#define NTUI_INCLUDE

#include <ncurses.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

/**************/
/* Structures */
/**************/

#define TYPE_DEFINE(name)
struct tuiwin_t;
typedef struct tuiwin_t tuiwin_t;
LIST_DECLARE(tuiwin_t);
struct tuiwin_t {
  tuiwin_t *parent;
  ntuilist_tuiwin_t children;
};
LIST_DEFINE(tuiwin_t);

typedef struct {
  WINDOW *win;
  tuiwin_t *root;
} ntui_t;

/*******/
/* API */
/*******/

static inline ntui_t *ntui_init(ntui_t *tui) {

  /* Initializen curses. */
  tui->win = initscr();
  tui->root = NULL;

  /* Set up the tty to be taken over. */
  raw();
  keypad(stdscr, TRUE);
  noecho();
  cbreak();
  clear();

  /* Get absolutely everything as a mouse event.
     Gather maximum information. */
  mousemask(ALL_MOUSE_EVENTS | BUTTON_SHIFT | BUTTON_CTRL | BUTTON_ALT |
                REPORT_MOUSE_POSITION,
            NULL);
  return tui;
}

static inline void ntui_destroy(ntui_t *tui) { endwin(); }

#endif /* NTUI_INCLUDE */