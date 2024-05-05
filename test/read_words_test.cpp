#include "gtest/gtest.h"

#include "../utils/read_words.h"

#include <filesystem>

TEST(TestReadWords, SpaceSeparated)
{
   const char* str = R"(Nothing takes place in the world whose meaning
 is not that of some maximum or minimum)";

   const auto words = io::parse<' '>(str);

   using namespace std::string_literals;

   const std::vector<std::string> expected = {"Nothing"s, "takes"s,
      "place"s, "in"s, "the"s, "world"s, "whose"s, "meaning"s, "is"s,
      "not"s, "that"s, "of"s, "some"s, "maximum"s, "or"s, "minimum"s};

   EXPECT_EQ(words, expected);
}

TEST(TestReadWords, CommaSeparated)
{
   const char* str = R"(Nothing,takes,place,in,the,world,whose,meaning,
is,not,that,of,some,maximum,or,minimum)";

   const auto words = io::parse<','>(str);

   using namespace std::string_literals;

   const std::vector<std::string> expected = {"Nothing"s, "takes"s,
                                              "place"s, "in"s, "the"s, "world"s, "whose"s, "meaning"s, "is"s,
                                              "not"s, "that"s, "of"s, "some"s, "maximum"s, "or"s, "minimum"s};

   EXPECT_EQ(words, expected);
}

TEST(TestReadWords, ReadWhitespaceSeparatedFromFile)
{
   const auto file_path= std::filesystem::current_path().parent_path() / "test/test_words.txt";

   const auto words = io::parse_from_file<' '>(file_path.string());

   if(!words)
   {
      FAIL() << "Unable to open file: " << file_path;
   }

   using namespace std::string_literals;

   const std::vector<std::string> expected = {"just"s, "some"s, "words"s, "to"s, "play"s,
      "around"s, "with"s};

   EXPECT_EQ(words, expected);
}

TEST(TestReadWords, TestTrimWhitespace)
{
   using namespace std::string_literals;
   const auto result1 = io::detail::trim(" whitespace  "s);
   EXPECT_EQ(result1, "whitespace"s);

   const auto result2 = io::detail::trim(" whitespace"s);
   EXPECT_EQ(result2, "whitespace"s);

   const auto result3 = io::detail::trim("whitespace   "s);
   EXPECT_EQ(result3, "whitespace"s);

   const auto result4 = io::detail::trim("no_whitespace"s);
   EXPECT_EQ(result4, "no_whitespace"s);
}

TEST(TestReadWords, TestTrimQuotes)
{
   using namespace std::string_literals;
   const auto result1 = io::detail::trim(R"("quoted")"s, R"(")"s);
   EXPECT_EQ(result1, "quoted"s);

   const auto result2 = io::detail::trim(R"(" quoted"  )"s, R"(" )"s);
   EXPECT_EQ(result2, "quoted"s);
}
