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