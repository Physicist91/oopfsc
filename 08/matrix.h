#ifndef MATRIX_H
#define MATRIX_H value

#include <iostream>
#include <iomanip>
#include <vector>

template <class T>
class Matrix {

public:
  void resize(int numRows_, int numCols_)
  {
    entries.resize(numRows_);
    for (size_t i = 0; i < entries.size(); ++i)
      entries[i].resize(numCols_);
    numRows = numRows_;
    numCols = numCols_;
  }

  void resize(int numRows_, int numCols_, T value)
  {
    entries.resize(numRows_);
    for (size_t i = 0; i < entries.size(); ++i) {
      entries[i].resize(numCols_);
      for (size_t j = 0; j < entries[i].size(); ++j)
        entries[i][j] = value;
    }
    numRows = numRows_;
    numCols = numCols_;
  }

  // access elements
  T& operator()(int i, int j)
  {
    if (i < 0 || i >= numRows) {
      std::cerr << "Illegal row index " << i;
      std::cerr << " valid range is [0:" << numRows-1 << "]";
      std::cerr << std::endl;
      exit(EXIT_FAILURE);
    }
    if (j < 0 || j >= numCols) {
      std::cerr << "Illegal column index " << j;
      std::cerr << " valid range is [0:" << numCols-1 << "]";
      std::cerr << std::endl;
      exit(EXIT_FAILURE);
    }
    return entries[i][j];
  }
  
  T operator()(int i, int j) const
  {
    if ( i < 0 || i >= numRows) {
      std::cerr << "Illegal row index " << i;
      std::cerr << " valid range is [0:" << numRows-1 << "]";
      std::cerr << std::endl;
      exit(EXIT_FAILURE);
    }
    if (j < 0 || j >= numCols) {
      std::cerr << "Illegal column index " << j;
      std::cerr << " valid range is [0:" << numCols-1 << "]";
      std::cerr << std::endl;
      exit(EXIT_FAILURE);
    }
    return entries[i][j];
  }

  std::vector<T>& operator[](int i)
  {
    if (i < 0 || i >= numRows) {
      std::cerr << "Illegal row index " << i;
      std::cerr << " valid range is [0:" << numRows-1 << "]";
      std::cerr << std::endl;
      exit(EXIT_FAILURE);
    }
    return entries[i];
  }

  const std::vector<T>& operator[](int i) const
  {
    if (i < 0 || i >= numRows) {
      std::cerr << "Illegal row index " << i;
      std::cerr << " valid range is [0:" << numRows-1 << "]";
      std::cerr << std::endl;
      exit(EXIT_FAILURE);
    }
    return entries[i];
  }

  // arithmetic functions
  Matrix<T>& operator*=(T x)
  {
    for (int i = 0; i < numRows; ++i)
      for (int j = 0; j < numCols; ++j)
        entries[i][j] *= x;
    return *this;
  }

  Matrix<T>& operator+=(const Matrix<T>& x)
  {
    if (x.numRows != numRows || x.numCols != numCols) {
      std::cerr << "Dimensions of matrix a (" << numRows
            << "x" << numCols << ") and matrix x (" 
            << x.numRows << "x" << x.numCols << ") do not match!";
      exit(EXIT_FAILURE);
    }
    for (int i = 0; i < numRows; ++i)
      for (int j = 0;j < numCols; ++j)
        entries[i][j] += x[i][j];
    return *this;
  }

  std::vector<T> solve(std::vector<T> b) const
  {
    std::vector<std::vector<T> > a(entries);
    for (int m = 0; m < numRows-1; ++m)
      for (int i = m+1; i < numRows; ++i) {
        auto q = a[i][m]/a[m][m];
        a[i][m] = 0.;
        for (int j= m+1; j < numRows; ++j)
          a[i][j] = a[i][j] - q * a[m][j];
        b[i] -= q*b[m];
      }

    std::vector<T> x(b);
    x.back() /= a[numRows-1][numRows-1];
    for (int i = numRows-2; i >= 0; --i) {
      for (int j = i+1; j < numRows; ++j)
        x[i] -= a[i][j] * x[j];
      x[i] /= a[i][i];
    }

    return x;
  }

