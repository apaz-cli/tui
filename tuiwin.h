#ifndef NTUI_TUIWIN_INCLUDE
#define NTUI_TUIWIN_INCLUDE

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "list.h"

#define TUIWIN_EMPTYWIN 0
#define TUIWIN_MAINWIN 1
#define TUIWIN_TEXTWIN 2
#define TUIWIN_IMAGEWIN 3
#define TUIWIN_BORDERWIN 4
#define TUIWIN_LRSPLITWIN 5
#define TUIWIN_UBSPLITWIN 6


// TODO replace with UTF8 support.

typedef int codepoint_t;

typedef struct {
  codepoint_t c;
  uint8_t fgcolor;
  uint8_t bgcolor;
  struct {
    bool bold : 1;
    bool dim : 1;
    bool underline : 1;
    bool blink : 1;
    bool reverse : 1;
    bool invisible : 1;
  } attrs;
  bool dirty;
} tuichar_t; // 64 bits on all sensible platforms.

static inline tuichar_t tuichar_new(codepoint_t c) {
  tuichar_t tc;
  memset(&tc, 0, sizeof(tc));
  tc.c = c;
  return tc;
}

LIST_DECLARE(tuichar_t);
LIST_DEFINE(tuichar_t);

LIST_DECLARE(list_tuichar_t);
LIST_DEFINE(list_tuichar_t);

typedef list_tuichar_t tuitextline;
typedef list_list_tuichar_t tuitextbuffer_t;

/* Renders to fill the container. */

typedef struct {
  tuichar_t t, b, l, r;
  tuichar_t tl, tr, bl, br;
} tuiborder_t;

struct tuiwin_t;
typedef struct tuiwin_t tuiwin_t;
LIST_DECLARE(tuiwin_t);
struct tuiwin_t {
  tuiwin_t *parent;

  int x, y;
  int width, height;

  /* Subclasses */
  char subclass;
  union /* anonymous */ {
    struct {
      list_tuiwin_t children;
    } main;

    struct {
      tuitextbuffer_t buffer;
    } text;

    struct {
      char *img_path;
    } image;

    struct {
      tuiborder_t border_chars;
    } border;

    struct {
      tuiwin_t *lchild;
      tuiwin_t *rchild;
      char separator;
    } lrsplit;

    struct {
      tuiwin_t *uchild;
      tuiwin_t *bchild;
      char separator;
    } ubsplit;
  };
};
LIST_DEFINE(tuiwin_t);

/* main window is initialized inline. */

static inline tuiwin_t *textwin_init(tuiwin_t *win, tuiwin_t *parent, int x,
                                     int y, int width, int height) {

  if ((!win) | (!parent) | (x < 0) | (y < 0) | (width < 0) | (height < 0)) {
    ERROR("Invalid arguments to textwin_init().");
  }
  win->x = x;
  win->y = y;
  win->width = width; // TODO validate
  win->height = height;
  win->parent = parent;
  win->subclass = TUIWIN_TEXTWIN;
  win->text.buffer = list_list_tuichar_t_new();
  
  return win;
}

static inline tuiwin_t *tuiborderwin_init(tuiwin_t *win, tuiwin_t *parent,
                                          tuiwin_t *child, tuiborder_t border) {
  return win;
}

#endif /* NTUI_TUIWIN_INCLUDE */
