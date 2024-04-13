#include "gtest/gtest.h"

#include "../utils/read_matrix.h"

TEST(TestReadMatrix, testReadGood)
{
   const char* str = R"(00 01 02
                        03 04 05
                        06 07 08)";

   const auto mat = io::read<int, 3, 3>(str);

   Matrix<int, 3, 3> expected(0, 1, 2,
                              3, 4, 5,
                              6, 7, 8);

   EXPECT_TRUE(expected == mat);
}

TEST(TestReadMatrix, testReadWithGarbage)
{
   const char* str = R"(00 01 02
                        03 xx 05
                        06 07 08)";

   const auto mat = io::read<int, 3, 3>(str);

   Matrix<int, 3, 3> expected(0, 1, 2,
                              3, 5, 6,
                              7, 8, 0);

   EXPECT_TRUE(expected == mat);
}

TEST(TestReadMatrix, testReadTooLong)
{
   const char* str = R"(00 01 02
                        03 04 05
                        06 07 08)";

   const auto mat = io::read<int, 2, 2>(str);

   Matrix<int, 2, 2> expected(0, 1,
                              2, 3);

   EXPECT_TRUE(expected == mat);
}