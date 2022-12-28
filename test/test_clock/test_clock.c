#include <unity.h>
#include <clock.h>

void setUp(void)
{
  // set stuff up here
}

void tearDown(void)
{
  // clean stuff up here
}

void test_clock_tick()
{
  clock clk;
  clock_init(&clk);
  clock_set_beat_rate(&clk, 2);
  TEST_ASSERT_EQUAL_INT8(1, clock_tick(&clk));
  TEST_ASSERT_EQUAL_INT8(0, clock_tick(&clk));
  TEST_ASSERT_EQUAL_INT8(1, clock_tick(&clk));
  TEST_ASSERT_EQUAL_INT8(0, clock_tick(&clk));
}

void test_clock_tick__beat_rate_is_one__beat_every_tick()
{
  clock clk;
  clock_init(&clk);
  clock_set_beat_rate(&clk, 1);
  TEST_ASSERT_EQUAL_INT8(1, clock_tick(&clk));
  TEST_ASSERT_EQUAL_INT8(1, clock_tick(&clk));
  TEST_ASSERT_EQUAL_INT8(1, clock_tick(&clk));
  TEST_ASSERT_EQUAL_INT8(1, clock_tick(&clk));
}

void test_clock_tick__beat_rate_is_zero__clock_is_off()
{
  clock clk;
  clock_init(&clk);
  clock_set_beat_rate(&clk, 0);
  TEST_ASSERT_EQUAL_INT8(0, clock_tick(&clk));
  TEST_ASSERT_EQUAL_INT8(0, clock_tick(&clk));
  TEST_ASSERT_EQUAL_INT8(0, clock_tick(&clk));
  TEST_ASSERT_EQUAL_INT8(0, clock_tick(&clk));
}

int main( int argc, char **argv)
{
  UNITY_BEGIN();
  RUN_TEST(test_clock_tick);
  RUN_TEST(test_clock_tick__beat_rate_is_one__beat_every_tick);
  RUN_TEST(test_clock_tick__beat_rate_is_zero__clock_is_off);
  UNITY_END();
}
