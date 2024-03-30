#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_15_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_15_H

#include<gtest/gtest.h>

#include <deque>

#include "Matrix.h"

/*
 * Lattice Paths
 * Starting in the top left corner of a 2x2 grid, and only being able to move
 * to the right and down, there are exactly 6 routes to the bottom right corner.
 * How many such routes are there through a 20x20 grid?

 * NOTE: The easy solution is to make the observation that out of 20 + 20 moves,
 * any 20 of them should be downwards. This results in there being C(40, 20)
 * possible paths where C(n, k) denotes a general binomial coefficient (i.e. the
 * coefficient of x^k in the expansion of (1 + x)^n).
 *
 * For the sake of a computationally more interesting solution we apply a tree
 * based solution, working ourselves backwards from the lower right point to the
 * initial top left one.
 */

namespace problem_15
{
struct Point
{
   int x_;
   int y_;
};

using int_t = uint64_t;

int_t problem_15()
{
   static constexpr int unknown = -1;
   static constexpr int SIZE = 20 + 1; // 21x21 points in a 20x20 grid
   static constexpr int LAST = SIZE - 1;

   Matrix<int_t, SIZE, SIZE> grid(unknown);
   grid.at(LAST, LAST) = 1;

   std::deque<Point> unprocessed;
   unprocessed.push_back({.x_ = LAST, .y_ = LAST - 1});
   unprocessed.push_back({.x_ = LAST - 1, .y_ = LAST});

   while(!unprocessed.empty())
   {
      auto current = unprocessed.front();
      unprocessed.pop_front();

      const auto x = current.x_;
      const auto y = current.y_;

      if(grid.at(x, y) != unknown)
         continue;

      int_t count = 0;

      if(x < LAST)
      {
         count += grid.at(x + 1, y);
      }

      if(y < LAST)
      {
         count += grid.at(x, y + 1);
      }

      grid.at(x, y) = count;

      if(y > 0)
      {
         unprocessed.push_back({x, y - 1});
      }
      if(x > 0)
      {
         unprocessed.push_back({x - 1, y});
      }
   }

   return grid.at(0, 0);
}

TEST(Problem15, CorrectAnswer)
{
   EXPECT_EQ(problem_15(), 137846528820);
}
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_15_H
