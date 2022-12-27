#include <unity.h>
#include <utils.h>

void setUp(void)
{
  // set stuff up here
}

void tearDown(void)
{
  // clean stuff up here
}

void test_four_bit_parity()
{
  TEST_ASSERT_EQUAL(1, four_bit_parity(0));
  TEST_ASSERT_EQUAL(0, four_bit_parity(1));
  TEST_ASSERT_EQUAL(0, four_bit_parity(2));
  TEST_ASSERT_EQUAL(1, four_bit_parity(3));
  TEST_ASSERT_EQUAL(0, four_bit_parity(4));
  TEST_ASSERT_EQUAL(1, four_bit_parity(5));
  TEST_ASSERT_EQUAL(1, four_bit_parity(6));
  TEST_ASSERT_EQUAL(0, four_bit_parity(7));
  TEST_ASSERT_EQUAL(0, four_bit_parity(8));
  TEST_ASSERT_EQUAL(1, four_bit_parity(9));
  TEST_ASSERT_EQUAL(1, four_bit_parity(10));
  TEST_ASSERT_EQUAL(0, four_bit_parity(11));
  TEST_ASSERT_EQUAL(1, four_bit_parity(12));
  TEST_ASSERT_EQUAL(0, four_bit_parity(13));
  TEST_ASSERT_EQUAL(0, four_bit_parity(14));
  TEST_ASSERT_EQUAL(1, four_bit_parity(15));
  // more than 4 bits input
  TEST_ASSERT_EQUAL(1, four_bit_parity(16));
  TEST_ASSERT_EQUAL(0, four_bit_parity(17));
  TEST_ASSERT_EQUAL(0, four_bit_parity(18));
  TEST_ASSERT_EQUAL(1, four_bit_parity(19));
}

int main( int argc, char **argv)
{
  UNITY_BEGIN();
  RUN_TEST(test_four_bit_parity);
  UNITY_END();
}
