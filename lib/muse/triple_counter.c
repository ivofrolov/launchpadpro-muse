#include "triple_counter.h"

void tri_ctr_init(triple_counter* tri_ctr)
{
  tri_ctr->storage = 0;
}

void tri_ctr_pulse(triple_counter* tri_ctr)
{
  ++(tri_ctr->storage);

  if (tri_ctr->storage == MUSE_TRIPLE_COUNTER_SIZE * 3 * 2)
    tri_ctr->storage = 0;
}

uint8_t tri_ctr_get(triple_counter* tri_ctr, uint8_t index)
{
  return (tri_ctr->storage / (3 * (index + 1))) & 1;
}
