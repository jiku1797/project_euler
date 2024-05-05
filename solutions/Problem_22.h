#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_22_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_22_H

#include <gtest/gtest.h>

#include <algorithm>
#include <numeric>
#include <filesystem>

#include "read_words.h"

/*
 * Names Scores
 * Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over
 * five-thousand first names, begin by sorting it into alphabetical order. Then working out the
 * alphabetical value for each name, multiply this value by its alphabetical position in the list
 * to obtain a name score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which is worth
 * 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of
 * 938 * 53 = 49714.
 *
 * What is the total of all the name scores in the file?
 */

namespace problem_22
{
using underlying_t = std::uint32_t;

inline int score(char c)
{
   return c - 'A' + 1;
}

/// Avoid the quotation marks
inline int word_score(const std::string& word)
{
   return std::accumulate(std::next(word.begin()), std::prev(word.end()), 0,
                          [](int acc, char c){return acc + score(c);});
}

underlying_t problem_22()
{
   using namespace std::string_literals;
   const auto file_path= std::filesystem::current_path().parent_path() / "solutions/0022_names.txt";
   auto words = io::parse_from_file(file_path.string());

   if(!words) return 0;

   auto& sorted_words = words.value();

   std::ranges::sort(sorted_words);

   std::size_t pos = 0;
   return std::accumulate(sorted_words.begin(), sorted_words.end(), 0ULL,
                  [&pos](std::size_t acc, const std::string& word)
                   {
                      return acc + word_score(word) * ++pos;
                   });
}
}

TEST(Problem22, CorrectAnswer)
{
   EXPECT_EQ(problem_22::problem_22(), 871198282);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_22_H
