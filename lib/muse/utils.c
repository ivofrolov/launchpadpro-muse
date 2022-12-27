#include "utils.h"

/* Returns 0 if number of ones in 4 least significant bits is even. */
uint8_t four_bit_parity(uint8_t x)
{
  uint8_t y = 1 ^ x;
  y ^= (x >> 1);
  y ^= (x >> 2);
  y ^= (x >> 3);
  return y & 1;
}
