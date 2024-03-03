#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_10_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_10_H

#include <gtest/gtest.h>
#include <ranges>

#include "primes.h"

/*
 * Summation of Primes
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 */

std::size_t problem_10()
{
   static constexpr int max = 2E6;
   std::size_t sum = 0;

   const auto sieve = primes::sieve_of_Eratosthenes<max>();

   for(int i : std::views::iota(2, max))
   {
      if(sieve[i]) sum += i;
   }

   return sum;
}

TEST(Problem10, CorrectAnswer)
{
   EXPECT_EQ(problem_10(), 142913828922);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_10_H
