#ifndef MUSE_TRIPLE_COUNTER_H
#define MUSE_TRIPLE_COUNTER_H

#include <stdint.h>

#define MUSE_TRIPLE_COUNTER_SIZE 2

typedef struct triple_counter triple_counter;
struct triple_counter
{
  uint8_t storage;
};

void tri_ctr_init(triple_counter* tri_ctr);

void tri_ctr_pulse(triple_counter* tri_ctr);

uint8_t tri_ctr_get(triple_counter* tri_ctr, uint8_t index);

#endif
