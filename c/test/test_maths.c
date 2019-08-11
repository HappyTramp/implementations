/* #define UNITY_INCLUDE_DOUBLE */
/* #define UNITY_INCLUDE_FLOAT */

#include "unity.h"
#include "maths.h"

void setUp(void) {}
void tearDown(void) {}

void test_maths_factorial(void)
{
    TEST_ASSERT_EQUAL(1, maths_factorial(0));
    TEST_ASSERT_EQUAL(1, maths_factorial(1));
    TEST_ASSERT_EQUAL(2, maths_factorial(2));
    TEST_ASSERT_EQUAL(6, maths_factorial(3));
    TEST_ASSERT_EQUAL(24, maths_factorial(4));
    TEST_ASSERT_EQUAL(3628800, maths_factorial(10));
}

void test_maths_fibonacci(void)
{
    TEST_ASSERT_EQUAL(0, maths_fibonacci(0));
    TEST_ASSERT_EQUAL(1, maths_fibonacci(1));
    TEST_ASSERT_EQUAL(1, maths_fibonacci(2));
    TEST_ASSERT_EQUAL(2, maths_fibonacci(3));
    TEST_ASSERT_EQUAL(3, maths_fibonacci(4));
    TEST_ASSERT_EQUAL(5, maths_fibonacci(5));
    TEST_ASSERT_EQUAL(8, maths_fibonacci(6));
    TEST_ASSERT_EQUAL(317811, maths_fibonacci(28));
}

void test_maths_pow(void)
{
    TEST_ASSERT_EQUAL(8, maths_pow(2, 3));
    TEST_ASSERT_EQUAL(27, maths_pow(3, 3));
    TEST_ASSERT_EQUAL(1, maths_pow(0, 0));
    TEST_ASSERT_EQUAL(-125, maths_pow(-5, 3));
    TEST_IGNORE_MESSAGE("find how to include double precision");
    TEST_ASSERT_EQUAL_DOUBLE(1 / 8, maths_pow(2, -3));
}

void test_trial_division(void)
{
    TEST_ASSERT_FALSE(maths_trial_division(0));
    TEST_ASSERT_FALSE(maths_trial_division(1));
    TEST_ASSERT_TRUE(maths_trial_division(2));
    TEST_ASSERT_TRUE(maths_trial_division(3));
    TEST_ASSERT_FALSE(maths_trial_division(4));
    TEST_ASSERT_TRUE(maths_trial_division(5));
    TEST_ASSERT_TRUE(maths_trial_division(7));
    TEST_ASSERT_TRUE(maths_trial_division(41));
    TEST_ASSERT_TRUE(maths_trial_division(47));
    TEST_ASSERT_FALSE(maths_trial_division(25));
    TEST_ASSERT_TRUE(maths_trial_division(2147483647));
    TEST_ASSERT_TRUE(maths_trial_division(2147483629));
    TEST_ASSERT_FALSE(maths_trial_division(2147483617));
}

