#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(uint rows, uint cols) : rows(rows),cols(cols), mat(new double *[rows]) {

    for (uint i = 0; i < rows; i++) {
        this->mat[i] = new double[cols];
    }
} // constructor (all elements initialized to 0)

Matrix::Matrix (const Matrix & m): Matrix::Matrix(m.numRows(), m.numCols()) {
    for (uint i = 0; i < rows; i++) {
        for (uint j = 0; j < cols; j++) {
            mat[i][j] = m.at(i, j);
        } // for
    } // for
} // copy constructor

Matrix::~Matrix() {
    for (uint i = 0; i < rows; i++) {
        delete[] mat[i];
    } // for

    delete[] mat;
}// destructor

Matrix Matrix::add(double s) const {
    Matrix addend(this->rows, this->cols);
    for (uint i = 0; i < this->rows; i++) {
        for (uint j = 0; j < this->cols; j++) {
            addend.at(i, j) = this->at(i, j) + s;
        } // for j
    } // for i
    return addend;
}// add scalar to this matrix

Matrix Matrix::add(const Matrix & m) const {
    if (this->rows == m.numRows() && this->cols == m.numCols()) {
        Matrix addend(this->rows, this->cols);
        for (uint i = 0; i < this->rows; i++) {
            for (uint j = 0; j < this->cols; j++) {
                addend.at(i, j) = this->at(i, j) + m.at(i, j);
            } // for j
        } // for i
        return addend;
    } else {
        Matrix copy(*this);
        return copy;
    } // else
}// add this matrix and another matrix

Matrix Matrix::subtract(double s) const {
    Matrix subtrahend(this->rows, this->cols);
    for(uint i = 0; i < this->rows; i++) {
        for(uint j = 0; j < this->cols; j++) {
            subtrahend.at(i,j) = this->at(i,j) - s;
        }
    }
    return subtrahend;
} // subtract scalar from this matrix

Matrix Matrix::subtract(const Matrix & m) const {
    if (this-> rows == m.numRows() && this-> cols == m.numCols()) {
        Matrix subtrahend(this-> rows, this-> cols);
        for (uint i = 0; i < this->rows; i++) {
            for (uint j = 0; j < this->cols; j++) {
                subtrahend.at(i, j) = this->at(i, j) - m.at(i, j);
            } // for j
        } // for i
        return subtrahend;
    } else {
        Matrix copy(*this);
        return copy;
    } // else
}// subtract another matrix from this matrix

Matrix Matrix::multiply(double s) const {
    Matrix multiplicand(this->rows, this->cols);
    for(uint i = 0; i < this->rows; i++) {
        for(uint j = 0; j < this->cols; j++) {
            multiplicand.at(i,j) = this->at(i,j) * s;
        }
    }
    return multiplicand;
} // multiply this matrix by a scaler

Matrix Matrix::multiply(const Matrix & m) const {
    if (this-> cols == m.numRows()) {
        Matrix multiplicand(this-> rows, m.numCols());
        double product;
        for(uint i = 0; i < multiplicand.numRows(); i++) {
            for (uint j = 0; j < multiplicand.numCols(); j++) {
                product = 0;
                for (uint x = 0; x < this->cols; x++) {
                    product += this->at(i, x) * m.at(x, j);
                } // for
                multiplicand.at(i, j) = product;
            } // for j
        } // for i
        return multiplicand;
    } else {
        Matrix copy(*this);
        return copy;
    } // else
} // multiply this matrix by another matrix

Matrix Matrix::divide(double s) const {
    if (s != 0) {
        Matrix dividend(this->rows, this->cols);
        for(uint i = 0; i < this->rows; i++) {
            for (uint j = 0; j < this->cols; j++) {
                dividend.at(i, j) = this->at(i, j) / s;
            } // for j
        } // for i
        return dividend;
    } else {
        Matrix copy(*this);
        return copy;
    } // else
} // divide this matrix by a scalar

