#include "gtest/gtest.h"

#include "../utils/read_vector_of_vectors.h"

using result_t = std::vector<std::vector<int>>;

using namespace io::read_vector_of_vectors;

TEST(TestReadVectorOfVectors, testReadTriangular)
{
   const char* str = R"(1
                        2 3
                        4 5 6)";

   const auto res = read(str);
   result_t expected = {{1}, {2, 3}, {4, 5, 6}};

   EXPECT_TRUE(expected == res);
}

TEST(TestReadVectorOfVectors, testReadWithExtraWhitespace)
{
   const char* str = R"(1  2   3
                        4 5
                        6  )";

   const auto res = read(str);
   result_t expected = {{1, 2, 3}, {4, 5}, {6}};

   EXPECT_TRUE(expected == res);
}

