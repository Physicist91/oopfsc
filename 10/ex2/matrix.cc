#include "matrix.h"
#include<iomanip>
#include<iostream>
#include<cstdlib>

void Matrix::resize(int numRows_, int numCols_)
{
    entries.resize(numRows_);
    for (size_t i = 0; i < entries.size(); ++i)
        entries[i].resize(numCols_);
    numRows = numRows_;
    numCols = numCols_;
}

void Matrix::resize(int numRows_, int numCols_, double value)
{
    entries.resize(numRows_);
    for (size_t i = 0; i < entries.size(); ++i)
    {
        entries[i].resize(numCols_);
        for (size_t j = 0; j < entries[i].size(); ++j)
            entries[i][j] = value;
    }
    numRows = numRows_;
    numCols = numCols_;
}

double& Matrix::operator()(int i, int j)
{
    if (i < 0 || i >= numRows)
    {
        std::cerr << "Illegal row index " << i;
        std::cerr << " valid range is [0:" << numRows-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    if (j < 0 || j >= numCols)
    {
        std::cerr << "Illegal column index " << j;
        std::cerr << " valid range is [0:" << numCols-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i][j];
}

double Matrix::operator()(int i, int j) const
{
    if ( i < 0 || i >= numRows)
    {
        std::cerr << "Illegal row index " << i;
        std::cerr << " valid range is [0:" << numRows-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    if (j < 0 || j >= numCols)
    {
        std::cerr << "Illegal column index " << j;
        std::cerr << " valid range is [0:" << numCols-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i][j];
}

std::vector<double>& Matrix::operator[](int i)
{
    if (i < 0 || i >= numRows)
    {
        std::cerr << "Illegal row index " << i;
        std::cerr << " valid range is [0:" << numRows-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i];
}

const std::vector<double>& Matrix::operator[](int i) const
{
    if (i < 0 || i >= numRows)
    {
        std::cerr << "Illegal row index " << i;
        std::cerr << " valid range is [0:" << numRows-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i];
}

std::vector<double> Matrix::solve(std::vector<double> b) const
{
    std::vector<std::vector<double> > a(entries);
    for (int m = 0; m < numRows-1; ++m)
        for (int i = m+1; i < numRows; ++i)
        {
            double q = a[i][m]/a[m][m];
            a[i][m] = 0.;
            for (int j= m+1; j < numRows; ++j)
                a[i][j] = a[i][j] - q * a[m][j];
            b[i] -= q*b[m];
        }
    std::vector<double> x(b);
    x.back() /= a[numRows-1][numRows-1];
    for (int i = numRows-2; i >= 0; --i)
    {
        for (int j = i+1; j < numRows; ++j)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }
    return(x);
}

Matrix operator*(const Matrix& a, double x)
{
    Matrix output(a);
    output *= x;
    return output;
}

Matrix operator*(double x, const Matrix& a)
{
    Matrix output(a);
    output *= x;
    return output;
}

std::vector<double> operator*(const Matrix& a,
                              const std::vector<double>& x)
{
    if (x.size() != a.cols())
    {
        std::cerr << "Dimensions of vector " << x.size();
        std::cerr << " and matrix " << a.cols() << " do not match!";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    std::vector<double> y(a.rows());
    for (int i = 0; i < a.rows(); ++i)
    {
        y[i] = 0.;
        for (int j = 0; j < a.cols(); ++j)
            y[i] += a[i][j] * x[j];
    }
    return y;
}

Matrix operator+(const Matrix& a, const Matrix& b)
{
    Matrix output(a);
    output += b;
    return output;
}
