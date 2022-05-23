#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#define with ";"
#define plain "0" /* or "" */
#define no "2"
#define bright "1"
#define dim "2"
#define italic "3"
#define underline "4"
#define reverse "7"

#define fg "3"
#define bg "4"
#define br_fg "9"
#define br_bg "10"
#define black "0"
#define red "1"
#define green "2"
#define yellow "3"
#define blue "4"
#define magenta "5"
#define cyan "6"
#define white "7"

#define alt_buf "?1049"
#define curs "?25"
#define term_clear "2J"
#define clear_line "2K"
#define high "h"
#define low "l"
#define jump "H"

#define esc "\x1b"
#define esca esc "["
#define wfg "38;5;"
#define wbg "48;5;"
#define color "m"
#define fmt(f) esca f "m"

#define say(s) write(1, s, sizeof(s))
#define sz(s) (sizeof(s) / sizeof(*s))

struct termios initial;
uint16_t width, height;

uint8_t meter_value = 0;
uint8_t meter_size = 25;
uint8_t meter_color_on = 219;
uint8_t meter_color_off = 162;
bool help_visible = true;

const char *instructions[] = {
    "press " fmt(reverse with bright) " i " fmt(plain) " to " fmt(
        underline with fg cyan) "increase the meter value" fmt(plain),
    "press " fmt(reverse with bright) " b " fmt(plain) " to " fmt(
        underline with fg red) "increase the length of the meter" fmt(plain),
    "press " fmt(reverse with bright) " d " fmt(plain) " to " fmt(
        underline with fg yellow) "decrease the meter value" fmt(plain),
    "press " fmt(reverse with bright) " s " fmt(plain) " to " fmt(
        underline with fg green) "decrease the length of the meter" fmt(plain),
    "press " fmt(reverse with bright) " c " fmt(plain) " to " fmt(
        underline with fg blue) "change the filled color" fmt(plain),
    "press " fmt(reverse with bright) " r " fmt(plain) " to " fmt(
        underline with br_fg red) "change the unfilled color" fmt(plain),
    "",
    "press " fmt(reverse with bright) " h " fmt(plain) " to " fmt(
        underline with fg magenta) "toggle this text" fmt(plain),
    "press " fmt(reverse with bright) "ESC" fmt(plain) " to " fmt(
        underline with br_fg cyan) "quit" fmt(plain)};

size_t textsz(const char *str) {
  // returns size of string without formatting characters
  size_t sz = 0, i = 0;

count:
  if (str[i] == 0)
    return sz;
  else if (str[i] == '\x1b')
    goto skip;
  else {
    ++i;
    ++sz;
    goto count;
  }

skip:
  if (str[i] != 'm') {
    ++i;
    goto skip;
  } else
    goto count;
};

void restore(void) {
  say(
      // enter alternate buffer if we haven't already
      esca alt_buf high

          // clean up the buffer
          esca term_clear

              // show the cursor
              esca curs high

                  // return to the main buffer
                  esca alt_buf low);

  // restore original termios params
  tcsetattr(1, TCSANOW, &initial);
}
void restore_die(int i) {
  exit(1);
  // since atexit has already registered a handler,
  // a call to exit(3) is all we actually need
}

void repaint(void);

void resize(int i) {
  struct winsize ws;
  ioctl(1, TIOCGWINSZ, &ws);
  width = ws.ws_col;
  height = ws.ws_row;
  say(esca term_clear);
  repaint();
}

void initterm(void) {
  // since we're using printf here, which doesn't play nicely
  // with non-canonical mode, we need to turn off buffering.
  setvbuf(stdout, NULL, _IONBF, 0);

termios : {
  struct termios t;
  tcgetattr(1, &t);
  initial = t;
  t.c_lflag &= (~ECHO & ~ICANON);
  tcsetattr(1, TCSANOW, &t);
};

  atexit(restore);
  signal(SIGTERM, restore_die);
  signal(SIGINT, restore_die);

  say(esca alt_buf high esca term_clear esca curs low);
}

void repaint(void) {
  const uint16_t mx = (width / 2) - (meter_size / 2), my = (height / 2) + 1;

  if (help_visible)
    for (size_t i = 0; i < sz(instructions); ++i)
      printf(esca "%lu" with "%lu" jump fmt(plain) "%s",
             // place lines above meter
             my - (1 + (sz(instructions) - i)),
             // center each line
             (width / 2) - (textsz(instructions[i]) / 2),
             // print line
             instructions[i]);

  printf(esca "%u" with "%u" jump, my, mx);
  say(esca clear_line);

  for (size_t i = 0; i < meter_size; ++i)
    printf(esca wfg "%u" color "%s",
           i < meter_value ? meter_color_on : meter_color_off,
           i < meter_value ? "█" : "░");
}

int main() {
  initterm();
  signal(SIGWINCH, resize);
  resize(0);
  bool dirty = true;
  for (char inkey; inkey != '\x1b';) {
    if (dirty) {
      repaint();
      dirty = false;
    }
    read(1, &inkey, 1);
    switch (inkey) {
    case 'i': // increase meter value
      ++meter_value;
      break;
    case 'd': // decrease meter value
      --meter_value;
      break;
    case 'b': // increase meter size
      ++meter_size;
      break;
    case 's': // decrease meter size
      --meter_size;
      break;
    case 'c': // randomize meter on color
      meter_color_on = rand();
      break;
    case 'r': // randomize meter off color
      meter_color_off = rand();
      break;
    case 'h': // toggle help text
      help_visible = !help_visible;
      say(esca term_clear);
      break;
    default:
      goto end;
    }
    dirty = true;
  end:;
  }
}