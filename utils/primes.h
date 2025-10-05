#ifndef PROJECT_EULER_SOLUTIONS_PRIMES_H
#define PROJECT_EULER_SOLUTIONS_PRIMES_H

#include <concepts>
#include <cmath>
#include <array>
#include <iterator>
#include <unordered_set>

namespace primes
{
bool is_prime(std::integral auto num)
{
   if(num <= 1) return false;
   if (num <= 3) return true;

   // enable skipping 5 numbers ata time
   if (num % 2 == 0 || num % 3 == 0)
   {
      return false;
   }

   for (int i = 5; i*i <= num; i += 6)
   {
      if(num % i == 0 || num % (i + 2) == 0)
         return false;
   }

   return true;
}

/**
 *
 * \param limit Primes up to and including this
 * \return Set of all primes up to and including \p limit
 */
auto primes(std::integral auto limit)
{
   using prime_set = std::unordered_set<std::uint32_t>;
   prime_set primes;
   if(limit >= 2)
   {
      primes.insert(2);
   }

   for(int i = 3; i <= limit; i += 2)
   {
      if(is_prime(i))
      {
         primes.insert(i);
      }
   }

   return primes;
}

template<std::size_t N>
using sieve_t = std::array<bool, N+1>;

template<std::size_t N>
constexpr sieve_t<N> sieve_of_Eratosthenes()
{
   static_assert(N>1);

   sieve_t<N> sieve{};
   std::ranges::fill(std::next(std::begin(sieve), 2), std::end(sieve), true);

   for (int p = 2; p * p <= N; ++p)
   {
      if (sieve[p] == true)
      {
         for(std::size_t i = p * p; i <= N; i += p)
         {
            sieve[i] = false;
         }
      }
   }

   return sieve;
}
}

#endif //PROJECT_EULER_SOLUTIONS_PRIMES_H
