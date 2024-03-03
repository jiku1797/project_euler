#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_9_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_9_H

#include <ranges>

/*
 * Special Pythagorean Triplet
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a^2 + b^2 = c^2.
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

static constexpr bool isPythagoreanTriple(int a, int b, int c)
{
   return c * c == a * a + b * b;
}

std::size_t problem_9()
{
   static constexpr int sum = 1000;

   for(int a : std::views::iota(1, sum - 1))
   {
      for(int b : std::views::iota(a+1, sum - 2*a))
      {
         const int c = sum - a - b;
         if(isPythagoreanTriple(a, b, c))
         {
            return a * b * c;
         }
      }
   }
   return 1;
}

TEST(Problem9, CorrectAnswer)
{
   EXPECT_EQ(problem_9(), 31875000);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_9_H
