#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_14_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_14_H

#include<gtest/gtest.h>

#include <unordered_map>
/*
 * Longest Collatz Sequence
 * The following iterative sequence is defined for the set of positive integers:
 * n -> n/2 (n is even)
 * n -> 3n + 1 (n is odd)
 * Using the rule above and starting with 13, we generate the following sequence:
 * 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 * Although it has not been proved yet (Collatz Problem), it is thought that all starting
 * numbers finish at 1.
 * Which starting number, under one million, produces the longest chain?
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */
namespace problem_14
{
using c_int_t = uint64_t;

[[nodiscard]] inline c_int_t next_collatz(c_int_t n)
{
   if(n % 2 == 0)
   {
      return n / 2;
   }

   return 3 * n + 1;
}

class collatz_cache
{
public:
   using cache_t = std::unordered_map<c_int_t, c_int_t>;

   collatz_cache()
   {
      cache_.reserve(1'000'000);
   }

   void insert(c_int_t start, c_int_t val)
   {
      cache_.insert(std::make_pair(start, val));
   }

   std::pair<cache_t::iterator, bool> contains(c_int_t start)
   {
      if(auto it = cache_.find(start); it != std::end(cache_))
      {
         return std::make_pair(it, true);
      }

      return std::make_pair(std::end(cache_), false);
   }

private:
   cache_t cache_;
};

class collatz
{
public:
   c_int_t collatz_length(int start)
   {
      c_int_t steps = 0;
      c_int_t number = start;

      while(number > 1)
      {
         if(auto [it, found] = cache_.contains(number); found)
         {
            const auto length = it->second + steps;
            cache_.insert(start, length);
            return length;
         }
         ++steps;
         number = next_collatz(number);
      }

      cache_.insert(start, steps + 1);
      return steps + 1;
   }

private:
   collatz_cache cache_{};
};

inline c_int_t problem_14()
{
   static constexpr int upper_bound = 1'000'000;

   c_int_t max_length = 1;
   c_int_t best_init = 1;
   collatz collatz_compute{};

   for(int i : std::views::iota(1, upper_bound))
   {
      const auto length = collatz_compute.collatz_length(i);
      if(length > max_length)
      {
         best_init = i;
         max_length = length;
      }
   }

   return best_init;
}

TEST(Problem14, CorrectAnswer)
{
   EXPECT_EQ(problem_14(), 837799);
}
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_14_H
