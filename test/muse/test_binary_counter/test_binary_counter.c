#include <unity.h>
#include <binary_counter.h>

void setUp(void)
{
  // set stuff up here
}

void tearDown(void)
{
  // clean stuff up here
}

void test_bin_ctr_get()
{
  binary_counter bin_ctr;
  bin_ctr_init(&bin_ctr);

  const uint8_t num_elements = 33;
  uint8_t actual[num_elements];
  for (uint8_t i = 0; i < num_elements; ++i)
    {
      uint8_t curr = 0;
      for (uint8_t pos = 0; pos < 5; ++pos)
        curr |= bin_ctr_get(&bin_ctr, pos) << pos;
      actual[i] = curr;
      bin_ctr_pulse(&bin_ctr);
    }

  uint8_t expected[num_elements] =
  {
    0b00001,
    0b00010,
    0b00011,
    0b00100,
    0b00101,
    0b00110,
    0b00111,
    0b01000,
    0b01001,
    0b01010,
    0b01011,
    0b01100,
    0b01101,
    0b01110,
    0b01111,
    0b10000,
    0b10001,
    0b10010,
    0b10011,
    0b10100,
    0b10101,
    0b10110,
    0b10111,
    0b11000,
    0b11001,
    0b11010,
    0b11011,
    0b11100,
    0b11101,
    0b11110,
    0b11111,
    0b00000,
    0b00001,
  };
  TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, actual, num_elements);
}

int main( int argc, char **argv)
{
  UNITY_BEGIN();
  RUN_TEST(test_bin_ctr_get);
  UNITY_END();
}
