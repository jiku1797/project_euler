//
// Created by datafusion on 2024-03-17.
//

#ifndef PROJECT_EULER_SOLUTIONS_DIVISORS_H
#define PROJECT_EULER_SOLUTIONS_DIVISORS_H

#include <concepts>
#include <vector>

namespace divisors
{
template<typename T>
   requires std::integral<T>
constexpr std::vector<T> num_divisors_sieve(std::size_t N)
{
   std::vector<T> num_divisors(N+1, 0);

   for(std::size_t i = 1; i <= N; ++i)
   {
      for(std::size_t j = i; j <= N; j += i)
      {
         ++num_divisors[j];
      }
   }

   return num_divisors;
}
}

#endif //PROJECT_EULER_SOLUTIONS_DIVISORS_H
