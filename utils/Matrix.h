#ifndef PROJECT_EULER_SOLUTIONS_MATRIX_H
#define PROJECT_EULER_SOLUTIONS_MATRIX_H

#include <algorithm> // std::swap
#include <array>
#include <memory>
#include <cassert>
#include <initializer_list>
#include <iomanip> // std::setw
#include <iterator>
#include <ostream>
#include <type_traits>

struct Dimensions
{
   std::size_t row_{};
   std::size_t col_{};
};

template <class Ty, std::size_t ROW, std::size_t COL>
   requires(!std::is_class_v<Ty>)
class Matrix
{
public:
   using value_type = Ty;
   using pointer = value_type*;
   using const_pointer = const value_type*;
   using reference = value_type&;
   using const_reference = const value_type&;
   using iterator = value_type*;
   using const_iterator = const value_type*;
   using size_type = std::size_t;
   using reverse_iterator = std::reverse_iterator<iterator>;
   using const_reverse_iterator = std::reverse_iterator<const_iterator>;
   static_assert(ROW > 0UL && COL > 0UL, "ROW and COL must both be positive");

private:
   std::array<value_type, (ROW * COL)> data_{};

public:
   constexpr Matrix() noexcept = default;

   constexpr Matrix(const Matrix& copy) noexcept
   {
      data_ = copy.data_;
   }

   constexpr Matrix(Matrix&& move) noexcept
   {
      data_ = std::move(move.data_);
      move.data_ = {};
   }

   constexpr Matrix(std::initializer_list<value_type> init)
      noexcept(std::is_nothrow_copy_constructible_v<value_type >)
   {
      std::ranges::uninitialized_copy(init, data_);
   }

   template <class... T>
   explicit consteval Matrix(const T... args)
   {
      if constexpr(sizeof...(T) == 1)
      {
         fill(std::forward<value_type>(args)...);
      }
      else
      {
         data_ = {std::move(args)...};
      }
   }

   constexpr ~Matrix() = default;

