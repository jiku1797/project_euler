#ifndef PROJECT_EULER_SOLUTIONS_READ_MATRIX_H
#define PROJECT_EULER_SOLUTIONS_READ_MATRIX_H

#include "Matrix.h"

#include <string_view>
#include <charconv>
#include <cctype>

namespace io
{
template <typename T, std::size_t ROW, std::size_t COL>
Matrix<T, ROW, COL> read(std::string_view str)
{
   Matrix<T, ROW, COL> mat{};

   auto begin = str.begin();
   auto end = str.end();
   std::size_t count = 0;

   while(begin != end && count < mat.size())
   {
      T num;
      auto [p, ec] = std::from_chars(begin, end, num);
      if(ec != std::errc())
      {
         ++begin;
         continue;
      }

      mat[count++] = num;
      begin = p;

      // skip whitespace or newline
      while(begin < end && std::isspace(*begin))
      {
         ++begin;
      }
   }

   return mat;
}
}

#endif //PROJECT_EULER_SOLUTIONS_READ_MATRIX_H
