#include "gtest/gtest.h"

#include <utility>

#include "../utils/primes.h"

class TestIsPrime : public testing::TestWithParam<std::pair<int, bool>>{};

TEST_P(TestIsPrime, FiboTraverse)
{
   const auto [num, expected] = GetParam();
   const auto actual = primes::is_prime(num);
   EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
   TestFiboGenerateBasicInputs
   , TestIsPrime, ::testing::Values(
      std::make_pair<int, int>(2,true)
         , std::make_pair<int, int>(2,true)
         , std::make_pair<int, int>(3,true)
         , std::make_pair<int, int>(4,false)
         , std::make_pair<int, int>(5,true)
         , std::make_pair<int, int>(6,false)
         , std::make_pair<int, int>(7,true)
         , std::make_pair<int, int>(8,false)
         , std::make_pair<int, int>(40,false)
         , std::make_pair<int, int>(41,true)
         , std::make_pair<int, int>(83,true)
         , std::make_pair<int, int>(85,false)
         , std::make_pair<int, int>(97,true)));