Matrix Matrix::t() const {
    Matrix trans(this->cols, this-> rows);
    for (uint i = 0; i < trans.numRows(); i++) {
        for (uint j = 0; j < trans.numCols(); j++) {
            trans.at(i, j) = this->at(j, i);
        } // for j
    } // for i
    return trans;
} // transpose (switch places) of this matrix

const uint Matrix::numRows() const {
    return this->rows;
} // returns the number of rows

const uint Matrix::numCols() const {
    return this->cols;
} // returns the number of cols

double & Matrix::at(uint row, uint col) {
    return this->mat[row][col];
} // get/set element at row,col

const double & Matrix::at(uint row, uint col) const {
    return this->mat[row][col];
} // get element at row,col (when using a const object)

double& Matrix::operator()(uint row, uint col){
    return this->at(row, col);
} // returns specific coordinate

Matrix & Matrix::operator=(const Matrix & param) {
    for (uint i = 0; i < rows; i++) {
        delete[] mat[i];
    } // for
    delete[] mat;

    this->rows = param.numRows();
    this->cols = param.numCols();

    this->mat = new double * [this->rows];
    for (uint i = 0; i < this->rows; i++) {
        this->mat[i] = new double [this->cols];
        for (uint j = 0; j < this->cols; j++) {
            this->at(i, j) = param.at(i, j);
        } // for
    } // for
    return *this;
} // returns copy of matrix

Matrix Matrix::operator-() {
    Matrix copy(*this);
    return copy.multiply(-1);
} // negates values in matrix

Matrix operator+(double s, const Matrix & m) {
    return m.add(s);
} // adds scalar to matrix

Matrix operator+(const Matrix & s, const Matrix & m) {
    return s.add(m);
} // adds scalar to matrix if const object

Matrix operator+(const Matrix& s, double m) {
    return s.add(m);
} // adds scalar to matrix

Matrix operator-(const Matrix& s, double m){
    return s.subtract(m);
} // subtracts scalar to matrix

Matrix operator-(double s, const Matrix& m) {
    return m.multiply(-1) + s;
} // subtracts scalar to matrix if const

Matrix operator-(const Matrix& s, const Matrix& m) {
    return s.subtract(m);
} // subtracts matrices together

Matrix operator*(const Matrix& s, double m) {
    return s.multiply(m);
} // multiplies scalar to matrix

Matrix operator*(double s, const Matrix& m) {
    return m.multiply(s);
} // multiplies scalar if const

Matrix operator*(const Matrix& s, const Matrix& m) {
    return s.multiply(m);
} // multiples matrices together

Matrix operator/(const Matrix& s, double m) {
    return s.divide(m);
} // divides matrix by scalar

Matrix operator/(double s, const Matrix& m) {
    Matrix copy(m.numRows(), m.numCols());
    bool zero = false;
    for(uint i = 0; i < copy.numRows(); i++) {
        for(uint j = 0; j < copy.numCols(); j++) {
            if(m.at(i,j) == 0) {
                zero = true;
                break;
            } else {
                copy.at(i,j) = s / m.at(i,j);
            }
        }
        if(zero) { break; }
    }
    if(zero) {
        Matrix original(m);
        return original;
    } else {
        return copy;
    }
} // divides matrix by scalar if const

ostream & operator<<(ostream& output, const Matrix& m) {
    for (uint i = 0; i < m.numRows(); i++) {
        output << "[ ";
        for (uint j = 0; j < m.numCols(); j++) {
            output << m.at(i,j);
            if (j < m.numCols()-1) { output << ", "; }
        }
        output << " ]" << "\n";
    }
    return output;
}

void Matrix::print() const{
    for (uint i = 0; i < numRows(); i++) {
        for (uint j = 0; j < numCols(); j++) {
            cout << "[ " << at(i, j) << " ]";
        }
        cout << endl;
    } // prints out matrix
}

// Matrix
