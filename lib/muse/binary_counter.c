#include "binary_counter.h"

void bin_ctr_init(binary_counter* bin_ctr)
{
  bin_ctr->storage = 1;
}

void bin_ctr_pulse(binary_counter* bin_ctr)
{
  ++(bin_ctr->storage);
}

uint8_t bin_ctr_get(binary_counter* bin_ctr, uint8_t index)
{
  return ((bin_ctr->storage) >> index) & 1;
}
