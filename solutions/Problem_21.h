#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_21_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_21_H

#include <gtest/gtest.h>

#include <set>
#include <numeric>

#include "divisors.h"

/*
 * Amicable Numbers
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which
 * divide evenly into n).
 * If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and
 * b are called amicable numbers.
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110;
 * therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 * Evaluate the sum of all the amicable numbers under 10000.
 */

namespace problem_21
{
using underlying_t = std::uint32_t;

std::set<underlying_t> get_amicable_pairs(underlying_t upper_bound)
{
   std::set<unsigned int> amicable_pairs;

   for (underlying_t i = 2; i <= upper_bound; ++i)
   {
      const auto sibling = divisors::sum_of_divisors(i);

      // found a pair ?
      if (i == divisors::sum_of_divisors(sibling) && i != sibling)
      {
         amicable_pairs.insert(i);
         amicable_pairs.insert(sibling);
      }
   }

   return amicable_pairs;
}

underlying_t problem_21()
{
   static constexpr underlying_t upper_bound = 10'000;
   const auto amicable_pairs = get_amicable_pairs(upper_bound);

   return std::reduce(std::begin(amicable_pairs), std::end(amicable_pairs));
}
}

TEST(Problem21, CorrectAnswer)
{
   EXPECT_EQ(problem_21::problem_21(), 31626);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_21_H