  // output
  void print() const
  {
    std::cout << "(" << numRows << "x";
    std::cout << numCols << ") matrix:" << std::endl;
    for (int i = 0; i < numRows; ++i) {
      std::cout << std::setprecision(3);
      for (int j = 0; j < numCols; ++j)
        std::cout << std::setw(5) << entries[i][j] << " ";
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  int rows() const {
    return numRows;
  }

  int cols() const {
    return numCols;
  }

  Matrix(int numRows_, int numCols_) :
      entries(numRows_), numRows(numRows_), numCols(numCols_)
  {
    for (int i = 0; i < numRows_; ++i)
      entries[i].resize(numCols_);
  };

  Matrix(int dim) : Matrix(dim,dim)
  {};

  Matrix(int numRows_, int numCols_, T value) {
    resize(numRows_,numCols_,value);
  };

  Matrix(std::vector<std::vector<T>> a) {
    entries = a;
    numRows = a.size();
    if (numRows > 0)
      numCols = a[0].size();
    else
      numCols = 0;
  }

  Matrix(const Matrix<T>& b) {
    entries = b.entries;
    numRows = b.numRows;
    numCols = b.numCols;
  }

private:
  std::vector<std::vector<T> > entries;
  int numRows = 0;
  int numCols = 0;
};

template <class T>
Matrix<T> operator*(const Matrix<T>& a, T x) {
  Matrix<T> output(a);
  output *= x;
  return output;
}

template <class T>
Matrix<T> operator*(T x, const Matrix<T>& a) {
  Matrix<T> output(a);
  output *= x;
  return output;
}

template <class T>
std::vector<T> operator*(const Matrix<T>& a, const std::vector<T>& x) {
  if (x.size() != a.cols()) {
    std::cerr << "Dimensions of vector " << x.size();
    std::cerr << " and matrix " << a.cols() << " do not match!";
    std::cerr << std::endl;
    exit(EXIT_FAILURE);
  }
  std::vector<T> y(a.rows());
  for (int i = 0; i < a.rows(); ++i) {
    y[i] = 0.;
    for (int j = 0; j < a.cols(); ++j)
      y[i] += a[i][j] * x[j];
  }
  return y;
}

template <class T>
Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b) {
  Matrix<T> output(a);
  output += b;
  return output;
}

template<class T1, class T2>
struct TypePromotion
{
  using PromotedType = decltype(std::declval<T1>() + std::declval<T2>());
};

template<typename T1, typename T2>
struct TypePromotion<std::vector<T1>,T2> 
{
  using PromotedType = typename TypePromotion<T1,T2>::PromotedType;
};

template<typename T1, typename T2>
struct TypePromotion<T1,std::vector<T2>> 
{
  using PromotedType = typename TypePromotion<T1,T2>::PromotedType;
};

template <class T1, class T2>
Matrix<typename TypePromotion<T1,T2>::PromotedType> operator+(const Matrix<T1>& a, const Matrix<T2>& b) {
  
  if (a.rows() != b.rows() || a.cols() != b.cols()) {
    std::cerr << "Dimensions of matrix a (" << a.rows()
          << "x" << a.cols() << ") and matrix x (" 
          << b.rows() << "x" << b.cols() << ") do not match!\n";
    exit(EXIT_FAILURE);
  }

  using PromotedType = typename TypePromotion<T1,T2>::PromotedType;

  Matrix<PromotedType> output(a.rows(),a.cols());
  for (int i = 0; i < a.rows(); ++i)
    for (int j = 0; j < a.cols(); ++j)
      output[i][j] = a[i][j] + b[i][j];

  return output;
}

template <class T1, class T2>
std::vector<typename TypePromotion<T1,T2>::PromotedType> operator*(const Matrix<T1>& a, const std::vector<T2>& x) {
  if (x.size() != a.cols()) {
    std::cerr << "Dimensions of vector " << x.size();
    std::cerr << " and matrix " << a.cols() << " do not match!";
    std::cerr << std::endl;
    exit(EXIT_FAILURE);
  }

  using PromotedType = typename TypePromotion<T1,T2>::PromotedType;

  std::vector<PromotedType> y(a.rows());
  for (int i = 0; i < a.rows(); ++i) {
    y[i] = PromotedType(0);
    for (int j = 0; j < a.cols(); ++j)
      y[i] += a[i][j] * x[j];
  }
  return y;
}

template <class T1, class T2>
Matrix<typename TypePromotion<T1,T2>::PromotedType> operator*(const Matrix<T1>& a, T2 x) {

  using PromotedType = typename TypePromotion<T1,T2>::PromotedType;

  Matrix<PromotedType> output(a.rows(),a.cols());

  for (int i = 0; i < a.rows(); ++i)
    for (int j = 0; j < a.cols(); ++j)
      output[i][j] = a[i][j] * x;

  return output;
}

template <class T1, class T2>
Matrix<typename TypePromotion<T1,T2>::PromotedType> operator*(T1 x, const Matrix<T2>& a) {
  return a*x;
}

#endif // MATRIX_H