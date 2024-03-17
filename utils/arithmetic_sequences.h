#ifndef PROJECT_EULER_SOLUTIONS_ARITHMETIC_SEQUENCES_H
#define PROJECT_EULER_SOLUTIONS_ARITHMETIC_SEQUENCES_H

#include <concepts>

namespace arithmetic_sequence
{
/// Calculates 1 + 2 + ... + \p last
/// \param last Maximum element
/// \return Arithmetic sum
auto arithmetic_sum(std::integral auto last)
{
   return (1 + last) * last / 2;
}
} // arithmetic_sequence

#endif //PROJECT_EULER_SOLUTIONS_ARITHMETIC_SEQUENCES_H
