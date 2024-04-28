#include "gtest/gtest.h"

#include "../utils/divisors.h"

using namespace divisors;

TEST(TestNumDivisors, Basic)
{
   const auto num_div = num_divisors_sieve<int>(12);

   EXPECT_EQ(num_div[1], 1);
   EXPECT_EQ(num_div[2], 2);
   EXPECT_EQ(num_div[3], 2);
   EXPECT_EQ(num_div[4], 3);
   EXPECT_EQ(num_div[5], 2);
   EXPECT_EQ(num_div[6], 4);
   EXPECT_EQ(num_div[7], 2);
   EXPECT_EQ(num_div[8], 4);
   EXPECT_EQ(num_div[9], 3);
   EXPECT_EQ(num_div[10], 4);
   EXPECT_EQ(num_div[11], 2);
   EXPECT_EQ(num_div[12], 6);
}

TEST(TestSumOfDivisors, Basic)
{
   EXPECT_EQ(sum_of_divisors(2), 1);
   EXPECT_EQ(sum_of_divisors(3), 1); // 1
   EXPECT_EQ(sum_of_divisors(4), 3); // 1 + 2
   EXPECT_EQ(sum_of_divisors(5), 1); // 1
   EXPECT_EQ(sum_of_divisors(6), 6); // 1 + 2 + 3
   EXPECT_EQ(sum_of_divisors(12), 16); // 1 + 2 + 3 + 4 + 6
}