#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_24_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_24_H

#include <gtest/gtest.h>
#include <algorithm>
#include <array>

/*
 * Lexicographic Permutations
 * A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation
 * of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically,
 * we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 *          012   021   102   120   201   210
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

namespace problem_24
{
using underlying_t = std::uint32_t;

template <typename T, std::size_t N>
underlying_t to_number(const std::array<T, N>& arr)
{
   underlying_t ten_power = 1;
   return std::accumulate(std::rbegin(arr), std::rend(arr), 0, [&ten_power](underlying_t acc, T val)
                      {
                         acc += val * ten_power;
                         ten_power *= 10;
                         return acc;
                      });
}

inline underlying_t problem_24()
{
   static constexpr underlying_t target = 1'000'000;
   std::array<uint8_t, 10> range = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

   for(underlying_t i=1; i<target; ++i)
   {
      std::next_permutation(std::begin(range), std::end(range));
   }

   return to_number(range);
}
}

TEST(Problem24, CorrectAnswer)
{
   EXPECT_EQ(problem_24::problem_24(), 2783915460);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_24_H
