#ifndef NTUI_INCLUDE
#define NTUI_INCLUDE

#include <ncurses.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********/
/* Macros */
/**********/

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define OOM()                                                                  \
  do {                                                                         \
    fprintf(stderr, "ntui out of memory.\n");                                  \
    exit(1);                                                                   \
  } while (0)
#define ERROR(errstr)                                                          \
  do {                                                                         \
    fprintf(stderr, "ntui error: %s.\n", errstr);                              \
    exit(1);                                                                   \
  } while (0)

/********/
/* List */
/********/

#define LIST_DECLARE(type)                                                     \
  typedef struct {                                                             \
    type *buf;                                                                 \
    size_t len;                                                                \
    size_t cap;                                                                \
  } ntuilist_##type;

#define LIST_DEFINE(type)                                                      \
  static inline ntuilist_##type ntuilist_##type##_new() {                      \
    ntuilist_##type nl;                                                        \
    nl.buf = NULL;                                                             \
    nl.len = 0;                                                                \
    nl.cap = 0;                                                                \
    return nl;                                                                 \
  }                                                                            \
  static inline void ntuilist_##type##_add(ntuilist_##type *self, type item) { \
    /* Grow */                                                                 \
    size_t prev = self->len;                                                   \
    self->len++;                                                               \
    if (self->cap <= self->len) {                                              \
      self->cap = self->len * 2;                                               \
      self->buf =                                                              \
          (type *)realloc(self->buf, sizeof(ntuilist_##type) * self->cap);     \
      if (!self->buf)                                                          \
        OOM();                                                                 \
    }                                                                          \
    /* Insert */                                                               \
    self->buf[prev] = item;                                                    \
  }                                                                            \
  static inline type ntuilist_##type##_remove(ntuilist_##type *self,           \
                                              size_t idx) {                    \
    if ((idx >= self->len) | (idx < 0))                                        \
      ERROR("ntui list index out of range.");                                  \
                                                                               \
    type ret = self->buf[idx];                                                 \
    size_t nlen = MAX(nlen - 1, 0);                                            \
    for (size_t i = idx; i < nlen; i++)                                        \
      self->buf[i] = self->buf[i + 1];                                         \
    self->len = nlen;                                                          \
    return ret;                                                                \
  }                                                                            \
  static inline void ntuilist_##type##_clear(ntuilist_##type *self) {          \
    free(self->buf);                                                           \
    *self = ntuilist_##type##_new();                                           \
  }

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
  tui->win = initscr();
  tui->root = NULL;
  return tui;
}

static inline void ntui_destroy(ntui_t *tui) {
  endwin();
}

#endif /* NTUI_INCLUDE */