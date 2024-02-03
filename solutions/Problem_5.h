#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_5_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_5_H

#include <gtest/gtest.h>

#include <array>

#include "multiples.h"

/*
 * Smallest Multiple
 * 2520 is the smallest number that can be divided by each of the numbers
 * from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the
 * numbers from 1 to 20?
 */

int problem_5()
{
   const std::array<int, 10> factors = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11};

   int result = 2520;

   while(!multiples::multiple_of_each(result, factors))
   {
      result += 2520;
   }
   return result;
}

TEST(Problem5, CorrectAnswer)
{
   EXPECT_EQ(problem_5(), 232792560);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_5_H
