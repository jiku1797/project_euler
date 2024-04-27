#include "gtest/gtest.h"

#include "../utils/factorials.h"

using namespace factorial;

TEST(TestFactorials, TestNumDigits)
{
   EXPECT_EQ(1, num_factorial_digits(2));
   EXPECT_EQ(1, num_factorial_digits(3));
   EXPECT_EQ(2, num_factorial_digits(4));
   EXPECT_EQ(3, num_factorial_digits(5));
   EXPECT_EQ(3, num_factorial_digits(6));
   EXPECT_EQ(4, num_factorial_digits(7));
}

TEST(TestFactorials, TestFactorialDigits)
{
   Digits expected = {2};
   EXPECT_EQ(expected, factorial::factorial(2));

   expected = {6};
   EXPECT_EQ(expected, factorial::factorial(3));

   expected = {4, 2};
   EXPECT_EQ(expected, factorial::factorial(4));

   expected = {0, 2, 1};
   EXPECT_EQ(expected, factorial::factorial(5));

   expected = {0, 2, 7};
   EXPECT_EQ(expected, factorial::factorial(6));

   expected = {0, 0, 8, 8, 2, 6, 3};
   EXPECT_EQ(expected, factorial::factorial(10));
}
