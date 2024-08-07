#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_29_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_29_H

#include <gtest/gtest.h>

#include <vector>
#include <ranges>
#include <type_traits>

/*
* Distinct powers
* Consider all integer combinations of a^b for 2<=a<=5 and 2<=b<=5:
* 2^2=4,  2^3=8,    2^4=16,   2^5=32
* 3^2=9,  3^3=27,   3^4=81,   3^5=243
* 4^2=16, 4^3=64,   4^4=256,  4^5=1024
* 5^2=25, 5^3=125,  5^4=625,  5^5=3125
* If they are then placed in numerical order, with any repeats removed,
* we get the following sequence of distinct terms:
* 4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125.
* How many distinct terms are in the sequence generated by a^b for
* 2<=a<=100 and 2<=b<=100?
*/

namespace problem_29
{
using underlying_t = uint32_t;
namespace vws = std::views;

template <underlying_t N>
static constexpr underlying_t value = std::integral_constant<underlying_t, N>::value;

static constexpr underlying_t one = value<1>;
static constexpr underlying_t two = value<2>;
static constexpr underlying_t limit = 100;

constexpr underlying_t max_base_pow()
{
  // this will occur for the smallest base, i.e. 2^b = n^a = 64^a = 2^{6*a}
  underlying_t pow = 2;
  underlying_t exponent = 0;
  while(pow <= limit)
  {
    ++exponent;
    pow *= 2;
  }
  return exponent;
}

inline std::vector<underlying_t> get_min_exponents(underlying_t max_base_power, underlying_t max_exponent)
{
  std::vector<unsigned int> min_exponent((max_exponent+1)*(max_base_power+1));
  for (const auto i : vws::iota(one, max_base_power+1))
  {
    for (const auto j : vws::iota(one, max_exponent+1))
    {
      if (min_exponent[i*j] == 0)
        min_exponent[i*j] = i;
    }
  }

  return min_exponent;
}

inline void fill_children(std::vector<underlying_t>& bases, underlying_t i)
{
  // find all future children where "i" is the parent
  auto power = i * i;
  // [i^2] = [i^3] = [i^4] = ... = i
  while (power <= limit)
  {
    bases[power] = i;
    power *= i;
  }
}

/**
 * Get N such that base^N = power
 * @param base Base
 * @param power The power of \p base
 * @return N with power = base^N
 */
constexpr underlying_t get_exponent(underlying_t base, underlying_t power)
{
  underlying_t exponent = 0;
  while (power > 1)
  {
    power /= base;
    ++exponent;
  }
  return exponent;
}

inline underlying_t problem_29()
{
  static constexpr underlying_t limit = 100;
  static constexpr auto max_base_power = max_base_pow();

  const auto min_exponents = get_min_exponents(max_base_power, limit);

  // all "a" which can be composed as base^exponent, stored as [a] => [base]
  std::vector<underlying_t> bases(limit + 1, 0);

  // how often numbers were used multiple times (those are the collisions we are looking for)
  unsigned int repeated = 0;

  // analyze all bases
  for(const auto i : vws::iota(two, limit+1))
  {
    // is x = parent^exponent?
    auto parent = bases[i];
    if (parent == 0) // no
    {
      fill_children(bases, i);

      // no i=a^b possible, "repeated" remains unchanged
      continue;
    }

    // we have a parent, find exponent such that a = parent^exponent
    const underlying_t exponent = get_exponent(parent, i);

    // analyze all pairs, and count all numbers we saw before (repeated++)
    for(const auto y : vws::iota(two, limit+1))
    {
      // that exponent was already used ?
      if (min_exponents[y * exponent] < exponent)
        ++repeated;
    }
  }

  return (limit-1)*(limit-1) - repeated;
}
} // namespace problem_29

TEST(Problem29, CorrectAnswer)
{
  EXPECT_EQ(problem_29::problem_29(), 9183);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_29_H
