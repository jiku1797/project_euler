#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_12_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_12_H

#include <gtest/gtest.h>

#include <cstdint>
#include <cmath>
#include <optional>

#include "divisors.h"

/*
 * Highly Divisible Triangular Number
 * The sequence of triangle numbers is generated by adding the natural numbers.
 * So the 7:th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first
 * ten terms would be:
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 * Let us list the factors of the first seven triangle numbers:
 * 1: 1
 * 3: 1,3
 * 6: 1,2,3,6
 * 10: 1,2,5,10
 * 15: 1,3,5,15
 * 21: 1,3,7,21
 * 28: 1,2,4,7,14,28

 * We can see that $28$ is the first triangle number to have over five divisors.
 * What is the value of the first triangle number to have over five hundred divisors?
 */

///
/// \param upper_bound Upper bound on n, generating triangular numbers T_n
/// \return Iff successful, an optional holding the first T_n with more than 500 divisors
std::optional<uint32_t> try_with_bound(uint32_t upper_bound)
{
   static constexpr uint32_t min_num_factors = 500;

   const auto num_div_sieve
      = divisors::num_divisors_sieve<uint32_t>(upper_bound);

   for(uint32_t i = 1; i<upper_bound; ++i)
   {
      uint32_t num_divisors;

      if(i%2 == 0)
      {
         num_divisors = num_div_sieve[i / 2] * num_div_sieve[i+1];
      }
      else
      {
         num_divisors = num_div_sieve[i] * num_div_sieve[(i+1) / 2];
      }

      if(num_divisors > min_num_factors)
      {
         return std::make_optional(i * (i+1) / 2);
      }
   }

   return std::nullopt;
}

uint32_t problem_12()
{
   std::size_t upper_bound = 1 << 14;

   std::optional<uint32_t> result;
   while(!result.has_value())
   {
      result = try_with_bound(upper_bound);
      upper_bound <<= 1;
   }

   return result.value();
}

TEST(Problem12, CorrectAnswer)
{
   EXPECT_EQ(problem_12(), 76576500);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_12_H
