#include <unity.h>
#include <triple_counter.h>

void setUp(void)
{
  // set stuff up here
}

void tearDown(void)
{
  // clean stuff up here
}

void test_tri_ctr_get()
{
  triple_counter tri_ctr;
  tri_ctr_init(&tri_ctr);

  const uint8_t num_elements = 13;
  uint8_t actual[num_elements];
  for (uint8_t i = 0; i < num_elements; ++i)
    {
      actual[i] = (tri_ctr_get(&tri_ctr, 1) << 1) | tri_ctr_get(&tri_ctr, 0);
      tri_ctr_pulse(&tri_ctr);
    }

  uint8_t expected[num_elements] =
  {
    0b00,
    0b00,
    0b00,
    0b01,
    0b01,
    0b01,
    0b10,
    0b10,
    0b10,
    0b11,
    0b11,
    0b11,
    0b00,
  };
  TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, actual, num_elements);
}

int main( int argc, char **argv)
{
  UNITY_BEGIN();
  RUN_TEST(test_tri_ctr_get);
  UNITY_END();
}
