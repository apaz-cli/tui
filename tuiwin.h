#ifndef NTUI_TUIWIN_INCLUDE
#define NTUI_TUIWIN_INCLUDE

#include "list.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TUIWIN_TEXTWIN 1
#define TUIWIN_IMAGEWIN 2
#define TUIWIN_BORDERWIN 3

typedef struct {

} tuitextbuffer_t

struct tuiwin_t;
typedef struct tuiwin_t tuiwin_t;
LIST_DECLARE(tuiwin_t);
struct tuiwin_t {
  tuiwin_t *parent;

  int x, y;
  int width, height;

  /* Subclasses */
  char type;
  union /* anonymous */ {
    struct {
      tuitextbuffer_t buffer;
    } text;

    struct {
      char* img_path;
    } image;

    struct {
      tuiborder_t border_chars;
    } border;

    struct {
      tuiwin_t* lchild;
      tuiwin_t* rchild;
      char separator;
    } lrsplit;

    struct {
      tuiwin_t* uchild;
      tuiwin_t* bchild;
      char separator;
    } ubsplit;
  };
};
LIST_DEFINE(tuiwin_t);

typedef struct {
  int t, b, l, r;
  int tl, tr, bl, br;
} tuiborder_t;

static inline tuiwin_t *tuiwin_init(tuiwin_t *win, tuiwin_t *parent, int x,
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

static inline tuiwin_t *tuiborderwin_init(tuiwin_t *win, tuiwin_t *parent,
                                            tuiwin_t *child,
                                            ntui_border_t border) {
  return win;
}

#endif /* NTUI_TUIWIN_INCLUDE */
