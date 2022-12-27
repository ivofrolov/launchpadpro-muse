#include <stdlib.h>
#include <Launchpad.h>
#include "ui.h"

uint8_t pad_to_control(struct ui_region const frame[], uint8_t frame_sz,
                       uint8_t index, uint8_t value, uint8_t* ctrl, uint8_t* offset)
{
  div_t idx_div = div(index, 10);

  for (uint8_t n = 0; n < frame_sz; ++n)
    {
      div_t i_div = div(frame[n].i, 10);
      div_t j_div = div(frame[n].j, 10);

      if ((idx_div.rem < i_div.rem) || (idx_div.rem > j_div.rem))
        continue;
      if ((idx_div.quot < i_div.quot) || (idx_div.quot > j_div.quot))
        continue;

      uint8_t base = j_div.rem - i_div.rem + 1;

      *offset = (idx_div.rem - i_div.rem) + base * (idx_div.quot - i_div.quot);
      *ctrl = n;

      return 1;
    }

  return 0;
}

uint8_t control_to_pad(struct ui_region const frame[], uint8_t ctrl,
                       uint8_t offset)
{
  div_t i_div = div(frame[ctrl].i, 10);
  div_t j_div = div(frame[ctrl].j, 10);

  uint8_t base = j_div.rem - i_div.rem + 1;
  div_t ofs_div = div(offset, base);

  return ofs_div.rem + i_div.rem + 10 * (ofs_div.quot + i_div.quot);
}

void ui_process_page(muse_ui* ui, uint8_t offset, uint8_t value)
{
  if (!value)
    return;

  hal_plot_led(TYPEPAD, control_to_pad(ui->frame, PAGE, 4 - ui->page), 0, 0, 0);

  ui->page = 4 - offset;
  hal_plot_led(TYPEPAD, control_to_pad(ui->frame, PAGE, offset), 0, MAXLED, 0);
}

void ui_process_slider(muse_ui* ui, uint8_t offset, uint8_t value)
{
  if (!value)
    return;

  uint8_t slider = offset % 8;

  uint8_t prev_offset = (7 - ui->sliders[slider]) * 8 + slider;
  hal_plot_led(TYPEPAD, control_to_pad(ui->frame, MULTISLIDER, prev_offset), 0,
               0,
               0);

  ui->sliders[slider] = 7 - offset / 8;

  hal_plot_led(TYPEPAD, control_to_pad(ui->frame, MULTISLIDER, offset), 0,
               MAXLED,
               0);
}

void ui_process_pad(muse* machine, muse_ui* ui, uint8_t index, uint8_t value)
{
  uint8_t ctrl;
  uint8_t offset;

  if (!pad_to_control(ui->frame, ui->frame_sz, index, value, &ctrl, &offset))
    return;

  switch (ctrl)
    {
    case PAGE:
      ui_process_page(ui, offset, value);
      break;
    case MULTISLIDER:
      ui_process_slider(ui, offset, value);
      for (uint8_t s = 0; s < 8; ++s)
        {
          muse_move_slider(machine, s, ui->sliders[s]);
        }
      break;
    }
}

void ui_init(muse_ui* ui)
{
  ui->frame = ui_main_frame;
  ui->frame_sz = sizeof ui_main_frame / sizeof *ui_main_frame;
}
