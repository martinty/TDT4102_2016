//
// Created by tysse on 07.02.2018.
//
#include <iostream>
#include <iomanip>
using namespace std;

#include "Matrix.h"

Matrix::Matrix() {
    rows = 0;
    columns = 0;
    data = nullptr;
}

Matrix::Matrix(unsigned int nRows, unsigned int nColumns, double value) {
    if(nRows < 1 || nColumns < 1){
        Matrix();
    } else{
        rows = nRows;
        columns = nColumns;
        data = new double[rows*columns];
        for (unsigned int i = 0; i < rows*columns; i++){
            data[i] = value;
        }
    }
}

Matrix::Matrix(unsigned int nRows):Matrix(nRows, nRows, 0) {
    for (unsigned int i = 0; i < nRows ; ++i) {
        set(i, i, 1);
    }
}

Matrix::~Matrix() {
    invalidData();
}

void Matrix::invalidData() {
    delete[] data;
    data = nullptr;
    rows = 0;
    columns = 0;
}

double Matrix::get(unsigned int row, unsigned int col) const {
    return data[row*columns + col];
}

void Matrix::set(unsigned int row, unsigned int col, double value) {
    data[row*columns + col] = value;
}

int Matrix::getHeight() const{
    return rows;
}

int Matrix::getWidth() const{
    return columns;
}

bool Matrix::isValid() const {
    if(data == nullptr){
        return false;
    } else{
        return true;
    }
}

ostream &operator<<(ostream  &os, const Matrix &matrix){
    if(matrix.isValid()){
        for(unsigned int row = 0; row < matrix.getHeight(); row++){
            for (unsigned int col = 0; col < matrix.getWidth(); col++){
                os << left << setw(10) << matrix.get(row, col) ;
            }
            os << "\n";
        }
        return os;
    } else{
        os << "Matrix is not valid\n";
        return os;
    }
}


Matrix::Matrix(const Matrix & rhs):Matrix(){
    if(rhs.isValid()){
        rows = rhs.rows;
        columns = rhs.columns;
        data = new double[rows*columns];
        for (unsigned int i = 0; i < rows*columns; i++){
            data[i] = rhs.data[i];
        }
    }
}

/*
Matrix &Matrix::operator =(Matrix rhs){
    swap(rows, rhs.rows);
    swap(columns, rhs.columns);
    swap(data, rhs.data);
    return *this;
}
*/

Matrix &Matrix::operator =(Matrix rhs){
    if (!rhs.isValid()) {
        invalidData();
    } else {
        if (rows*columns != rhs.rows*rhs.columns) {
            double *oldData = data;
            data = new double[rhs.rows*rhs.columns];
            delete[] oldData;
        }
        rows = rhs.rows;
        columns = rhs.columns;
        for ( unsigned int i = 0; i < rows*columns; ++i){
            data[i] = rhs.data[i];
        }
    }
    return *this;
}


Matrix &Matrix::operator+=(const Matrix &rhs) {
    if(rows == rhs.rows && columns == rhs.columns){
        for (int i = 0; i < rows*columns ; ++i) {
            data[i] += rhs.data[i];
        }
    } else{
        invalidData();
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &rhs) const {
    if(rows == rhs.rows && columns == rhs.columns) {
        return Matrix(*this) += rhs;
    } else{
        return Matrix();
    }
}

Matrix &Matrix::operator-=(const Matrix &rhs) {
    if(rows == rhs.rows && columns == rhs.columns){
        for (int i = 0; i < rows*columns ; ++i) {
            data[i] -= rhs.data[i];
        }
    } else{
        invalidData();
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix &rhs) const {
    if(rows == rhs.rows && columns == rhs.columns) {
        return Matrix(*this) -= rhs;
    } else{
        return Matrix();
    }
}

Matrix Matrix::operator*(const Matrix &rhs)const{
    if (columns == rhs.rows){
        Matrix temp(rows, rhs.columns,0);
        for(unsigned int row = 0; row < temp.rows; row++){
            for(unsigned int col = 0; col < temp.columns; col++){
                for(unsigned int i = 0; i < columns; i++){
                    temp.data[row*temp.columns + col] += get(row,i) * rhs.get(i,col);
                }
            }
        }
        return temp;
    } else{
        return Matrix();
    }
}

Matrix &Matrix::operator*=(const Matrix &rhs){
    if(columns == rhs.rows){
        return *this = *this * rhs;
    }else{
        invalidData();
        return *this;
    }
}



Matrix Matrix::operator*(double rhs) const {
    if(isValid()) {
        Matrix temp(rows, columns, 0);
        for (int i = 0; i < rows * columns; i++) {
            temp.data[i] = data[i] * rhs;
        }
        return temp;
    }
    return Matrix();
}

Matrix &Matrix::operator*=(double rhs) {
    if(isValid()){
        return *this = *this * rhs;
    } else{
        return *this;
    }
}

Matrix Matrix::operator-() const {
    return *this * -1;
}