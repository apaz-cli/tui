#ifndef NTUI_TUIWIN_INCLUDE
#define NTUI_TUIWIN_INCLUDE

#include "list.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tuiwin_t;
typedef struct tuiwin_t tuiwin_t;
LIST_DECLARE(tuiwin_t);
struct tuiwin_t {
  tuiwin_t *parent;
  list_tuiwin_t children;
};
LIST_DEFINE(tuiwin_t);

typedef struct {
  int t, b, l, r;
  int tl, tr, bl, br;
} ntui_border_t;

static inline tuiwin_t *ntui_tuiwin_init(tuiwin_t *win, tuiwin_t *parent, int x,
                                         int y, int width, int height) {
  /* Initial initialization, about to be resized anyway. */
  if (!parent) {
    win->parent = NULL;
    win->children = list_tuiwin_t_new();
    return win;
  }

  /* Otherwise, sanity check. */
  return win;
}

static inline tuiwin_t *ntui_borderwin_init(tuiwin_t *win, tuiwin_t *parent,
                                            tuiwin_t *child,
                                            ntui_border_t border) {
  return win;
}

#endif /* NTUI_TUIWIN_INCLUDE */