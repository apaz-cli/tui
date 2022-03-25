#include "ntui.h"

int main(void) {
  ntui_t ntui;
  ntui_init(&ntui);

  int c, count=0;
  MEVENT mouse_event;
  while ((c = getch())) {
    if (c == KEY_MOUSE) {
      if (getmouse(&mouse_event) == ERR)
        ERROR("Failed to recieve mouse event.");

      wclear(stdscr);
      wprintw(ntui.win, "Recieved mouse event: (x: %i, y: %i, button: %i).",
              mouse_event.x, mouse_event.y, (int)mouse_event.bstate);
    } else {
        wclear(stdscr);
      wprintw(ntui.win, "Recieved keystroke: %c", c);
    }
    mvprintw(1, 0, "Event number: %4d", count++);
  }

  ntui_destroy(&ntui);
}
