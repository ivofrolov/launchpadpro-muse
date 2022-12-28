#include <unity.h>
#include <shift_register.h>

void setUp(void)
{
  // set stuff up here
}

void tearDown(void)
{
  // clean stuff up here
}

void test_sht_reg_get()
{
  shift_register sht_reg;
  sht_reg_init(&sht_reg);

  uint32_t actual = 0;
  sht_reg_pulse(&sht_reg, 1);
  sht_reg_pulse(&sht_reg, 0);
  sht_reg_pulse(&sht_reg, 0);
  sht_reg_pulse(&sht_reg, 0);

  for (uint32_t pos = 0; pos < 32; pos++)
    actual |= sht_reg_get(&sht_reg, pos) << pos;

  TEST_ASSERT_EQUAL_UINT32(0b0001000, actual);
}

int main( int argc, char **argv)
{
  UNITY_BEGIN();
  RUN_TEST(test_sht_reg_get);
  UNITY_END();
}
