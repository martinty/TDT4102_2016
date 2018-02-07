//
// Created by tysse on 07.02.2018.
//
#include <iostream>
#include <cmath>
using namespace std;
#include "Vector2.h"

Vector2::Vector2() {
    set(0, 0);
    set(1, 0);
}

Vector2::Vector2(double a, double b) {
    set(0, a);
    set(1, b);
}

void Vector2::set(int row, double value) {
    vector[row] = value;
}

double Vector2::get(int row) const {
    return vector[row];
}

ostream &operator<<(ostream  &os, const Vector2 &vector){
    os << vector.get(0) << "\n"
       << vector.get(1) << "\n";
    return os;
}

double Vector2::dot(const Vector2 &rhs) const {
    return get(0)*rhs.get(0) + get(1)*rhs.get(1);
}

double Vector2::lengthSquared() const {
    return pow(get(0), 2) + pow(get(1),2);
}

double Vector2::length() const {
    return sqrt(lengthSquared());
}

Vector2 &Vector2::operator+=(const Vector2 &rhs){
    for(unsigned int row = 0; row < 2; row++){
        vector[row] += rhs.get(row);
    }
    return *this;
}

Vector2 &Vector2::operator-=(const Vector2 &rhs){
    for(unsigned int row = 0; row < 2; row++){
        vector[row] -= rhs.get(row);
    }
    return *this;
}

Vector2 Vector2::operator+(const Vector2 &rhs)const{
    return Vector2(*this) += rhs;
}

Vector2 Vector2::operator-(const Vector2 &rhs)const{
    return Vector2(*this) -= rhs;
}

Vector2::~Vector2(){}
