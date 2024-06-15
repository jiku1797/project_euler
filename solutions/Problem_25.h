#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_25_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_25_H

#include <gtest/gtest.h>

#include "fibonacci.h"

/*
 * The Fibonacci sequence is defined by the recurrence relation:
 * $F_n = F_{n - 1} + F_{n - 2}, where F_1 = 1 and F_2 = 1
 * F_1 = 1
 * F_2 = 1
 * F_3 = 2
 * F_4 = 3
 * F_5 = 5
 * F_6 = 8
 * F_7 = 13
 * F_8 = 21
 * F_9 = 34
 * F_{10} = 55
 * F_{11} = 89
 * F_{12} = 144

 * The 12th term, F_{12}, is the first term to contain three digits.
 * What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
 */

namespace problem_25
{
using underlying_t = uint32_t;

underlying_t problem_25()
{
   static constexpr uint32_t num_digits = 1'000;
   underlying_t index = 1;

   while(fibonacci::num_fibo_digits(++index) < num_digits)
   {
   }

   return index;
}
}

TEST(Problem25, CorrectAnswer)
{
   EXPECT_EQ(problem_25::problem_25(), 4782);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_25_H
