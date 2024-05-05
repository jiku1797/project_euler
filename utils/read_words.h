#ifndef PROJECT_EULER_SOLUTIONS_READ_WORDS_H
#define PROJECT_EULER_SOLUTIONS_READ_WORDS_H

#include <string>
#include <string_view>
#include <vector>
#include <optional>
#include <sstream>
#include <iterator>
#include <fstream>

namespace io
{
using namespace std::string_literals;

namespace detail
{
inline std::string trim(const std::string& str, const std::string& delimiters = " "s)
{
   const auto first_found = str.find_first_not_of(delimiters);
   const auto last_found = str.find_last_not_of(delimiters);

   if(first_found == std::string::npos) return {};
   const std::size_t end = (last_found == std::string::npos) ? str.size() : last_found + 1;

   return str.substr(first_found, end - first_found);
}

template <char>
class DelimitedWord : public std::string
{ };

template <char delim>
inline std::istream& operator>>(std::istream& is, DelimitedWord<delim>& output)
{
   std::getline(is, output, delim);
   if(output.ends_with('\n'))
      output.pop_back();
   if(output.starts_with('\n'))
      output.erase(output.begin());
   return is;
}

template <typename Istream, char delim = ','>
inline std::vector<std::string> parse_base(Istream& words)
{
   return {std::istream_iterator<DelimitedWord<delim>>(words),
      std::istream_iterator<DelimitedWord<delim>>()};
}
} // detail

template <char delim = ','>
inline std::vector<std::string> parse(const std::string& words)
{
   std::istringstream iss(words);
   return detail::parse_base<std::istringstream, delim>(iss);
}

template <char delim = ','>
inline std::optional<std::vector<std::string>> parse_from_file(const std::string& filename)
{
   std::ifstream ifs(filename.c_str());

   if(!ifs.good()) return std::nullopt;

   return std::make_optional(detail::parse_base<std::ifstream, delim>(ifs));
}
}

#endif //PROJECT_EULER_SOLUTIONS_READ_WORDS_H
