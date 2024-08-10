#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_30_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_30_H

#include <gtest/gtest.h>

#include <numeric>

#include "digits.h"

/*
* Digit Fifth Powers
* Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
* 1634 = 1^4 + 6^4 + 3^4 + 4^4
* 8208 = 8^4 + 2^4 + 0^4 + 8^4
* 9474 = 9^4 + 4^4 + 7^4 + 4^4
* As 1 = 1^4 is not a sum it is not included.
* The sum of these numbers is 1634 + 8208 + 9474 = 19316.
* Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

namespace problem_30
{
using underlying_t = uint32_t;

inline underlying_t problem_30()
{
  static constexpr underlying_t exponent = 5;

  // there can't be a number with 7 digits (or more) which fulfils the condition for exponent=6
  // since if all digits are 9, then
  // 7 digits: 7 * 9^5 = 413343
  static constexpr const underlying_t upper_bound = 6 * 9 * 9 * 9 * 9 * 9;

  underlying_t sum = 0;

  for(underlying_t i = 2; i <= upper_bound; ++i)
  {
     const auto digits = digits::digits(i);
     const underlying_t current_sum = std::transform_reduce(std::cbegin(digits), std::cend(digits),
       0, std::plus{}, [](underlying_t n){return std::pow(n, exponent);});

    if(current_sum == i)
    {
      sum += i;
    }
  }

  return sum;
}
} // namespace problem_30

TEST(Problem30, CorrectAnswer)
{
  EXPECT_EQ(problem_30::problem_30(), 443839);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_30_H
