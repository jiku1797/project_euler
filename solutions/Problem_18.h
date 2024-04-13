#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_18_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_18_H

#include <gtest/gtest.h>

#include "../utils/read_vector_of_vectors.h"

/*
 * Maximum Path Sum I
 * By starting at the top of the triangle below and moving to adjacent numbers on the
 * row below, the maximum total from top to bottom is 23.
 * That is, 3 + 7 + 4 + 9 = 23.
 * Find the maximum total from top to bottom of the triangle below:
 * 75
 * 95 64
 * 17 47 82
 * 18 35 87 10
 * 20 04 82 47 65
 * 19 01 23 75 03 34
 * 88 02 77 73 07 63 67
 * 99 65 04 28 06 16 70 92
 * 41 41 26 56 83 40 80 70 33
 * 41 48 72 33 47 32 37 16 94 29
 * 53 71 44 65 25 43 91 52 97 51 14
 * 70 11 33 28 77 73 17 78 39 68 17 57
 * 91 71 52 38 17 14 91 43 58 50 27 29 48
 * 63 66 04 68 89 53 67 30 73 16 69 87 40 31
 * 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
 * NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route.
 * However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot
 * be solved by brute force, and requires a clever method!
 */

namespace problem_18
{
static constexpr const char* input = R"(75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23)";

io::read_vector_of_vectors::result_t numbers = io::read_vector_of_vectors::read(input);

int problem_18()
{
   const std::size_t num_rows = numbers.size();

   std::vector<int> prev_sums;
   prev_sums.push_back(numbers[0][0]);

   // sum over remaining rows
   for(std::size_t row = 1; row < num_rows; ++row)
   {
      const auto row_sz = numbers[row].size();
      std::vector<int> current_sums;
      current_sums.reserve(row_sz);

      // process all numbers of current row
      for (std::size_t col = 0; col < row_sz; ++col)
      {
         int left_parent = 0;
         if (col > 0)
            left_parent = prev_sums[col - 1];

         int right_parent = 0;

         if (col < prev_sums.size())
            right_parent = prev_sums[col];

         // add larger parent to current value
         const int sum = numbers[row][col] + std::max(left_parent, right_parent);
         current_sums.push_back(sum);
      }

      prev_sums = std::move(current_sums);
   }

   return *std::max_element(prev_sums.begin(), prev_sums.end());
}
}

TEST(Problem18, CorrectAnswer)
{
   EXPECT_EQ(problem_18::problem_18(), 1074);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_18_H
