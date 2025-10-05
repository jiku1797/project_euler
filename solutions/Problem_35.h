#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_35_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_35_H

#include "primes.h"

#include <cstdint>

#include <gtest/gtest.h>

/*
* Circular Primes
*
* The number, 197, is called a circular prime because all rotations of the digits: 197,
* 971, and 719, are themselves prime.
* There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
* How many circular primes are there below one million?
*/

/*
 * SOLUTION
 *
 */

namespace problem_35
{
using underlying_t = std::uint32_t;

inline underlying_t problem_35()
{
   static constexpr underlying_t limit = 1'000'000;

   const auto primes = primes::primes(limit);

   underlying_t count = 0;

   for (const auto& prime : primes)
   {
      underlying_t shift = 1;
      while(prime > 10 * shift)
      {
         shift *= 10;
      }

      auto rotated = prime;

      do
      {
         const auto digit = rotated % 10;
         rotated /= 10;
         rotated += digit * shift;

         if(!primes.contains(rotated)) break;
      }while(rotated != prime);

      if(rotated == prime) ++count;
   }

   return count;
}
}

TEST(Problem35, CorrectAnswer)
{
   EXPECT_EQ(problem_35::problem_35(), 55);
}

#endif // PROJECT_EULER_SOLUTIONS_PROBLEM_35_H

