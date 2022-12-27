#include "muse.h"
#include "utils.h"

/* Returns a bit at internal state position.

   State has the following structure (or bits sequence,
   f.e. 01111001010~0).

   OFF  □ - always 0
   ON   ■ - always 1
   C1/2 ■ \
   C1   ■ |
   C2   ■ | binary counter
   C4   □ |
   C8   □ /
   C3   ■ \ triple counter
   C6   □ /
   B1   ■ \
   ...  □ | shift register
   B31  □ /
*/
uint8_t muse_state(muse* machine, uint8_t position)
{
  /* shift register */
  uint8_t boundary = MUSE_BINARY_COUNTER_SIZE + MUSE_TRIPLE_COUNTER_SIZE + 2;
  if (position >= boundary)
    return sht_reg_get(&(machine->sht_reg), position - boundary);

  /* triple counter */
  boundary = MUSE_BINARY_COUNTER_SIZE + 2;
  if (position >= boundary)
    return tri_ctr_get(&(machine->tri_ctr), position - boundary);

  /* binary counter */
  boundary = 2;
  if (position >= boundary)
    return bin_ctr_get(&(machine->bin_ctr), position - boundary);

  /* on */
  if (position == 1)
    return 1;

  /* off */
  return 0;
}

/* Returns 4-bit state in the sliders positions. */
uint8_t muse_sliders_state(muse* machine,
                           enum slider s1, enum slider s2, enum slider s3, enum slider s4)
{
  uint8_t state = muse_state(machine, machine->sliders[s1]);
  state |= (muse_state(machine, machine->sliders[s2]) << 1);
  state |= (muse_state(machine, machine->sliders[s3]) << 2);
  state |= (muse_state(machine, machine->sliders[s4]) << 3);
  return state;
}

/* Initializes machine internal state. */
void muse_init(muse* machine)
{
  bin_ctr_init(&(machine->bin_ctr));
  tri_ctr_init(&(machine->tri_ctr));
  sht_reg_init(&(machine->sht_reg));
}

/* Advances machine one step forward. */
uint8_t muse_pulse(muse* machine)
{
  bin_ctr_pulse(&(machine->bin_ctr));
  // advance triple counter and shift register on the whole step
  if (!bin_ctr_get(&(machine->bin_ctr), 0))
    {
      tri_ctr_pulse(&(machine->tri_ctr));
      uint8_t theme = muse_sliders_state(machine, W, X, Y, Z);
      sht_reg_pulse(&(machine->sht_reg), four_bit_parity(theme));
    }

  uint8_t interval = muse_sliders_state(machine, A, B, C, D);
  return interval;
}

/* Changes slider position which affects the machine state. */
void muse_move_slider(muse* machine, enum slider s, uint8_t position)
{
  machine->sliders[s] = position;
}
