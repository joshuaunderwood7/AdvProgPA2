#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "pa2functions.h"


template <typename T>
class matrix
{
  private:
    T** TheMatrix;
    size_t row_count, col_count;

  public:
    matrix();
    matrix(std::ifstream& filestr);
    matrix(size_t rows, size_t columns);
    matrix(const matrix& toCopy);
    ~matrix(void);
    T getlocation(size_t row, size_t col) const;
    const size_t getDemRows(void) const {return row_count;};
    const size_t getDemCols(void) const {return col_count;};
    bool setDemRows(size_t rows) {row_count = rows;}
    bool setDemCols(size_t cols) {col_count = cols;}

    //unsigned int is used to disambiguate the matrixRow [] operator
    T* operator[](size_t x) { return TheMatrix[x];}
    matrix<T>& operator = (const matrix<T>& toCopy);

};

template <typename T>
size_t CALCULATE_SHORTEST_PATH(matrix<T> Matrix, size_t from, size_t to);
#include "matrix.tem"

//------------------cut and put into matrix.tem----------

template <typename T>
std::ostream& operator << (std::ostream& out, const matrix<T>& obj)
{
    out << obj.getDemRows() << " " << obj.getDemCols() << std::endl;
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
        for(size_t ajbi = 0; ajbi < a.getDemCols(); ++ajbi)
        {
            result[i][j] += (a.getlocation(i,ajbi) * b.getlocation(ajbi,j));
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
matrix<T>& matrix<T>::operator = (const matrix<T>& toCopy)
{
    for(size_t i = 0; i < row_count; ++i)
    {
       delete TheMatrix[i];
    }
    delete TheMatrix;

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
}

template <typename T>
matrix<T>::matrix()
{
    row_count = 0;
    col_count = 0;
}

template <typename T>
matrix<T>::matrix(std::ifstream& filestr)
{
    filestr >> row_count;
    filestr >> col_count;
    TheMatrix = new T*[row_count];
    for(size_t i = 0; i < row_count; ++i)
    {
       TheMatrix[i] = new T[col_count];
    }

    for(size_t i = 0; i < row_count; ++i)
    {
        for(size_t j = 0; j < col_count; ++j)
        {
            filestr >> TheMatrix[i][j];
        }
    }
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
    for(size_t i = 0; i < row_count; ++i)
    {
       delete TheMatrix[i];
    }
    delete TheMatrix;
};

template <typename T>
T matrix<T>::getlocation(size_t row, size_t col) const
{ return TheMatrix[row][col]; };

template <typename T>
size_t CALCULATE_SHORTEST_PATH(matrix<T> Matrix, size_t from, size_t to)
{
    size_t p = 1;
    while(Matrix[from][to] <= 0)
    {
        Matrix = Matrix * Matrix;
        ++p;
    }
    return p;

}

#endif
