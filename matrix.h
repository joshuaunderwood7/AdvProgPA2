#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

template <typename T>
class matrix
{
  private:
    T** TheMatrix;
    size_t row_count, col_count;

  public:
    matrix(size_t rows, size_t columns);
    matrix(const matrix& toCopy);
    const T& operator [](size_t x);
    T getlocation(size_t row, size_t col);
    size_t getDemRows(void){return row_count;};
    size_t getDemCols(void){return col_count;};

    friend std::ostream& operator << (std::ostream&, const matrix<T>& obj);
   
    class matrixRow //allows for matrix[i][j] dereferencing 
    {
        matrix& parent;
        size_t   x;
        public:
            matrixRow(matrix& p, size_t theX) : parent(p), x(theX) {}     // Just init the temp object
            T& operator[](size_t y)  const { return parent.getlocation(x,y);}   // Here we get the value.
    }
    matrixRow operator[](size_t x) { return matrixRow(*this, x);}
};

//------------------cut and put into matrix.tem----------

template <typename T>
matrix<T>::matrix(size_t rows, size_t columns)
{
    TheMatrix = new T*[rows];
    for(size_t i = 0; i < rows; ++i)
    {
       TheMatrix[i] = new T[columns];
    }
};

template <typename T>
matrix<T>::matrix(const matrix& toCopy)
{
    size_t rows = toCopy.getDemRows();
    size_t cols = toCopy.getDemCols();
    TheMatrix = new T*[rows];
    for(size_t i = 0; i < rows; ++i)
    {
       TheMatrix[i] = new T[cols];
    }

    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; i < cols; ++j)
        {
            TheMatrix[i][j] = toCopy[i][j];
        }
    }

};

template <typename T>
class matrix<T>::matrixRow
{
    matrix& parent;
    size_t   x;
    public:
        matrixRow(matrix& p, size_t theX) : parent(p), x(theX) {}     // Just init the temp object
        T& operator[](size_t y)  const { return parent.getlocation(x,y);}   // Here we get the value.
};

template <typename T>
T getlocation(size_t row, size_t col)
{

}

#endif
