/* MATRIX ITERATOR
The problem set requires nested classes, therefore we implement all the new CLASSES
as nested classes of Matrix. There are three new classes:
1. RowIterator
2. ColIterator
3. Row
These classes has to be forward declared, otherwise the compiler complains.
*/

#include<vector>
#include<iostream>
#include<iomanip>

class Matrix
{

public:
  /*
  Forward declaration of the nested CLASSES
  */
  class RowIterator;
  class ColIterator;
  class Row;

  /*
  CLASS ROW.
  The matrix is now a container of Rows, which is a container of row entries.
  It needs to have:
  begin(), end() -- required from the problem set
  setRow() -- required for RowIterator to work
  */
  class Row{
  private:
    Matrix &myMatrix;
    unsigned int count;

  public:

    //Defining the constructor
    Row(Matrix& m, unsigned int cnt): myMatrix(m),count(cnt){}

    void setRow(unsigned int cnt){
        count = cnt;
    }

    //point to first entry
    ColIterator begin(){
      return ColIterator(myMatrix, count, 0);
    }

    //point to the position after the last column
    ColIterator end(){
      return ColIterator(myMatrix, count, myMatrix.cols());
    }

  };

  /* CLASS RowIterator
  Note: this is a forward iterator
  */
  class RowIterator{
  private:
    Matrix &myMatrix; //we want a reference to the actual matrix, not a copy.
    unsigned int count; //using unsigned because the interface row() defines so and it makes sense as iterator >=0.
    Row myRow;

  public:

    //Defining the constructor
    RowIterator(Matrix& m, unsigned int cnt): myMatrix(m), count(cnt), myRow(m, cnt){}

    //move to the next row
    RowIterator& operator++(){
      count++;
      myRow.setRow(count);
      return *this;
    }

    //comparison of iterators
    bool operator==(const RowIterator &ri) const{
      return ri.count == count;
    }

    //also define an inequality operator, so that the iterator can be used in the "standard" way
    bool operator!=(const RowIterator &ri) const{
      return ! operator==(ri);
    }

    //access to current row (output iterator?)
    Row& operator*(){
      return myRow;
    }

    //access to current row (input iterator?)
    const Row& operator*() const{
      return myRow;
    }

    //number of current row
    unsigned int row() const {
      return count;
    }

  };

  /* CLASS ColIterator
  This is the column iterator (also a forward iterator)
  */
  class ColIterator{
  private:
    Matrix &myMatrix; //we want a reference to the actual matrix, not a copy.
    unsigned int rowCount;
    unsigned int colCount;

  public:

    //Defining the Constructor
    ColIterator(Matrix& m, unsigned int rcnt, unsigned int ccnt):myMatrix(m),rowCount(rcnt),colCount(ccnt){}

    //move to the next entry
    ColIterator& operator++(){
      colCount++;
      return *this;
    }

    //comparison of iterators
    bool operator==(const ColIterator &ci) const{
      return ci.rowCount == rowCount && ci.colCount == colCount;
    }

    //also define an inequality operator
    bool operator!=(const ColIterator &ci) const{
      return ! operator==(ci);
    }

    //access to current entry (output iterator?)
    double& operator*() {
      return myMatrix(rowCount, colCount);
    }

    //access to current entry (input iterator?)
    const double& operator*() const{
      return myMatrix(rowCount, colCount);
    }

    //number of current entry
    unsigned int col() const {
      return colCount;
    }
  };


  /*
  ADDITIONAL METHODS FOR THE MATRIX
  namely, the methods begin() and end()
  */

  //point to the first row
  RowIterator begin() {
    return RowIterator(*this, 0);
  }

  //point to the position after the last row
  RowIterator end() {
    return RowIterator(*this, rows());
  }


  /*
  RE-IMPLEMENTED METHODS that can use the iterator concept
  */
  void print()
  {
      std::cout << "(" << numRows << "x";
      std::cout << numCols << ") matrix:" << std::endl;

      for(RowIterator i = (*this).begin(); i!=(*this).end(); ++i){ //use the matrix methods
        std::cout << std::setprecision(3);
        for(ColIterator j = (*i).begin(); j!=(*i).end();++j) //use the methods from Class Row
          std::cout << std::setw(5) << *j << " ";
      }
      //original method is commented for comparison
      // for (int i = 0; i < numRows; ++i)
      // {
      //     std::cout << std::setprecision(3);
      //     for (int j = 0; j < numCols; ++j)
      //         std::cout << std::setw(5) << entries[i][j] << " ";
      //     std::cout << std::endl;
      // }
      std::cout << std::endl;
  }

  Matrix& operator*=(double x)
  {
      for(RowIterator i = (*this).begin(); i!=(*this).end(); ++i){
        for(ColIterator j = (*i).begin(); j!= (*i).end(); ++j)
          *j *= x;
      }
      //original method is commented for comparison
      // for (int i = 0; i < numRows; ++i)
      //     for (int j = 0; j < numCols; ++j)
      //         entries[i][j] *= x;
      return *this;
  }

  Matrix& operator+=(const Matrix& x)
  {

      if (x.numRows != numRows || x.numCols != numCols)
      {
          std::cerr << "Dimensions of matrix a (" << numRows
                    << "x" << numCols << ") and matrix x ("
                    << x.numRows << "x" << x.numCols << ") do not match!";
          exit(EXIT_FAILURE);
      }
      for(RowIterator i = (*this).begin(); i!=(*this).end(); ++i)
        for(ColIterator j = (*i). begin(); j!=(*i).end(); ++j)
          *j += x(i.row(),j.col());

      //original method is commented for comparison
      // for (int i = 0; i < numRows; ++i)
      //     for (int j = 0;j < numCols; ++j)
      //         entries[i][j] += x[i][j];
      return *this;
  }



  /*
  The original methods and definitions from sheet8
  */
private:
  std::vector<std::vector<double> > entries;
  int numRows = 0;
  int numCols = 0;

public:

    void resize(int numRows_, int numCols_);
    void resize(int numRows_, int numCols_, double value);
    // access elements
    double& operator()(int i, int j);
    double  operator()(int i, int j) const;
    std::vector<double>& operator[](int i);
    const std::vector<double>& operator[](int i) const;
    // arithmetic functions
    std::vector<double> solve(std::vector<double> b) const;
    // output
    int rows() const
    {
        return numRows;
    }
    int cols() const
    {
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

    Matrix(int numRows_, int numCols_, double value)
    {
        resize(numRows_,numCols_,value);
    };

    Matrix(std::vector<std::vector<double> > a)
    {
        entries = a;
        numRows = a.size();
        if (numRows > 0)
            numCols = a[0].size();
        else
            numCols = 0;
    }

    Matrix(const Matrix& b)
    {
        entries = b.entries;
        numRows = b.numRows;
        numCols = b.numCols;
    }

};

std::vector<double> operator*(const Matrix& a,
                              const std::vector<double>& x);
Matrix operator*(const Matrix& a, double x);
Matrix operator*(double x, const Matrix& a);
Matrix operator+(const Matrix& a, const Matrix& b);
