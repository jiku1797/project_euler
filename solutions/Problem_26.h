#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_26_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_26_H

#include <gtest/gtest.h>

/*
 * Reciprocal Cycles
 * A unit fraction contains $1$ in the numerator. The decimal representation of
 * the unit fractions with denominators $2$ to $10$ are given:
 * 1/2 = 0.5
 * 1/3 = 0.(3)
 * 1/4 = 0.25
 * 1/5 = 0.2
 * 1/6 = 0.1(6)
 * 1/7 = 0.(142857)
 * 1/8 = 0.125
 * 1/9 = 0.(1)
 * 1/10 = 0.1
 *
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be
 * seen that 1/7 has a 6-digit recurring cycle.
 * Find the value of d < 1000 for which 1/d contains the longest recurring cycle
 * in its decimal fraction part.
 */

namespace problem_26
{
using underlying_t = uint32_t;

inline underlying_t cycle_length(underlying_t n)
{
   static constexpr underlying_t not_seen_value = 0;
   std::vector seen(n, not_seen_value);

   underlying_t position = 1;
   underlying_t dividend = 1;

   while(true)
   {
      underlying_t remainder = dividend % n;

      if(remainder == 0)
      {
         return 0;
      }

      if(seen[remainder] != not_seen_value)
      {
         return position - seen[remainder];
      }

      seen[remainder] = position;
      ++position;
      dividend = remainder * 10;
   }
}

inline underlying_t problem_26()
{
   static constexpr uint32_t upper_bound = 1'000;

   underlying_t longest_cycle = 0;
   underlying_t longest_denominator = 0;

   for(underlying_t denominator = 2; denominator < upper_bound; ++denominator)
   {
      if(const auto c_length = cycle_length(denominator); c_length > longest_cycle)
      {
         longest_cycle = c_length;
         longest_denominator = denominator;
      }
   }

   return longest_denominator;
}
} // namespace problem_26

TEST(Problem26, CorrectAnswer)
{
   EXPECT_EQ(problem_26::problem_26(), 983);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_26_H
