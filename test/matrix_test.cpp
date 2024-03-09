#include "gtest/gtest.h"

#include "../utils/Matrix.h"

#include <vector>

namespace sr = std::ranges;

// matrix multiplications
TEST(TestMatrix, testInitializerList)
{
   const auto il = {0, 1, 2, 3, 4, 5};
   const Matrix<int, 2, 3> mat = il;
   const std::vector<int> actual = il;
   EXPECT_TRUE(sr::equal(mat, actual));
}

TEST(TestMatrix, testRowAndCol)
{
   constexpr Matrix<int, 2, 3> x(0, 3, 5, 5, 5, 2);
   constexpr Matrix<int, 3, 2> y(3, 4, 3, -2, 4, -2);

   EXPECT_EQ(x.row(), 2);
   EXPECT_EQ(x.col(), 3);
   EXPECT_EQ(y.row(), 3);
   EXPECT_EQ(y.col(), 2);
}

TEST(TestMatrix, testDim)
{
   constexpr Matrix<int, 2, 3> mat(0, 3, 5, 5, 5, 2);
   const auto dim = mat.dim();

   EXPECT_EQ(dim.row_, 2);
   EXPECT_EQ(dim.col_, 3);
}

TEST(TestMatrix, testSize)
{
   constexpr Matrix<int, 2, 3> mat{};
   EXPECT_EQ(mat.size(), 6);
}

TEST(TestMatrix, testAt)
{
   const std::initializer_list<int> il = {0, 3, 5,
                                          5, 5, 2};

   Matrix<int, 2, 3> mat{il};
   auto& last_elem = mat.at(1, 2);
   last_elem = 42;
   EXPECT_EQ(mat.at(1, 2), 42);

   const Matrix c_mat = mat;
   EXPECT_EQ(c_mat.at(1, 2), 42);
}

TEST(TestMatrix, testSwapRows)
{
   const std::initializer_list<int> il = {0, 1, 2,
                                          3, 4, 5,
                                          6, 7, 8,
                                          9, 10, 11};
   Matrix<int, 4, 3> mat(il);
   mat.swap_rows(1, 3);

   Matrix<int, 4, 3> expected(0, 1, 2,
                              9, 10, 11,
                              6, 7, 8,
                              3, 4, 5);

   EXPECT_TRUE(sr::equal(mat, expected));
}

TEST(TestMatrix, testSwapColumns)
{
   const std::initializer_list<int> il = {0, 1, 2,
                                          3, 4, 5,
                                          6, 7, 8,
                                          9, 10, 11};
   Matrix<int, 4, 3> mat(il);
   mat.swap_cols(0, 2);

   Matrix<int, 4, 3> expected(2, 1, 0,
                              5, 4, 3,
                              8, 7, 6,
                              11, 10, 9);

   EXPECT_TRUE(sr::equal(mat, expected));
}

TEST(TestMatrix, testTransposeSquared)
{
   Matrix<int, 3, 3> mat(0, 1, 2,
                        3, 4, 5,
                        6, 7, 8);

   mat.transpose_squared();

   const Matrix<int, 3, 3> expected(0, 3, 6,
                                    1, 4, 7,
                                    2, 5, 8);

   EXPECT_TRUE(sr::equal(mat, expected));
}

TEST(TestMatrix, testTranspose)
{
   Matrix<int, 4, 3> mat(0, 1, 2,
                         3, 4, 5,
                         6, 7, 8,
                         9, 10, 11);

   const auto transpose = mat.transpose();

   const Matrix<int, 3, 4> expected(0, 3, 6, 9,
                                    1, 4, 7, 10,
                                    2, 5, 8, 11);

   EXPECT_TRUE(sr::equal(transpose, expected));
}

TEST(TestMatrix, testFill) 
{
   Matrix<int, 3, 3> nums{};
   nums.fill(1);
   for (auto i : nums) {
      EXPECT_EQ(i, 1);
   }
}

// matrix multiplications
TEST(TestMatrix, testNonSquareMultiplicatiion) 
{
   constexpr Matrix<int, 2, 3> x(0, 3, 5, 5, 5, 2);
   constexpr Matrix<int, 3, 2> y(3, 4, 3, -2, 4, -2);
   constexpr auto actual = (x * y);

   constexpr Matrix<int, 2, 2> expected(29, -16, 38, 6);
   EXPECT_EQ(expected, actual);
}

TEST(TestMatrix, testSquareMultiplication)
{
   constexpr Matrix<int, 2, 2> k(0, 3, 2, 5);
   constexpr Matrix<int, 2, 2> j(3, 4, 5, 6);
   constexpr auto actual = (k * j);

   constexpr Matrix<int, 2, 2> expected(15, 18, 31, 38);
   EXPECT_EQ(expected, actual);
}

TEST(TestMatrix, testSquareTimesNonSquare)
{
   constexpr Matrix<int, 2, 2> a(1, 2, 3, 4);
   constexpr Matrix<int, 2, 4> b(3, 5, 2, 3, 4, 5, 3, 2);
   constexpr auto actual = (a * b);

   constexpr Matrix<int, 2, 4> expected(11, 15, 8, 7, 25, 35, 18, 17);
   EXPECT_EQ(expected, actual);
}

TEST(TestMatrix, testMatrixTimesScalar)
{
   Matrix<int, 2, 2> arr(2, 3, 4, 5);
   const auto actual = (arr * 2);

   constexpr Matrix<int, 2, 2> expected(4, 6, 8, 10);
   EXPECT_EQ(expected, actual);
}

TEST(TestMatrix, testMatrixAddition)
{
   constexpr Matrix<int, 3, 3> a(3, 4, 5, 5, 4, 3, 3, 3, 7);

   constexpr Matrix<int, 3, 3> b(3, 4, 5, 5, 4, 3, 3, 3, 7);

   constexpr auto actual = (a + b);
   constexpr Matrix<int, 3, 3> expected(6, 8, 10, 10, 8, 6, 6, 6, 14);
   EXPECT_EQ(expected, actual);
}

TEST(TestMatrix, testMatrixSubtraction)
{
   constexpr Matrix<int, 3, 3> a(3, 4, 5, 5, 4, 3, 3, 3, 7);

   constexpr Matrix<int, 3, 3> b(3, 4, 5, 5, 4, 3, 3, 3, 7);
   constexpr auto actual = (a - b);
   constexpr Matrix<int, 3, 3> expected(0, 0, 0, 0, 0, 0, 0, 0, 0);
   EXPECT_EQ(expected, actual);
}

TEST(TestMatrix, testMatrixAdditionWithScalar)
{
   constexpr Matrix<int, 3, 3> a(3, 4, 5, 5, 4, 3, 3, 3, 7);

   constexpr auto actual = (a + 2);
   constexpr Matrix<int, 3, 3> expected(5, 6, 7, 7, 6, 5, 5, 5, 9);
   EXPECT_EQ(expected, actual);
}

TEST(TestMatrix, testMatrixSubtractionWithScalar)
{
   constexpr Matrix<int, 3, 3> a(3, 4, 5, 5, 4, 3, 3, 3, 7);

   constexpr auto actual = (a - 2);
   constexpr Matrix<int, 3, 3> expected(1, 2, 3, 3, 2, 1, 1, 1, 5);
   EXPECT_EQ(expected, actual);
}





