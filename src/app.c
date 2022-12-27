#include <stdint.h>
#include <Launchpad.h>
#include <clock.h>
#include <muse.h>

clock muse_clock;
muse muse_machine;

void app_init(u16 const* adc_buffer)
{
  clock_init(&muse_clock);
  clock_set_beat_rate(&muse_clock, 12); // 1/8th notes

  muse_init(&muse_machine);
}

void app_timer_event()
{
  /* pass */
}

void app_midi_event(u8 port, u8 status, u8 d1, u8 d2)
{
  static uint8_t state = 0, prev_state = 0;
  static uint8_t beat_led = 0;
  static uint8_t tick_ctr = 0;

  switch (status)
    {
    case MIDITIMINGCLOCK:
      tick_ctr++;

      if (beat_led && tick_ctr >= 6)
        {
          beat_led = 0;
          hal_plot_led(TYPEPAD, 70, 0, beat_led, 0);
        }

      if (clock_tick(&muse_clock))
        {
          tick_ctr = 0;

          beat_led = MAXLED;
          hal_plot_led(TYPEPAD, 70, 0, beat_led, 0);

          state = muse_pulse(&muse_machine);
          if (state != prev_state)
            {
              hal_send_midi(USBMIDI, NOTEOFF, prev_state + 60, 127);
              hal_send_midi(USBMIDI, NOTEON, state + 60, 127);
              prev_state = state;
            }
        }
      break;
    case CC:
      if (d1 >= 112 && d1 <= 119)
        muse_move_slider(&muse_machine, d1 - 112, d2 < 40 ? d2 : 39);
      break;
    }
}

void app_sysex_event(u8 port, u8* data, u16 count)
{
  /* pass */
}

void app_cable_event(u8 type, u8 value)
{
  /* pass */
}

void app_surface_event(u8 type, u8 index, u8 value)
{
  /* pass */
}

void app_aftertouch_event(u8 index, u8 value)
{
  /* pass */
}
