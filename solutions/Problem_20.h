#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_20_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_20_H

#include <gtest/gtest.h>

#include <numeric>

#include "factorials.h"

/*
 * Factorial Digit Sum
 * n! means n*(n-1)*...*3*2*1.
 * For example, 10! = 10*9*8*..*3*2*1 = 3628800,
 * and the sum of the digits in the number 10! is
 * 3+6+2+8+8+0+0 = 27.
 * Find the sum of the digits in the number 100!.
 */

namespace problem_20
{
inline int problem_20()
{
   const auto digits = factorial::factorial(100);

   return std::reduce(digits.begin(), digits.end(), 0);
}
}

TEST(Problem20, CorrectAnswer)
{
   EXPECT_EQ(problem_20::problem_20(), 648);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_20_H
