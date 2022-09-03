#include "tui.h"

void tmt_cb(tmt_msg_t m, struct TMT *vt, const void *r, void *p) {
  switch (m) {
  case TMT_MSG_MOVED:
    puts("MOVED");
    break;
  case TMT_MSG_UPDATE:
    puts("UPDATE");
    break;
  case TMT_MSG_ANSWER:
    puts("ANSWER");
    break;
  case TMT_MSG_BELL:
    puts("BELL");
    break;
  case TMT_MSG_CURSOR:
    puts("CURSOR");
    break;
  }
  
}

int main(void) {
  TMT *tmt = tmt_open(23, 80, tmt_cb, NULL, NULL);
  const TMTPOINT* pt = tmt_cursor(tmt);

  char chars[80] = {0};
  size_t written = (size_t)sprintf(chars, "(%zu, %zu)\n", pt->c, pt->r);
  tmt_write(tmt, chars, written);
  

  printf("(%zu, %zu)\n", pt->c, pt->r);
  tmt_close(tmt);
}

/*
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
*/
