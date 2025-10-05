#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_34_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_34_H

#include <ranges>

#include "factorials.h"

#include <gtest/gtest.h>

/*
* Digit Factorials
*
* 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
* Find the sum of all numbers which are equal to the sum of the factorial of their digits.
* Note: As 1! = 1 and 2! = 2 are not sums they are not included.
*/

/*
 * SOLUTION
 * Assume a_{N-1}*10^{N-1} + ... + a_0 = a_{N-1}! + ... + a_0!.
 * Then LHS >= 10^{N-1} and RHS <= 9!*N. For N>=7 the LHS will be
 * strictly larger than the RHS. Thus we can limit ourselves to
 * N < 7 (7-digit numbers and below).
 */

namespace problem_34
{
using underlying_t = std::uint32_t;

inline underlying_t problem_34()
{
   static const underlying_t upper_limit = 7 * factorial::factorials<underlying_t>[9];
   static constexpr underlying_t lower_limit = 10;

   namespace sr = std::ranges;
   namespace sv = std::views;

   return sr::fold_left(
      sv::iota(lower_limit, upper_limit + 1)
         |  sv::filter([](auto n)
            {
               auto original = n;
               underlying_t sum = 0;
               while (n > 0)
               {
                  sum += factorial::factorials<underlying_t>[n % 10];
                  n /= 10;
               }
               return sum == original;
            }
         )
      , 0
      , std::plus<>{}
   );
}
}

TEST(Problem34, CorrectAnswer)
{
   EXPECT_EQ(problem_34::problem_34(), 40730);
}

#endif // PROJECT_EULER_SOLUTIONS_PROBLEM_34_H
