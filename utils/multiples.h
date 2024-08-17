#ifndef PROJECT_EULER_SOLUTIONS_MULTIPLES_H
#define PROJECT_EULER_SOLUTIONS_MULTIPLES_H

#include <concepts>
#include <array>
#include <algorithm>

namespace multiples
{
template<typename T, std::size_t N>
   requires std::integral<T>
bool multiple_of_each(T num, const std::array<T, N>& factors)
{
   return std::all_of(std::cbegin(factors), std::cend(factors),
      [num](T factor){return num % factor == 0;});
}
}

#endif //PROJECT_EULER_SOLUTIONS_MULTIPLES_H