   ///
   [[nodiscard]] constexpr const_iterator begin() const noexcept
   {
      return data_.begin();
   }
   [[nodiscard]] constexpr const_iterator end() const noexcept
   {
      return data_.end();
   }
   [[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept
   {
      return data_.rbegin();
   }
   [[nodiscard]] constexpr const_reverse_iterator rend() const noexcept
   {
      return data_.rend();
   }
   ///
   [[nodiscard]] constexpr iterator begin() noexcept
   {
      return data_.begin();
   }
   [[nodiscard]] constexpr iterator end() noexcept
   {
      return data_.end();
   }
   [[nodiscard]] constexpr reverse_iterator rbegin() noexcept
   {
      return data_.rbegin();
   }
   [[nodiscard]] constexpr reverse_iterator rend() noexcept
   {
      return data_.rend();
   }

   /// methods:

   [[nodiscard]] constexpr auto col() const -> size_type
   {
      return COL;
   }

   [[nodiscard]] constexpr auto row() const -> size_type
   {
      return ROW;
   }

   /// \get: row and column
   [[nodiscard]] constexpr auto dim() const -> Dimensions
   {
      return {ROW, COL};
   }

   ///
   /// \return Total number of elements
   [[nodiscard]] constexpr auto size() const -> size_type
   {
      return ROW * COL;
   }

   /// \brief get/modify element at given row-col
   /// \tparam row row-index
   /// \tparam col column-index
   /// \return reference
   template <const size_type row, size_type col>
   [[nodiscard]] constexpr auto at() -> reference
   {
      static_assert((row >= 0 && col >= 0) && (row < ROW && col < COL));
      return data_[(row * COL) + col];
   }

   /// \brief get element at given row-col
   /// \tparam row row-index
   /// \tparam col column-index
   /// \return value_type
   template <const size_type row, size_type col>
   [[nodiscard]] constexpr auto at() const -> value_type
   {
      static_assert((row >= 0 && col >= 0) && (row < ROW && col < COL));
      return data_[(row * COL) + col];
   }

   /// \brief get/modify element at given row-col
   /// \tparam row row-index
   /// \tparam col column-index
   /// \return reference
   [[nodiscard]] constexpr auto at(const size_type& row, const size_type& col) -> reference
   {
      return data_[(row * COL) + col];
   }

   /// \brief get element at given row-col
   /// \tparam row row-index
   /// \tparam col column-index
   /// \return value_type
   [[nodiscard]] constexpr auto at(const size_type& row, const size_type& col) const -> value_type
   {
      return data_[(row * COL) + col];
   }

   /// \brief swaps given rows
   /// \param start which row
   /// \param with change with row
   constexpr auto swap_rows(const size_type& start, const size_type& with) -> void
   {
      for(size_type i = 0; i < COL; ++i)
      {
         std::swap(at(start, i), at(with, i));
      }
   }

   /// \brief swaps given columns
   /// \param start which column
   /// \param with change with column
   constexpr auto swap_cols(const size_type& start, const size_type& with) -> void
   {
      for(size_type i = 0; i < ROW; ++i)
      {
         std::swap(at(i, start), at(i, with));
      }
   }

   /// \brief changes this into its transpose
   constexpr auto transpose_squared() -> void
   {
      static_assert(ROW == COL, "transpose_squared requires a square matrix");

      for(size_type i{0}; i < ROW - 1; ++i)
      {
         for(size_type j{i + 1}; j < COL; ++j)
         {
            std::swap(at(i, j), at(j, i));
         }
      }
   }

   ///
   /// \return transposed matrix
   [[nodiscard]] constexpr auto transpose() const
   {
      Matrix<value_type, COL, ROW> temp{};
      for(size_type i{}; i < ROW; ++i)
      {
         for(size_type j{}; j < COL; ++j)
         {
            temp.at(j, i) = at(i, j);
         }
      }

      return temp;
   }

   /// \brief fill matrix with given value
   constexpr auto fill(value_type&& value) -> void
   {
      std::ranges::fill(data_, value);
   }

   /// matrix operators
   
   constexpr Matrix& operator=(const Matrix& other) noexcept
   {
      if(this == &other)
      {
         return *this;
      }
      data_ = other.data_;
      return *this;
   }

   constexpr Matrix& operator=(Matrix&& other) noexcept
   {
      if(this == &other)
      {
         return *this;
      }
      data_ = std::move(other.data_);
      other.data_ = {};
      
      return *this;
   }

   constexpr Matrix& operator+=(const Matrix& rhs) noexcept
   {
      for(size_type j{}; const auto& i : rhs)
      {
         data_[j] += i;
         ++j;
      }
      
      return *this;
   }

   constexpr friend Matrix operator+(Matrix lhs, const Matrix& rhs) noexcept
   {
      lhs += rhs;
      return lhs;
   }

   constexpr Matrix& operator+=(const value_type scalar) noexcept
   {
      for(auto&& i : *this)
      {
         i += scalar;
      }
      
      return *this;
   }
   
   constexpr friend Matrix operator+(Matrix lhs, const value_type scalar) noexcept
   {
      lhs += scalar;
      return lhs;
   }
   
   [[nodiscard]] constexpr Matrix& operator*(value_type val) noexcept
   {
      for(auto&& i : *this)
      {
         i *= val;
      }
      
      return *this;
   }

   /// \brief multiplies two matrices
   /// \pre `col` of A must be equal to `row` B
   [[nodiscard]] constexpr Matrix operator*(const Matrix& rhs) noexcept
   {
      if constexpr(ROW == 1UL)
      {
         for(size_type j{}; const auto& i : rhs)
         {
            data_[j] *= i;
            ++j;
         }
         return *this;
      }
      Matrix<value_type, ROW, COL> temp{};
      for(size_type i{}; i < ROW; ++i)
      {
         for(size_type k{}; k < rhs.row(); ++k)
         {
            for(size_type j{}; j < COL; ++j)
            {
               temp.at(i, j) += (at(i, k) * rhs.at(k, j));
            }
         }
      }
      
      return temp;
   }

   /// \brief multiplies two matrices (A * B)
   /// `col` of A must be equal to `row` B
   template <const size_type L>
   [[nodiscard]] constexpr Matrix<value_type, ROW, L>
   operator*(const Matrix<value_type, COL, L>& rhs) const noexcept
   {
      Matrix<value_type, ROW, L> temp{};
      for(size_type i{}; i < ROW; ++i)
      {
         for(size_type k{}; k < rhs.row(); ++k)
         {
            for(size_type j{}; j < L; ++j)
            {
               temp.at(i, j) += (at(i, k) * rhs.at(k, j));
            }
         }
      }
      return temp;
   }

   constexpr Matrix& operator-=(const Matrix& rhs) noexcept
   {
      for(size_type j{}; const auto& i : rhs)
      {
         data_[j] -= i;
         ++j;
      }
      return *this;
   }

   /// \brief subtract a matrix
   constexpr friend Matrix operator-(Matrix lhs, const Matrix& rhs) noexcept
   {
      lhs -= rhs;
      return lhs;
   }

   constexpr Matrix& operator-=(const value_type scalar) noexcept
   {
      for(auto&& i : *this)
      {
         i -= scalar;
      }
      return *this;
   }

   /// \brief adds a matrix containers with a scalar
   /// \return matrix
   constexpr friend Matrix operator-(Matrix lhs, const value_type scalar) noexcept
   {
      lhs -= scalar;
      return lhs;
   }

   /// \brief get/modify an element in a given index
   /// \brief Subscript access to the data contained in the %matrix
   /// \param i index of the element for which data should be accessed.
   /// \return value_type&
   constexpr value_type& operator[](const size_type i) noexcept
   {
      return data_[i];
   }

   /// \brief access an element at a given linear index
   /// \param i linear index of the element to be accessed.
   /// \return value at \p i
   constexpr value_type operator[](const size_type i) const noexcept
   {
      return data_[i];
   }

   constexpr bool operator!=(const Matrix& rhs) const noexcept
   {
      return data_ != rhs.data_;
   }
   constexpr bool operator==(const Matrix& rhs) const noexcept
   {
      return data_ == rhs.data_;
   }

   /// \brief prints matrix
   constexpr friend std::ostream& operator<<(std::ostream& os, const Matrix& mat)
   {
      for(size_type count{}; auto&& i : mat)
      {
         if(count % COL == 0)
         {
            os << '\n';
            count = 0;
         }
         if constexpr(std::is_floating_point_v<value_type>)
         {
            os << std::setw(7);
         }
         else
         {
            os << i << ' ';
         }
         ++count;
      }
      return os;
   }
}; // end of class Matrix

#endif //PROJECT_EULER_SOLUTIONS_MATRIX_H
