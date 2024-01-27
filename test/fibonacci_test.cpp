#include "gtest/gtest.h"

#include <utility>

#include "../utils/fibonacci.h"

class TestFiboGenerate : public testing::TestWithParam<std::pair<int, int>>{};

TEST_P(TestFiboGenerate, FiboTraverse)
{
   const auto [idx, expected] = GetParam();
   const auto actual = fibonacci::fibo_traverse(idx);
   EXPECT_EQ(actual, expected);
}

TEST_P(TestFiboGenerate, FiboBinet)
{
   const auto [idx, expected] = GetParam();
   const auto actual = fibonacci::fibo_binet(idx);
   EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
   TestFiboGenerateBasicInputs
   , TestFiboGenerate, ::testing::Values(
      std::make_pair<int, int>(1,1)
      , std::make_pair<int, int>(2,2)
      , std::make_pair<int, int>(3,3)
      , std::make_pair<int, int>(4,5)
      , std::make_pair<int, int>(5,8)
      , std::make_pair<int, int>(6,13)
      , std::make_pair<int, int>(7,21)
      , std::make_pair<int, int>(8,34)));
