#ifndef MUSE_BINARY_COUNTER_H
#define MUSE_BINARY_COUNTER_H

#include <stdint.h>

#define MUSE_BINARY_COUNTER_SIZE 5

typedef struct binary_counter binary_counter;
struct binary_counter
{
  uint8_t storage;
};

void bin_ctr_init(binary_counter* bin_ctr);

void bin_ctr_pulse(binary_counter* bin_ctr);

uint8_t bin_ctr_get(binary_counter* bin_ctr, uint8_t index);

#endif
