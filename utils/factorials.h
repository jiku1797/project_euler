#ifndef PROJECT_EULER_SOLUTIONS_FACTORIALS_H
#define PROJECT_EULER_SOLUTIONS_FACTORIALS_H

#include <vector>
#include <unordered_map>
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

   for (const int factor : std::views::iota(2, n+1))
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

template<typename T>
inline static std::unordered_map<T, std::uint32_t> factorials = {
   {0, 1},
   {1, 1},
   {2, 2},
   {3, 6},
   {4, 24},
   {5, 120},
   {6, 720},
   {7, 5040},
   {8, 40320},
   {9, 362880}
};
}

#endif //PROJECT_EULER_SOLUTIONS_FACTORIALS_H
