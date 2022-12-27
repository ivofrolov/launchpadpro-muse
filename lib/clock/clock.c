#include "clock.h"

void clock_init(clock* clk)
{
  clk->beat_rate = MIDI_CLOCK_RATE;
  clk->counter = 0;
}

void clock_set_beat_rate(clock* clk, uint8_t beat_rate)
{
  clk->beat_rate = beat_rate;
}

uint8_t clock_tick(clock* clk)
{
  if ((clk->counter)++ == 0)
    return 1;

  if (clk->counter == clk->beat_rate)
    clk->counter = 0;

  return 0;
}
