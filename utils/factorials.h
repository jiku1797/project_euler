#ifndef PROJECT_EULER_SOLUTIONS_FACTORIALS_H
#define PROJECT_EULER_SOLUTIONS_FACTORIALS_H

#include <vector>
#include <ranges>
#include <cmath>

namespace factorial
{
using Digits = std::vector<u_int16_t>;

inline int num_factorial_digits(int n)
{
   double log_sum = 0.0;

   for(const int i : std::views::iota(2, n+1))
   {
      log_sum += std::log10(i);
   }

   return std::ceil(log_sum);
}

/// NOTE: For very large factorials care must be taken so
/// as not to overflow the underlying integral type.
/// \param n The last factor in 1*2*3*...*(n-1)*n
/// \return The digits of the factorial, but in reverse order
inline Digits factorial(int n)
{
   Digits digits = {1};

   const auto num_digits = num_factorial_digits(n);

   digits.reserve(num_digits);

   for (unsigned int factor = 2; factor <= n; factor++)
   {
      uint8_t carry = 0;

      for(auto& digit : digits)
      {
         digit = digit * factor + carry;

         // overflow?
         if (digit >= 10)
         {
            carry  = digit / 10;
            digit %= 10;
         }
         else
            carry  = 0;
      }

      while(carry != 0)
      {
         digits.push_back(carry % 10);
         carry /= 10;
      }
   }
   return digits;
}
}

#endif //PROJECT_EULER_SOLUTIONS_FACTORIALS_H
