#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

template <typename T>
class matrix
{
  private:
    T** TheMatrix;
    size_t row_count, col_count;
 
/*
    class matrixRow //allows for matrix[i][j] dereferencing 
    {
        matrix& parent;
        size_t   x;
        public:
            matrixRow(matrix& p, size_t theX) : parent(p), x(theX) {}     // Just init the temp object
            T& operator[](size_t y)  const { return parent.getlocation(x,y);}   // Here we get the value.
    };
*/

  public:
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
    out << std::endl;
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
matrix::~matrix(void)
{
    for(size_t i = 0; i < row_count; ++i)
    {
       delete TheMatrix[i];
    }
};

template <typename T>
T matrix<T>::getlocation(size_t row, size_t col) const
{ return TheMatrix[row][col]; };



#endif
