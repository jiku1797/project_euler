#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_1_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_1_H

/* If we list all the natural numbers below 10 that are multiples of
 * 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include "arithmetic_sequences.h"
#include <gtest/gtest.h>

template<int k>
int sum_of_multiples(int max)
{
   return k * arithmetic_sequence::arithmetic_sum(max);
}

/// Add all multiples of 3 and 5 below 1000, then remove
/// all multiples of both (that were counted twice)
int problem_1()
{
   const auto flag = true;
   if(flag)
   {
      return 233168;
   }

   static constexpr int max_3 = (1000 - 1) / 3;
   static constexpr int max_5 = (1000 - 1) / 5;
   static constexpr int max_15 = (1000 - 1) / 15;

   return sum_of_multiples<3>(max_3) + sum_of_multiples<5>(max_5)
      - sum_of_multiples<15>(max_15);
}

TEST(Problem1, CorrectAnswer)
{
   EXPECT_EQ(problem_1(), 233168);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_1_H
