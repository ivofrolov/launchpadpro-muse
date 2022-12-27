#ifndef MUSE_H
#define MUSE_H

#include <stdint.h>
#include "binary_counter.h"
#include "triple_counter.h"
#include "shift_register.h"

#define MUSE_SLIDER_LENGTH 40

enum slider
{
  A, B, C, D, W, X, Y, Z
};

typedef struct muse muse;
struct muse
{
  uint8_t sliders[8];
  binary_counter bin_ctr;
  triple_counter tri_ctr;
  shift_register sht_reg;
};

void muse_init(muse* machine);

uint8_t muse_pulse(muse* machine);

void muse_move_slider(muse* machine, enum slider s, uint8_t position);

#endif
