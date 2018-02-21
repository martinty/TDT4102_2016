//
// Created by tysse on 14.02.2018.
//
#include <cmath>

#include "Matrix.h"
#include "Vector.h"

Vector::Vector(const Matrix &other): Matrix() {
    if (other.getColumns() == 1 && other.isValid()) {
        Matrix::operator=(other);
    }
}

void Vector::set(unsigned int row, double value) {
    Matrix::set(row,0,value);
}

double Vector::get(unsigned int row) const {
    return Matrix::get(row,0);
}

double Vector::dot(const Vector &rhs) const {
    if (getRows() == rhs.getRows()){
        double value = 0;
        for (unsigned int row = 0; row < getRows(); row++) {
            value += get(row) * rhs.get(row);
        }
        return value;
    } else{
        return nan("");
    }
}

double Vector::lengthSquared() const {
    double value = 0;
    for (unsigned int row = 0; row < getRows(); row++) {
        value += pow(get(row),2);
    }
    return value;
}

double Vector::length() const {
    return sqrt(lengthSquared());
}
