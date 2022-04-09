#ifndef NTUI_INCLUDE
#define NTUI_INCLUDE

#define NTUI_BACKEND_CURSES 1 // TODO Remove this

#ifndef NTUI_BACKEND_CURSES
#define NTUI_BACKEND_CURSES 0
#else
#undef NTUI_BACKEND_CURSES
#define NTUI_BACKEND_CURSES 1
#endif

#ifndef NTUI_BACKEND_WAYLAND
#define NTUI_BACKEND_WAYLAND 0
#else
#undef NTUI_BACKEND_WAYLAND
#define NTUI_BACKEND_WAYLAND 1
#endif

_Static_assert(
    (NTUI_BACKEND_CURSES | NTUI_BACKEND_WAYLAND),
    "A backend is required for ntui. Supports either wayland or ncurses.");

_Static_assert(!(NTUI_BACKEND_CURSES & NTUI_BACKEND_WAYLAND),
               "Cannot enable both the ntui curses and wayland backends at the "
               "same time.");

static inline void ntui_init(void);
static inline void ntui_render(void);
static inline void ntui_input_loop(void);
static inline void ntui_destroy(void);

#if NTUI_BACKEND_CURSES
#include "ntui_curses.h"
#else
#include "ntui_wayland.h"
#endif

#endif /* NTUI_INCLUDE */