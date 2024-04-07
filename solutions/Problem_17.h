#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_17_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_17_H

#include<gtest/gtest.h>

#include <array>
#include <string>
#include <numeric>
#include <ranges>

/*
 * Number Letter Counts
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five,
 * then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words,
 * how many letters would be used?
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains
 * 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing
 * out numbers is in compliance with British usage.
 */

namespace problem_17
{
std::array<std::string, 19> words_base = {
   "one",
   "two",
   "three",
   "four",
   "five",
   "six",
   "seven",
   "eight",
   "nine",
   "ten",
   "eleven",
   "twelve",
   "thirteen",
   "fourteen",
   "fifteen",
   "sixteen",
   "seventeen",
   "eighteen",
   "nineteen"};

std::array<std::string, 8> decade_words = {
   "twenty",
   "thirty",
   "forty",
   "fifty",
   "sixty",
   "seventy",
   "eighty",
   "ninety"
};

std::size_t problem_17()
{
   // count up to 19
   std::size_t count = std::accumulate(words_base.begin(), words_base.end(), 0,
      [](std::size_t acc, const auto& word){return acc + word.size();});

   // count remaining up to and including 99
   for(const auto& decade : decade_words)
   {
      const auto decade_sz = decade.size();
      count += decade_sz;

      for(const auto i : std::views::iota(0, 9))
      {
         count += decade_sz + words_base[i].size();
      }
   }

   // cache for reuse
   const auto first_99_count = count;

   // count to 999
   const auto hundred_sz = "hundred"sv.size();
   const auto and_sz = "and"sv.size();

   for(const auto i : std::views::iota(0, 9))
   {
      const auto base_sz = words_base[i].size();

      // even hundreds
      count += base_sz + hundred_sz;
      // remaining
      count += (base_sz + hundred_sz + and_sz) * 99 + first_99_count;
   }

   // last word
   count += "onethousand"sv.size();

   return count;
}
}

TEST(Problem17, CorrectAnswer)
{
   EXPECT_EQ(problem_17::problem_17(), 21124);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_17_H
