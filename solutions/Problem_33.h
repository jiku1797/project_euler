#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_33_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_33_H

#include <ranges>
#include <numeric>

#include <gtest/gtest.h>

/*
* Digit Cancelling Fractions
*
* The fraction 49/98 is a curious fraction, as an inexperienced mathematician in
* attempting to simplify it may incorrectly believe that $49/98 = 4/8$, which is
* correct, is obtained by cancelling the 9s.
* We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
* There are exactly four non-trivial examples of this type of fraction, less than one
* in value, and containing two digits in the numerator and denominator.
* If the product of these four fractions is given in its lowest common terms,
* find the value of the denominator.
*/

/*
 * SOLUTION
 * There are 4 alternatives to strike out digits:
 *
 * 1) (10n+c) / (10d + c) = n/d <=> d = n i.e. no solutions in n < d
 * 2) (10c+n) / (10c+d) = n/d <=> d = n, i.e.  no solutions in n < d
 * 3) (10c+n) / (10d+c) = n/d <=> c(d-n) = 9d(n-c)
 *    Thus c<d<n and n-c = c/9 - cn/(9d) < 1, so n-c <= 0, i.e. no solutions.
 * 4) (10n+c)/(10c+d) = n/d <=> 9n(c-d) = c(d-n) > 0.
 *    Thus we need only investigate n < d < c <= 9 (84 iterations).
 */

namespace problem_33
{
using underlying_t = std::uint32_t;

inline underlying_t problem_33()
{
   underlying_t np = 1;
   underlying_t dp = 1;

   for(const auto c : std::views::iota(3, 10))
   {
      for(const auto d : std::views::iota(2, c))
      {
         for(const auto n : std::views::iota(1, d))
         {
            if((10*n + c)*d == n*(10*c + d))
            {
               np *= n;
               dp *= d;
            }
         }
      }
   }
   return dp / std::gcd(np, dp);
}
}

TEST(Problem33, CorrectAnswer)
{
   EXPECT_EQ(problem_33::problem_33(), 100);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_33_H
