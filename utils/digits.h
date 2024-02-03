#ifndef PROJECT_EULER_SOLUTIONS_DIGITS_H
#define PROJECT_EULER_SOLUTIONS_DIGITS_H

#include <vector>
#include <concepts>

namespace digits
{
///
/// \param n
/// \return Digits in "reverse" order (a_0, a_1, ..., a_n)
std::vector<int> digits(std::integral auto n)
{
   std::vector<int> digits;
   while(n > 0)
   {
      digits.push_back(n % 10);
      n /= 10;
   }

   return digits;
}

///
/// \param n
/// \return True iff \p n is palindrome
bool is_palindrome(std::integral auto n)
{
   const auto ds = digits(n);
   const auto sz = ds.size();

   for(int i=0; i<sz/2; ++i)
   {
      if(ds[i] != ds[sz - i - 1]) return false;
   }
   return true;
}
}
#endif //PROJECT_EULER_SOLUTIONS_DIGITS_H
