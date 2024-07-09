#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_27_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_27_H

#include <gtest/gtest.h>

#include "primes.h"

/*
* Quadratic Primes
* Euler discovered the remarkable quadratic formula:
* n^2 + n + 41
* It turns out that the formula will produce 40 primes for the consecutive
* integer values 0 <= n <= 39. However, when n = 40, 40^2 + 40 + 41 =
* 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41^2 + 41 + 41
* is clearly divisible by 41.
* The incredible formula n^2 - 79n + 1601 was discovered, which produces 80
* primes for the consecutive values 0 <= n <= 79. The product of the
* coefficients, -79 and 1601, is -126479.
* Considering quadratics of the form:
* n^2 + an + b, where |a| <= 1000 and |b| <= 1000 where |n| is the
* modulus/absolute value of n, e.g. |11| = 11 and |-4| = 4.
* Find the product of the coefficients, a and b, for the quadratic expression
* that produces the maximum number of primes for consecutive values of n,
* starting with n = 0.
 */

namespace problem_27
{
using underlying_t = int32_t;

inline underlying_t problem_27()
{
  static constexpr underlying_t limit = 1'000;
  underlying_t consecutive = 0;
  underlying_t best_a = 0;
  underlying_t best_b = 0;

  // simple brute-force approach
  for (underlying_t a = -limit; a <= limit; ++a)
  {
    for (underlying_t b = -limit; b <= limit; ++b)
    {
      // count number of consecutive prime numbers
      underlying_t length = 0;
      while (primes::is_prime(length * length + a * length + b))
      {
        length++;
      }

      if (consecutive < length)
      {
        consecutive = length;
        best_a = a;
        best_b = b;
      }
    }
  }

  return best_a * best_b;
}
} // namespace problem_26

TEST(Problem27, CorrectAnswer)
{
  EXPECT_EQ(problem_27::problem_27(), -59231);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_27_H
