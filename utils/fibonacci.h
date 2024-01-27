#ifndef PROJECT_EULER_SOLUTIONS_FIBONACCI_H
#define PROJECT_EULER_SOLUTIONS_FIBONACCI_H

#include <cstdint>
#include <cassert>
#include <cmath>
#include <functional>

/*
 * Here the Fibonacci sequence is computed as 1, 2, 3, 5, 8, ...
 * i.e. starting from what is often considered the third
 * Fibonacci number, F_2.
 */

namespace fibonacci
{
using underlying_t = uint64_t;

/// Compute naively from definition
/// \param n Index, starts at 1
/// \return n:th Fibonacci number
inline underlying_t fibo_traverse(uint32_t n)
{
   assert(n!=0 && "Expects positive n");
   underlying_t a=1;
   underlying_t b=1;
   underlying_t c;
   if(n==1) return a;
   for(int i=1; i<n; ++i)
   {
      c = a + b;
      a = b;
      b = c;
   }

   return b;
}

/// Invoke a functor on each Fibonacci number
/// \param fibo_upper_bound Invoke only for Fibonacci numbers
///        less than this
/// \param func Functor to invoke
template<typename F>
void fibo_traverse_functor(uint32_t fibo_upper_bound, F func)
{
   underlying_t a=1;
   underlying_t b=1;
   underlying_t c;

   while(true)
   {
      c = a + b;
      a = b;
      b = c;
      if(b >= fibo_upper_bound) return;
      std::invoke(func, b);
   }
}

/*** Binet's formula ***/
static const double phi = (1 + std::sqrt(5)) / 2;
static const double psi = (1 - std::sqrt(5)) / 2;

/// Binet's formula
/// \param n Index, starts at 1
/// \return n:th Fibonacci number
inline underlying_t fibo_binet(uint32_t n)
{
   return static_cast<underlying_t>(
      (std::pow(phi, n+1) - std::pow(psi, n+1)) / std::sqrt(5));
}
}
#endif //PROJECT_EULER_SOLUTIONS_FIBONACCI_H
