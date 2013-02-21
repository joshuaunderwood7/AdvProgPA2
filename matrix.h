#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "pa2functions.h"


template <typename T>
class matrix
{
  private:
    T** TheMatrix;
    size_t row_count, col_count;

  public:
    matrix();
    matrix(size_t rows, size_t columns);
    matrix(const matrix& toCopy);
    ~matrix(void);
    T getlocation(size_t row, size_t col) const;
    const size_t getDemRows(void) const {return row_count;};
    const size_t getDemCols(void) const {return col_count;};

    //unsigned int is used to disambiguate the matrixRow [] operator
    T* operator[](size_t x) { return TheMatrix[x];}

};


//------------------cut and put into matrix.tem----------

template <typename T>
std::ostream& operator << (std::ostream& out, const matrix<T>& obj)
{
    out < "inside << \n";
    out << obj.getDemRows() << "x" << obj.getDemCols() << std::endl;
    for(size_t i = 0; i < obj.getDemRows(); ++i)
    {
        for(size_t j = 0; j < obj.getDemCols(); ++j)
        {
            out << obj.getlocation(i,j) << " ";
        }
        out << std::endl;
    }
    return out;
}

template <typename T>
matrix<T> operator * (const matrix<T>&a, const matrix<T>& b)
{

  matrix<T> result = matrix<T>(a.getDemRows(), b.getDemCols());

  if(a.getDemCols() == b.getDemRows())
  {
    for(size_t i = 0; i < result.getDemRows(); ++i)
    {
      for(size_t j = 0; j < result.getDemCols(); ++j)
      {
        result[i][j] = T(0);
        for(size_t aj = 0; aj < a.getDemCols(); ++aj)
        {
          for(size_t bi = 0; bi < b.getDemRows(); ++bi)
          {
            result[i][j] += a.getlocation(i,aj) * b.getlocation(bi,j);
          }
        } 
      }
    }
    return result;
  }
  else
  { 
    std::cerr << "Matricies are not proper dimentions to multiply" << std::endl;
  }
  return matrix<T>(0,0);
}

template <typename T>
matrix<T>::matrix()
{
    row_count = 0;
    col_count = 0;
}

template <typename T>
matrix<T>::matrix(size_t rows, size_t columns)
{
    row_count = rows;
    col_count = columns;
    TheMatrix = new T*[rows];
    for(size_t i = 0; i < rows; ++i)
    {
       TheMatrix[i] = new T[columns];
    }
};

template <typename T>
matrix<T>::matrix(const matrix& toCopy)
{
    row_count = toCopy.getDemRows();
    col_count = toCopy.getDemCols();
    TheMatrix = new T*[row_count];
    for(size_t i = 0; i < row_count; ++i)
    {
       TheMatrix[i] = new T[col_count];
    }

    for(size_t i = 0; i < row_count; ++i)
    {
        for(size_t j = 0; j < col_count; ++j)
        {
            TheMatrix[i][j] = toCopy.getlocation(i,j);
        }
    }
};

template <typename T>
matrix<T>::~matrix(void)
{
//    std::cout << row_count << "x" << col_count << std::endl;
    for(size_t i = 0; i < row_count; ++i)
    {
//    std::cout << " deleting matrix row: " << i << std::endl;
       delete TheMatrix[i];
    }
//    std::cout << "Now deleting the pointer." << std::endl;
    delete TheMatrix;
//    underwood::ENTER_TO_CONTINUE();
};

template <typename T>
T matrix<T>::getlocation(size_t row, size_t col) const
{ return TheMatrix[row][col]; };



#endif
