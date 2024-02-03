#include "gtest/gtest.h"

#include <utility>
#include <vector>

#include "../utils/digits_test.h"

class TestDigitsGenerate : public testing::TestWithParam<std::pair<int, std::vector<int>>>{};

TEST_P(TestDigitsGenerate, Digits)
{
   const auto [num, expected] = GetParam();
   const auto actual = digits::digits(num);
   EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
   TestDigitsGenerateBasicInputs
   , TestDigitsGenerate, ::testing::Values(
      std::make_pair<int, std::vector<int>>(0,{})
      , std::make_pair<int, std::vector<int>>(1,{1})
      , std::make_pair<int, std::vector<int>>(10,{0,1})
      , std::make_pair<int, std::vector<int>>(88,{8,8})
      , std::make_pair<int, std::vector<int>>(102,{2,0,1})
      , std::make_pair<int, std::vector<int>>(999,{9,9,9})
      , std::make_pair<int, std::vector<int>>(1234,{4,3,2,1})));

class TestPalindromeGenerate : public testing::TestWithParam<std::pair<int, bool>>{};

TEST_P(TestPalindromeGenerate, Digits)
{
   const auto [num, expected] = GetParam();
   const auto actual = digits::is_palindrome(num);
   EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
   TestPalindromeGenerateBasicInputs
   , TestPalindromeGenerate, ::testing::Values(
      std::make_pair<int, bool>(1,true)
      , std::make_pair<int, bool>(11,true)
      , std::make_pair<int, bool>(12,false)
      , std::make_pair<int, bool>(101,true)
      , std::make_pair<int, bool>(1221,true)
      , std::make_pair<int, bool>(1234,false)));

