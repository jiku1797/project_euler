#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_31_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_31_H

#include <gtest/gtest.h>

/*
* Coin Sums
* In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight
* coins in general circulation:
* 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
* It is possible to make £2 in the following way:
* 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
* How many different ways can £2 be made using any number of coins?
*/

namespace problem_31
{
using underlying_t = uint32_t;

inline underlying_t problem_31()
{
   static constexpr underlying_t target = 200;
   std::array<underlying_t, 8> coins = {1, 2, 5, 10, 20, 50, 100, 200};
   std::array<underlying_t, target+1> ways = {1};

   for(auto coin : coins)
   {
      for(const auto i : std::views::iota(coin, target+2))
      {
         ways[i] += ways[i-coin];
      }
   }
   return ways[target];
}
} // namespace problem_31

TEST(Problem31, CorrectAnswer)
{
   EXPECT_EQ(problem_31::problem_31(), 73682);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_31_H
