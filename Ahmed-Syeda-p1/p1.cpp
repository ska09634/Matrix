#include "Matrix.h"

int main() {
    Matrix a(2, 2);
    a.at(0, 0) = 1.5; // [ 1.5, 2.0 ]
    a.at(0, 1) = 2.0; // [ 1.0, 3.5 ]
    a.at(1, 0) = 1.0;
    a.at(1, 1) = 3.5;
    cout << "Matrix a" << endl;
    a.print();
    cout << endl;

    Matrix b(2, 1);
    b.at(0, 0) = 3.5; // [ 3.5 ]
    b.at(1, 0) = 2.0; // [ 2.0 ]
    cout << "Matrix b" << endl;
    b.print();
    cout << endl;

    // adding scalar
    Matrix c = a.add(2);
    cout << "Adding scalar 2 to Matrix a" << endl;
    c.print();
    cout << endl;

    // adding a and b together
    Matrix d = a.add(b);
    cout << "Adding a and b together (if not possible then returns a only)" << endl;
    d.print();
    cout << endl;

    // subtracting scalar
    Matrix e = a.subtract(2);
    cout << "Subtracting scalar 2 to Matrix a" << endl;
    e.print();
    cout << endl;

    //subtracting a and b
    Matrix f = a.subtract(b);
    cout << "Subtracting b from a (if not possible then returns a only)" << endl;
    f.print();
    cout << endl;

    // multiplying scalar
    Matrix g = a.multiply(2);
    cout << "Multiplying scalar 2 to matrix a" << endl;
    g.print();
    cout << endl;

    //multiplying a and b
    Matrix h = a.multiply(b);
    cout << "Multiplying a by b (if not possible then returns a only)" << endl;
    h.print();
    cout << endl;

    //dividing scalar
    Matrix i = a.divide(2);
    cout << "Dividing matrix a by scalar two" << endl;
    i.print();
    cout << endl;

    //transpose
    Matrix j = a.t();
    cout << "Transpose of matrix a" << endl;
    j.print();
    cout << endl;

    //copy constructor
    cout << "Copy Constructor of a" << endl;
    Matrix k = Matrix(a);
    k.print();
    cout << endl;

} // main
