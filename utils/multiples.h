#ifndef PROJECT_EULER_SOLUTIONS_MULTIPLES_H
#define PROJECT_EULER_SOLUTIONS_MULTIPLES_H

#include <concepts>
#include <array>

namespace multiples
{
template<typename T, std::size_t N>
   requires std::integral<T>
bool multiple_of_each(T num, const std::array<T, N>& factors)
{
   for(const auto factor : factors)
   {
      if(num % factor != 0) return false;
   }
   return true;
}
}

#endif //PROJECT_EULER_SOLUTIONS_MULTIPLES_H
