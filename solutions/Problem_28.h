#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_28_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_28_H

#include <gtest/gtest.h>

/*
* Number Spiral Diagonals
* Starting with the number 1 and moving to the right in a clockwise
* direction a 5 by 5 spiral is formed as follows:
*
*       21 22 23 24 25
*       20 07 08 09 10
*       19 06 01 02 11
*       18 05 04 03 12
*       17 16 15 14 13
*
* It can be verified that the sum of the numbers on the diagonals is 101.
* What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
* formed in the same way?
*/

/*
 * NOTE ON SOLUTION
 * The upper right corner of the square with side i is i^2, where
 * i = 1, 3, ..., 1001, or, put differently, (2*j+1)^2 where
 * j = 0, 1, ..., [1001/2] denotes the j:th square. Here i = 2*j+1 or j = [i/2].
 * The other corners are then found by subtracting i-1 = 2*j successively three
 * times. This yields corner values
 * UR: 4*j^2 + 4*j + 1
 * UL: 4*j^2 + 2*j + 1
 * LL: 4*j^2 + 1
 * LR: 4*j^2 - 2*j + 1
 * Note howveer that this reasoing is only valid starting from second square (j=1)
 * since the first "square" does not have 4 corners. Consequently the sum of all
 * corners can be found by summing 16*j^2 + 4*j + 4 from j=0 to [1001/2] and add
 * 1 for the innermost "square". (There are exact formulas for this, but
 * for the purpose of this problem a direct summation suffices.)
 */

namespace problem_28
{
using underlying_t = uint32_t;

inline underlying_t problem_28()
{
  // see note for reasoning
  static constexpr underlying_t limit = 1001U;
  underlying_t sum = 1; // accomodate for the innermost square

  for(underlying_t j=1; j<=limit/2; ++j)
  {
    sum += 16*j*j + 4*j + 4;
  }

  return sum;
}
} // namespace problem_26

TEST(Problem28, CorrectAnswer)
{
  EXPECT_EQ(problem_28::problem_28(), 669171001);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_28_H
