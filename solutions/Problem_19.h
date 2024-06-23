#ifndef PROJECT_EULER_SOLUTIONS_PROBLEM_19_H
#define PROJECT_EULER_SOLUTIONS_PROBLEM_19_H

#include <gtest/gtest.h>

#include <chrono>

/*
 * Counting Sundays
 * You are given the following information, but you may prefer to do some research for yourself.
 * 1 Jan 1900 was a Monday.
 * Thirty days has September
 * April, June and November.
 * All the rest have thirty-one
 * Saving February alone
 * Which has twenty-eight, rain or shine.
 * And on leap years, twenty-nine.
 * A leap year occurs on any year evenly divisible by 4, but not on a century unless it is
 * divisible by 400.
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901
 * to 31 Dec 2000)?
 */

namespace problem_19
{
inline int problem_19()
{
   int cnt = 0;
   for (int y{1901}; y < 2001; ++y)
   {
      const std::chrono::year cur_year{y};
      for (int cur_month{1}; cur_month != 13; ++cur_month)
      {
         const std::chrono::year_month_day ymd{cur_year/cur_month/01};
         const std::chrono::weekday cur_weekday{std::chrono::sys_days(ymd)};
         if (cur_weekday == std::chrono::Sunday)
            ++cnt;
      }
   }
   return cnt;
}
}

TEST(Problem19, CorrectAnswer)
{
   EXPECT_EQ(problem_19::problem_19(), 171);
}

#endif //PROJECT_EULER_SOLUTIONS_PROBLEM_19_H
