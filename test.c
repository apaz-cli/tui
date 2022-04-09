#define NTUI_BACKEND_CURSES
#include "ntui.h"

int main(void) {
  ntui_init();

  int c, count = 0;
  MEVENT mouse_event;
  while ((c = getch())) {
    if (c == KEY_MOUSE) {
      if (getmouse(&mouse_event) == ERR)
        ERROR("Failed to recieve mouse event.");

      wclear(stdscr);
      wprintw(ntui.curses_window,
              "Recieved mouse event: (x: %i, y: %i, button: %i).",
              mouse_event.x, mouse_event.y, (int)mouse_event.bstate);

    } else if (c == KEY_RESIZE) {
      wclear(stdscr);
      wprintw(ntui.curses_window, "Window resized to: (%i, %i).", LINES, COLS);
      ntui_render();
    } else {
      wclear(stdscr);
      wprintw(ntui.curses_window, "Recieved keystroke: %c", c);
    }
    mvprintw(1, 0, "Event number: %4d", count++);
  }

  ntui_destroy();
}
