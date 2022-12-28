#include "shift_register.h"

void sht_reg_init(shift_register* sht_reg)
{
  sht_reg->storage = 0;
}

void sht_reg_pulse(shift_register* sht_reg, uint8_t feed)
{
  sht_reg->storage = ((sht_reg->storage) << 1) | (feed & 1);
}

uint8_t sht_reg_get(shift_register* sht_reg, uint8_t index)
{
  return ((sht_reg->storage) >> index) & 1;
}
