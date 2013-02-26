//
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "pa2functions.h"

/* this class holds Matricies and allows some basic operations on
*   the matrix: multipilaction and assigment.
*
*/
template <typename T>
class matrix
{
  private:
    T** TheMatrix;
    size_t row_count, col_count;

  public:
    //Constructor creates an empty matrix with dementions 0x0
    matrix();

    //Constructor creates a matrix from an input stream
    //pre: the format is:
    //The input data will be in the following format within the file.
    //6
    // The number of vertices in the vertex set V.
    //1 2 3 4 5 6
    // The vertex set, V, space delimited.
    //1 2
    // The number of edges in th edge set E.
    //1 3
    // Edge (u, v), one per line, u and v space delimited
    //1 4
    //......
    //post: matrix is created from inout stream
    matrix(std::ifstream& filestr);

    //creates matrix of given size
    //pre: given row count and column count
    //post matrix of given dementions is created with entries equal to zero
    matrix(size_t rows, size_t columns);

    //copys a matrix
    //pre: input a created matrix of this type
    //post: a copy of input matrix
    matrix(const matrix& toCopy);

    //properly frees memory
    ~matrix(void);

    //pre: given input row and column within the boundries of the matrix
    //post: copy of element at [row][column] is returned
    T getlocation(size_t row, size_t col) const;

    //pre: none
    //post: returns the created number of rows
    const size_t getDemRows(void) const {return row_count;};
    
    //pre: none
    //post: returns the created number of columns
    const size_t getDemCols(void) const {return col_count;};

//    bool setDemRows(size_t rows) {row_count = rows;} //not used
//    bool setDemCols(size_t cols) {col_count = cols;} //not used

    //pre: given input matrix[row][column] within the boundries of the matrix
    //post: copy of element at [row][column] is returned
    T* operator[](size_t x) { return TheMatrix[x];}
    
    
    //assigns a matrix
    //pre: input a created matrix of this type
    //post: original matrix is properly destructed, then a copy of input matrix
    //is made.
    matrix<T>& operator = (const matrix<T>& toCopy);

};

/* this class holds Matricies and allows some basic operations on
*   the matrix: multipilaction and assigment.
*  This is the int specialization
*/
template <>
class matrix<int>
{
  private:
    int** TheMatrix;
    size_t row_count, col_count;

  public:
    //Constructor creates an empty matrix with dementions 0x0
    matrix();

    //Constructor creates a matrix from an input stream
    //pre: the format is:
    //The input data will be in the following format within the file.
    //6
    // The number of vertices in the vertex set V.
    //1 2 3 4 5 6
    // The vertex set, V, space delimited.
    //1 2
    // The number of edges in th edge set E.
    //1 3
    // Edge (u, v), one per line, u and v space delimited
    //1 4
    //......
    //post: matrix is created from inout stream
    matrix(std::ifstream& filestr);

    //creates matrix of given size
    //pre: given row count and column count
    //post matrix of given dementions is created with entries equal to zero
    matrix(size_t rows, size_t columns);

    //copys a matrix
    //pre: input a created matrix of this type
    //post: a copy of input matrix
    matrix(const matrix& toCopy);

    //properly frees memory
    ~matrix(void);

    //pre: given input row and column within the boundries of the matrix
    //post: copy of element at [row][column] is returned
    int getlocation(size_t row, size_t col) const;

    //pre: none
    //post: returns the created number of rows
    const size_t getDemRows(void) const {return row_count;};
    
    //pre: none
    //post: returns the created number of columns
    const size_t getDemCols(void) const {return col_count;};

//    bool setDemRows(size_t rows) {row_count = rows;} //not used
//    bool setDemCols(size_t cols) {col_count = cols;} //not used

    //pre: given input matrix[row][column] within the boundries of the matrix
    //post: copy of element at [row][column] is returned
    int* operator[](size_t x) { return TheMatrix[x];}
    
    
    //assigns a matrix
    //pre: input a created matrix of this type
    //post: original matrix is properly destructed, then a copy of input matrix
    //is made.
    matrix<int>& operator = (const matrix<int>& toCopy);

};



//calulates shortest path between two nodes in a graph when the graph is
//represented as a matrix.
//pre: matrix must be a adjacency matrix representation of a graph where
//element [u][v] represents the number of edges from u to v.
//post: the shortet path from u to v is output to the screen via standard
//output, along with a short annotation  
template <typename T>
size_t CALCULATE_SHORTEST_PATH(const matrix<T>& input, size_t from, size_t to, size_t max_len=100);

#include "matrix.tem"

#endif

