#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>

#define MIDI_CLOCK_RATE 24  // pulses per quarter note

typedef struct clock clock;
struct clock
{
  uint8_t beat_rate;
  uint8_t counter;
};

void clock_init(clock* clk);

void clock_set_beat_rate(clock* clk, uint8_t beat_rate);

uint8_t clock_tick(clock* clk);

#endif
