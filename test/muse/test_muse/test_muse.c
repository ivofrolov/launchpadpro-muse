#include <unity.h>
#include <muse.h>

void setUp(void)
{
  // set stuff up here
}

void tearDown(void)
{
  // clean stuff up here
}

void test_muse_pulse__interval()
{
  muse machine;
  muse_init(&machine);
  muse_move_slider(&machine, A, 0); /* OFF */
  muse_move_slider(&machine, B, 1); /* ON */
  muse_move_slider(&machine, C, 2); /* C1/2 */
  muse_move_slider(&machine, D, 7); /* C3 */

  const uint8_t num_elements = 24;
  uint8_t actual[num_elements];
  for (uint8_t i = 0; i < num_elements; i++)
    actual[i] = muse_pulse(&machine);

  uint8_t expected[num_elements] =
  {
    0b0100, 0b0110, 0b0100, 0b0110, 0b0101, 0b0111,
    0b0101, 0b0111, 0b0101, 0b0111, 0b0100, 0b0110,
    0b0100, 0b0110, 0b0100, 0b0110, 0b0101, 0b0111,
    0b0101, 0b0111, 0b0101, 0b0111, 0b0100, 0b0110,
  };
  TEST_ASSERT_EQUAL_INT8_ARRAY(expected, actual, num_elements);
}

void test_muse_pulse__theme()
{
  muse machine;
  muse_init(&machine);
  muse_move_slider(&machine, A, 9);  /* B1 */
  muse_move_slider(&machine, B, 10); /* B2 */
  muse_move_slider(&machine, C, 11); /* B3 */
  muse_move_slider(&machine, D, 12); /* B4 */
  muse_move_slider(&machine, W, 1);  /* ON */
  muse_move_slider(&machine, X, 3);  /* C1 */
  muse_move_slider(&machine, Y, 7);  /* C3 */
  muse_move_slider(&machine, Z, 9);  /* B1 */

  const uint8_t num_elements = 24;
  uint8_t actual[num_elements];
  for (uint8_t i = 0; i < num_elements; i++)
    actual[i] = muse_pulse(&machine);

  uint8_t expected[num_elements] =
  {
    0b0000, 0b0000, 0b1000, 0b1000, 0b1100, 0b1100,
    0b1110, 0b1110, 0b0111, 0b0111, 0b0011, 0b0011,
    0b0001, 0b0001, 0b1000, 0b1000, 0b1100, 0b1100,
    0b1110, 0b1110, 0b0111, 0b0111, 0b0011, 0b0011,
  };
  TEST_ASSERT_EQUAL_INT8_ARRAY(expected, actual, num_elements);
}

int main( int argc, char **argv)
{
  UNITY_BEGIN();
  RUN_TEST(test_muse_pulse__interval);
  RUN_TEST(test_muse_pulse__theme);
  UNITY_END();
}
