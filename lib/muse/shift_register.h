#ifndef MUSE_SHIFT_REGISTER_H
#define MUSE_SHIFT_REGISTER_H

#include <stdint.h>

#define MUSE_SHIFT_REGISTER_SIZE 31

typedef struct shift_register shift_register;
struct shift_register
{
  uint32_t storage;
};

void sht_reg_init(shift_register* sht_reg);

void sht_reg_pulse(shift_register* sht_reg, uint8_t state);

uint8_t sht_reg_get(shift_register* sht_reg, uint8_t index);

#endif
