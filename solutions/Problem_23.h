#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_23_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_23_H

#include <gtest/gtest.h>

#include <set>

#include "divisors.h"

/*
 * Non-Abundant Sums
 * A perfect number is a number for which the sum of its proper divisors is exactly equal to
 * the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28,
 * which means that 28 is a perfect number.

 * A number n is called deficient if the sum of its proper divisors is less than n, and it is
 * called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can
 * be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown
 * that all integers greater than 28123 can be written as the sum of two abundant numbers. However,
 * this upper limit cannot be reduced any further by analysis even though it is known that the
 * greatest number that cannot be expressed as the sum of two abundant numbers is less than this
 * limit.
 *
 * Find the sum of all the positive integers which cannot be written as the sum of two abundant
 * numbers.
 */

namespace problem_23
{
using underlying_t = std::uint32_t;

static constexpr underlying_t upper_limit = 28123;

template<underlying_t upper_limit>
class Abundant
{
public:
   Abundant()
   {
      for(const underlying_t i : std::views::iota(static_cast<underlying_t>(1), upper_limit))
      {
         if(divisors::sum_of_divisors(i) > i)
         {
            abundant_nums_.insert(i);
         }
      }
   }

   [[nodiscard]] bool is_sum_of_abundant(underlying_t n) const
   {
      if(n > upper_limit) return false;

      for(const auto i : abundant_nums_)
      {
         if(i > n / 2)
         {
            return false;
         }

         if(abundant_nums_.contains(n - i))
         {
            return true;
         }
      }

      return false;
   }

private:
   std::set<underlying_t> abundant_nums_{};
};

inline underlying_t problem_23()
{
   const Abundant<upper_limit> abundant{};

   underlying_t sum_of_non_abundant = 0;

   for(underlying_t i = 0; i < upper_limit; ++i)
   {
      if(!abundant.is_sum_of_abundant(i))
      {
         sum_of_non_abundant += i;
      }
   }

   return sum_of_non_abundant;
}
}

TEST(Problem23, CorrectAnswer)
{
   EXPECT_EQ(problem_23::problem_23(), 4179871);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_23_H
