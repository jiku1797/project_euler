#include "gtest/gtest.h"

#include <utility>
#include <vector>

#include "../utils/digits.h"

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
      std::make_pair<int, std::vector<int>>(1,{1})
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

class TestNumDigitsGenerate : public testing::TestWithParam<std::pair<int, int>>{};

TEST_P(TestNumDigitsGenerate, NumDigits)
{
   const auto [num, expected] = GetParam();
   const auto actual = digits::num_digits(num);
   EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
   TestNumDigitsGenerateBasicInputs
   , TestNumDigitsGenerate, ::testing::Values(
      std::make_pair<int, int>(1, 1)
         , std::make_pair<int, int>(9, 1)
         , std::make_pair<int, int>(10, 2)
         , std::make_pair<int, int>(123, 3)
         , std::make_pair<int, int>(1234, 4)
         , std::make_pair<int, int>(99999, 5)
         , std::make_pair<int, int>(100000, 6)));

