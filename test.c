#include "ntui.h"

int main(void) {

    ntui_t ntui;
    ntui_init(&ntui);

  tuiwin_t twin;
  memset(&twin, 0, sizeof(tuiwin_t));

  ntuilist_tuiwin_t winlist = ntuilist_tuiwin_t_new();
  ntuilist_tuiwin_t_add(&winlist, twin);

  tuiwin_t nt = ntuilist_tuiwin_t_remove(&winlist, 0);

  ntuilist_tuiwin_t_clear(&winlist);

  ntui_destroy(&ntui);
}
