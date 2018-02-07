//
// Created by tysse on 06.02.2018.
//
#include <iostream>
#include <iomanip>
using namespace std;
#include "Matrix2x2.h"

Matrix2x2::Matrix2x2() {
    set(0,0,1);
    set(0,1,0);
    set(1,0,0);
    set(1,1,1);
}

Matrix2x2::Matrix2x2(double a, double b, double c, double d) {
    set(0,0,a);
    set(0,1,b);
    set(1,0,c);
    set(1,1,d);
}

double Matrix2x2::get(int row, int column) const {
    return matrix[row][column];
}

void Matrix2x2::set(int row, int column, double value) {
    matrix[row][column] = value;
}

void Matrix2x2::print()const{
    cout << get(0,0) << "\t\t" << get(0, 1) << endl;
    cout << get(1,0) << "\t\t" << get(1, 1) << endl;
}

ostream &operator<<(ostream  &os, const Matrix2x2 &matrix){
    os << left << setw(10) << matrix.get(0,0) << matrix.get(0,1) << "\n"
       << left << setw(10) << matrix.get(1,0) << matrix.get(1,1) << "\n";
    return os;
}

Matrix2x2 &Matrix2x2::operator+=(const Matrix2x2 &rhs){
    for(unsigned int row = 0; row < 2; row++){
        for(unsigned int column = 0; column < 2; column++){
            matrix[row][column] += rhs.get(row,column);
        }
    }
    return *this;
}

Matrix2x2 &Matrix2x2::operator-=(const Matrix2x2 &rhs){
    for(unsigned int row = 0; row < 2; row++){
        for(unsigned int column = 0; column < 2; column++){
            matrix[row][column] -= rhs.get(row,column);
        }
    }
    return *this;
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2 &rhs)const{
    return Matrix2x2(*this) += rhs;
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2 &rhs)const{
    return Matrix2x2(*this) -= rhs;
}

Matrix2x2 Matrix2x2::operator*(const Matrix2x2 &rhs)const{
    Matrix2x2 temp(0,0,0,0);
    for(unsigned int row = 0; row < 2; row++){
        for(unsigned int column = 0; column < 2; column++){
            for(unsigned int i = 0; i < 2; i++){
                temp.matrix[row][column] += get(row,i) * rhs.get(i,column);
            }
        }
    }
    return temp;
}

Matrix2x2 &Matrix2x2::operator*=(const Matrix2x2 &rhs){
    return *this = *this * rhs;
}

double Matrix2x2::det() const {
    return get(0,0)*get(1,1) - get(0,1)*get(1,0);
}

Matrix2x2 Matrix2x2::inverse() const {
    double determinant = det();
    if (determinant == 0){
        cout << "Matrix A is singular. No solution!" << endl;
        Matrix2x2 error(0,0,0,0);
        return error;
    } else{
        Matrix2x2 inverse(get(1,1)/determinant, -get(1,0)/determinant,
                          -get(0,1)/determinant, get(0,0)/determinant);
        return inverse;
    }
}

Matrix2x2::~Matrix2x2() {}