#include "gtest/gtest.h"

#include <tuple>

#include "../utils/multiples.h"

using namespace multiples;

template<std::size_t N>
using ArrayI = std::array<int, N>;

TEST(TestMultiples, Basic1)
{
   EXPECT_TRUE(multiple_of_each(30, ArrayI<3>{2,3,5}));
}

TEST(TestMultiples, Basic2)
{
   EXPECT_FALSE(multiple_of_each(10, ArrayI<3>{2,3,5}));
}

TEST(TestMultiples, Basic3)
{
   EXPECT_TRUE(multiple_of_each(28, ArrayI<3>{2,4,7}));
}