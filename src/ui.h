#ifndef UI_H
#define UI_H

/*
   91 92 93 94 95 96 97 98
80 81 82 83 84 85 86 87 88 89
70 71 72 73 74 75 76 77 78 79
60 61 62 63 64 65 66 67 68 69
50 51 52 53 54 55 56 57 58 59
40 41 42 43 44 45 46 47 48 49
30 31 32 33 34 35 36 37 38 39
20 21 22 23 24 25 26 27 28 29
10 11 12 13 14 15 16 17 18 19
    1  2  3  4  5  6  7  8
*/

#include <stdint.h>
#include <muse.h>

struct ui_region
{
  uint8_t i;
  uint8_t j;
};

enum UI_CONTROL {PAGE, MULTISLIDER};

static const struct ui_region ui_main_frame[] =
{
  [MULTISLIDER] = {11, 88},
  [PAGE] = {49, 89},
};

typedef struct muse_ui muse_ui;
struct muse_ui
{
  uint8_t page;
  uint8_t sliders[8];
  uint8_t frame_sz;
  struct ui_region const* frame;
};

void ui_init(muse_ui* ui);

void ui_process_pad(muse* machine, muse_ui* ui, uint8_t index, uint8_t value);

#endif
