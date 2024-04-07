#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_16_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_16_H

#include<gtest/gtest.h>

#include <vector>
#include <numeric>

/*
 * Power Digit Sum
 * 2^{15} = 32768 and the sum of its digits is $ + 2 + 7 + 6 + 8 = 26.
 * What is the sum of the digits of the number 2^{1000}?
 */

namespace problem_16
{
int problem_16()
{
   using Digits = std::vector<unsigned short>;
   std::vector<Digits> power_two_digits = {{2}}; // start at 2^1
   int exponent = 1;

   static constexpr int final_power = 1'000;

   while(exponent < final_power)
   {
      ++exponent;
      // start with previous digits
      auto next_digits = power_two_digits.back();
      int remainder = 0;
      for(auto& digit : next_digits)
      {
         digit = 2 * digit + remainder;

         if(digit > 9)
         {
            digit -= 10;
            remainder = 1;
         }
         else
         {
            remainder = 0;
         }
      }

      if(remainder > 0)
      {
         next_digits.push_back(remainder);
      }

      power_two_digits.push_back(next_digits);
   }

   return std::reduce(power_two_digits.back().begin(), power_two_digits.back().end());
}
}

TEST(Problem16, CorrectAnswer)
{
   EXPECT_EQ(problem_16::problem_16(), 1366);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_16_H
