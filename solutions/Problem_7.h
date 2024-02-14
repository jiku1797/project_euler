#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_7_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_7_H

#include <gtest/gtest.h>

#include "primes.h"

/*
 * 10001st Prime
 * By listing the first six prime numbers:
 * 2, 3, 5, 7, 11 and 13, we can see that the
 * 6th prime is 13.
 *
 * What is the 10001 prime number?
 */

int problem_7()
{
   int num = 1;
   int count = 0;
   while(count < 10001)
   {
      ++num;
      if(primes::is_prime(num))
      {
         ++count;
      }
   }
   return num;
}

TEST(Problem7, CorrectAnswer)
{
   EXPECT_EQ(problem_7(), 104743);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_7_H
