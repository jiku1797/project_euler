#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_32_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_32_H

#include <unordered_set>
#include <algorithm>
#include <numeric>

namespace problem_32
{
using underlying_t = std::uint32_t;
namespace sr = std::ranges;

inline underlying_t problem_32()
{
   static constexpr int maxDigit = 9;
   std::vector<underlying_t> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   digits.resize(maxDigit);
   std::unordered_set<underlying_t> valid;

   do
   {
      for (int len_a = 1; len_a < maxDigit; ++len_a)
      {
         for (int len_b = 1; len_b < maxDigit - len_a; ++len_b)
         {
            const auto len_c = maxDigit - len_a - len_b;

            // exclude impossible cases
            if (len_c < len_a || len_c < len_b) break;

            // current position in "digits"
            int pos = 0;

            auto compute_num = [&pos, &digits](auto length) -> underlying_t
            {
               underlying_t num = 0;
               for (int i = 1; i <= length; ++i)
               {
                  num *= 10;
                  num += digits[pos++];
               }

               return num;
            };

            const auto a = compute_num(len_a);
            const auto b = compute_num(len_b);
            const auto c = compute_num(len_c);

            if(a*b == c) valid.insert(c);
         }
      }
   }
   while(sr::next_permutation(digits).found);

   return std::reduce(std::begin(valid), std::end(valid), underlying_t{});
}
}

TEST(Problem32, CorrectAnswer)
{
   EXPECT_EQ(problem_32::problem_32(), 45228);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_32_H
