#ifndef PROJECT_EULER_SOLUTIONS_READ_VECTOR_OF_VECTORS_H
#define PROJECT_EULER_SOLUTIONS_READ_VECTOR_OF_VECTORS_H

#include <vector>
#include <string_view>
#include <charconv>
#include <cctype>
#include <iterator>
#include <utility>
#include <optional>

namespace io::read_vector_of_vectors
{
using underlying_t = int;
using row_t = std::vector<underlying_t>;
using result_t = std::vector<row_t>;

///
/// \param str String to parse from begin to newline
/// \return Parsed row and iterator to first non-parsed element
inline std::pair<row_t, std::string_view::const_iterator>
   read_row(std::string_view str)
{
   row_t row;
   auto begin = str.begin();
   auto end = str.end();

   while(begin != end)
   {
      int num;
      auto [p, ec] = std::from_chars(begin, str.end(), num);

      if(ec != std::errc())
      {
         ++begin;
         continue;
      }

      row.push_back(num);

      begin = p;

      if(*begin == '\n')
      {
         break;
      }

      // trim whitespace
      while(begin < end && std::isspace(*begin))
      {
         ++begin;
      }
   }

   return std::make_pair(row, begin);
}

inline result_t read(std::string_view str)
{
   auto begin = str.begin();
   auto end = str.end();

   result_t ret;

   while(begin != end)
   {
      auto [row, ptr] = read_row(std::string_view(begin, end));
      ret.push_back(std::move(row));
      begin = ptr;
   }

   return ret;
}
}

#endif //PROJECT_EULER_SOLUTIONS_READ_VECTOR_OF_VECTORS_H
