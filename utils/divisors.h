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

/// Obtain the sum of all divisors of \p n
/// 1 counts as divisor, but not \p n
template <std::integral T>
inline auto sum_of_divisors(T n)
{
   T divisor_sum = 1;

   for (T divisor = 2; divisor * divisor <= n; ++divisor)
   {
      if(n % divisor == 0)
      {
         divisor_sum += divisor;

         auto other_divisor = n / divisor;
         // avoid double counting square numbers
         if(other_divisor != divisor)
            divisor_sum += other_divisor;
      }
   }

   return divisor_sum;
}
}

#endif //PROJECT_EULER_SOLUTIONS_DIVISORS_H
