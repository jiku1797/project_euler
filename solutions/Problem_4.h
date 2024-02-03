#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_4_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_4_H

#include <gtest/gtest.h>

#include <algorithm>

#include "digits.h"

/* Largest Palindrome Product
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 * 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

/// A 6 digit palindrome number a0 + 10*a1 + 10^2*a2 + 10^3*a3 + 10^4*a1 + 10^5*a0
/// = (1+10^5)*a0 + 10*(10^3+1)*a1 + 10^2*(10+1)*a0 is divisible by 11.
/// Written as any product, one of them must be a multiple of 11.
/// \return
int problem_4()
{
   int greatest = 0;
   for(int x=999; x>=100; --x)
   {
      for(int y=990; y>=100; y-=11)
      {
         const int prod = x*y;
         if(digits::is_palindrome(prod))
         {
            greatest = std::max(prod, greatest);
         }

         if(prod < greatest) break;
      }
   }
   return greatest;
}

TEST(Problem4, CorrectAnswer)
{
   EXPECT_EQ(problem_4(), 906609);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_4_H
