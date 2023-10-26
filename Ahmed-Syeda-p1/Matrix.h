#include <cstdlib>
#include <iostream>

using namespace std;

typedef unsigned int uint;

class Matrix {

    uint rows;
    uint cols;
    double ** mat;

public:

    /**
     * Constructor (all elements initialized to 0).
     * @param rows the number of rows
     * @param cols the number of cols
     */
    Matrix(uint rows, uint cols);

/**
 * Copy Constructor.
 * @param m the matrix from which the calling matrix will copy
 */
    Matrix(const Matrix & m); // copy constructor

/**
 * Destructor, deallocates memory for the matrix.
 */
    ~Matrix(); // destructor

    /**
     * Adds the scalar s to all of the values of the calling matrix.
     * @param s the double value to add
     * @return new matrix with updated values reflecting the addition by the scalar
     */
    Matrix add(double s) const;

    /**
     * Adds all the values in the given matrix to all the values in the calling matrix.
     * @param m the const matrix that will be added to the calling matrix
     * @return new matrix after addition
     */
    Matrix add(const Matrix & m) const;

    /**
     * Subtracts the scalar s from all the values of the calling matrix.
     * @param s the double value to subtract
     * @return new matrix after subtracting
     */
    Matrix subtract(double s) const;

    /**
     * Subtracts all the values in the given matrix from the values of the calling matrix.
     * @param m the const matrix that will be subtracted from the calling matrix
     * @return new matrix after subtracting
     */
    Matrix subtract(const Matrix & m) const;

    /**
     * Multiplies all the values in the calling matrix by the specified scalar.
     * @param s the double value to multiply by
     * @return new matrix after multiplying
     */
    Matrix multiply(double s) const;

    /**
     * Multiplies all the values in the calling matrix by the values in the given matrix.
     * @param m the const matrix that will be multiplied with the calling matrix
     * @return new matrix after multiplying
     */
    Matrix multiply(const Matrix & m) const;

    /**
     * Divides all the values in the calling matrix by the specified scalar.
     * @param s the double value to divide by
     * @return new matrix after dividing
     */
    Matrix divide(double s) const;

    /**
     * Transposes the matrix
     * @return transposed matrix
     */
    Matrix t() const;

    /**
     * Gets the number of rows of the matrix.
     * @return the number of rows
     */
    const uint numRows() const;

    /**
     * Gets the number of cols of the matrix.
     * @return the number of cols
     */
    const uint numCols() const;

    /**
     * Gets the element at row/col index.
     * @param row the row of the desired value
     * @param col the col of the desired value
     * @return the value at the specified row/col index
     */
    double & at(uint row, uint col);

    /**
     * Gets the element at row/col index. For use with const matrix.
     * @param row the row of the desired value
     * @param col the col of the desired value
     * @return the const double value at the specified row/col index
     */
    const double & at(uint row, uint col) const;

    /**
     * Acceses values at row/col indices of matrix.
     * @param row the row of the desired value
     * @param col the col of the desired value
     * @return the reference to the  double value at the specified row/col index
     */
    double & operator()(uint row, uint col);

    /**
     * Copies values from one matrix into another without copy constructor.
     * @param param the reference to the matrix whose values are being copied over
     * @return a reference to the matrix pointed to by 'this'
     */
    Matrix & operator=(const Matrix & param);

    /**
     * Negates the values of the calling matrix.
     * @return a matrix containing the negated values of the calling matrix
     */
    Matrix operator-();

    /**
     * Prints out the matrices to the screen.
     */
    void print() const;

}; // Matrix

/**
 * Creates a new matrix after adding.
 * @param s the matrix
 * @param m the scalar
 * @return a new matrix containing the added values
 */
Matrix operator+(const Matrix& s, double m);

/**
 * Creates a new matrix after addingg.
 * @param s the scalar
 * @param m the matrix
 * @return a new matrix containing the added values
 */
Matrix operator+(double s, const Matrix& m);

/**
 * Creates a new matrix after adding.
 * @param s the left Matrix
 * @param m the right Matrix
 * @return a new matrix containing the added values
 */
Matrix operator+(const Matrix& s, const Matrix& m);

/**
 * Creates a new matrix after subtracting.
 * @param s the Matrix whose values will be subtracted by m
 * @param m the scalar that will be subtracted from s's values
 * @return a new matrix containing the subtracted values
 */
Matrix operator-(const Matrix& s, double m);

/**
 * Creates a new matrix after subtracting
 * @param s the scalar that will be subtracted from m's values
 * @param m the Matrix whose values will be subtracted by s
 * @return a new matrix containing the subtracted values
 */
Matrix operator-(double s, const Matrix& m);

/**
 * Creates a new matrix after subtracting.
 * @param s the Matrix whose values will be subtracted by m's values
 * @param m the Matrix whose values will subtract from s's values
 * @return a new matrix containing the subtracted values
 */
Matrix operator-(const Matrix& s, const Matrix& m);

/**
 * Creates a new matrix after multiplying.
 * @param s the Matrix whose values will be multiplied
 * @param m the scalar to multiply by
 * @return a new matrix containing the multiplied values
 */
Matrix operator*(const Matrix& s, double m);

/**
 * Creates a new matrix after multiplying.
 * @param s the scalar to multiply by
 * @param m the Matrix whose values will be multiplied
 * @return a new matrix containing the multiplied values
 */
Matrix operator*(double s, const Matrix& m);

/**
 * Creates a new matrix after multiplying matrices.
 * @param s the left Matrix
 * @param m the right Matrix
 * @return a new matrix containing the multiplied values
 */
Matrix operator*(const Matrix& s, const Matrix& m);

/**
 * Creates a new matrix after dividing by scalar that is not 0.
 * @param s the dividend
 * @param m the divisor
 * @return a new matrix containing the divided values
 */
Matrix operator/(const Matrix& s, double m);

/**
 * Creates a new matrix after dividing by scalar that is not 0.
 * @param s the dividend
 * @param m the divisor
 * @return a new matrix containing the divided values
 */
Matrix operator/(double s, const Matrix& m);


/**
 * Stream insertion operator overload.
 * @param output the ostream reference into which the matrix output will be directed
 * @param m the matrix reference whose data will be directed into the ostream
 * @return reference to the ostream containing the desired matrix output
 */
ostream& operator<<(ostream& output, const Matrix& m);
