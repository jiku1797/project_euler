#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_6_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_6_H

#include <gtest/gtest.h>

/*
 * Sum Square Difference
 * The sum of the squares of the first ten natural numbers is,
 * 1^2 + ... + 10^2 = 385.
 * The square of the sum of the first ten natural numbers is,
 * (1 + ... + 10)^2 = 55^2 = 3025.
 * Hence the difference between the sum of the squares of the first
 * ten natural numbers and the square of the sum is 3025 - 385 = 2640.
 * Find the difference between the sum of the squares of the first one
 * hundred natural numbers and the square of the sum.
 */


/// Let A_N = (1 + ... + N)^2 and B_N = 1^2 + ... + N^2.
/// It is not hard to see that
/// A_N - B_N = A_{N-1} - B_{N-1} + N^2 * (N-1),
/// i.e. we get the recursive formula
/// C_N = C_{N-1} + N^2 * (N-1), with C_1 = 0,
/// for the difference where C_100 denotes the solution.
int problem_6()
{
   int current = 0;
   for(int i = 2; i<=100; ++i)
   {
      current = current + i * i * (i - 1);
   }
   return current;
}

TEST(Problem6, CorrectAnswer)
{
   EXPECT_EQ(problem_6(), 25164150);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_6_H
