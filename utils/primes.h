#ifndef PROJECT_EULER_SOLUTIONS_PRIMES_H
#define PROJECT_EULER_SOLUTIONS_PRIMES_H

#include <concepts>
#include <cmath>

namespace primes
{
inline bool is_prime(std::integral auto num)
{
   if(num <= 1) return false;
   if (num <= 3) return true;

   int upper_bound = std::sqrt(num);
   // enable skipping 5 numbers ata time
   if (num % 2 == 0 || num % 3 == 0)
   {
      return false;
   }

   for (int i = 5; i <= upper_bound; i += 6)
   {
      if(num % i == 0 || num % (i + 2) == 0)
         return false;
   }

   return true;
}
}

#endif //PROJECT_EULER_SOLUTIONS_PRIMES_H
