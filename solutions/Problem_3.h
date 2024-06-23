#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_3_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_3_H

#include <gtest/gtest.h>

#include "primes.h"

/* The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143?
 */

inline int problem_3()
{
   static constexpr auto num = 600851475143;

   const auto upper_bound = std::lround(std::sqrt(num));

   auto largest = 1;

   auto is_divisible_by = [](int n)
   {
      return num % n == 0;
   };

   for(int i = 2; i < upper_bound; ++i)
   {
      if(is_divisible_by(i) && primes::is_prime(i))
      {
         largest = i;
      }
   }
   return largest;
}

TEST(Problem3, CorrectAnswer)
{
   EXPECT_EQ(problem_3(), 6857);
}
#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_3_H
