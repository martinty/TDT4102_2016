//
// Created by tysse on 07.02.2018.
//
#include <iostream>
using namespace std;
#include "Vector2.h"
#include "Matrix2x2.h"
#include "utilities.h"

Vector2 operator*(const Matrix2x2 &lhs, const Vector2 &rhs) {
    double temp[2];
    for(unsigned int row = 0; row < 2; row++){
        for(unsigned int column = 0; column < 2; column++){
            temp[row] += lhs.get(row,column) * rhs.get(column);
        }
    }
    Vector2 vector(temp[0],temp[1]);
    return vector;
}

void equationSet(){
    double a, b, c, d, p, q;
    cout << " I : ax + by = p" << endl;
    cout << "II : cx + dy = q\n" << endl;
    cout << "| a  b |   | x |   | p |" << endl;
    cout << "|      | * |   | = |   |" << endl;
    cout << "| c  d |   1 y |   1 q |\n" << endl;
    cout << "A*x = z\n" << endl;
    cout << "Write the value of the parameters" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    cout << "d: ";
    cin >> d;
    cout << "p: ";
    cin >> p;
    cout << "q: ";
    cin >> q;
    Matrix2x2 A(a, b, c, d);
    Vector2 z(p, q);
    Vector2 x;
    cout << "\nA:\n" << A << endl;
    cout << "z:\n" << z << endl;
    solveEquationSet(A, z, x);
}

void solveEquationSet(Matrix2x2 A, Vector2 z, Vector2 x){
    x = A.inverse()*z;
    cout << "Answer:" << endl;
    cout << "x = " << x.get(0) << endl;
    cout << "y = " << x.get(1) << endl;
}