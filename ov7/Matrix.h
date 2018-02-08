//
// Created by tysse on 07.02.2018.
//

#ifndef OV7_MATRIX_H
#define OV7_MATRIX_H


class Matrix {
private:
    unsigned int rows, columns;
    double *data;
public:
    Matrix();
    Matrix(unsigned int nRows, unsigned int nColumns, double value);
    explicit Matrix(unsigned int nRows);
    ~Matrix();
    void invalidData();
    double get(unsigned int row, unsigned int col) const;
    void set(unsigned int row, unsigned int col, double value);
    int getHeight() const;
    int getWidth() const;
    bool isValid() const;
    friend ostream &operator<<(ostream &os, const Matrix &matrix);
    Matrix(const Matrix & rhs);
    Matrix &operator =(Matrix rhs);
    Matrix &operator+=(const Matrix &rhs);
    Matrix operator+(const Matrix &rhs) const;
    Matrix &operator-=(const Matrix &rhs);
    Matrix operator-(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs)const;
    Matrix &operator*=(const Matrix &rhs);
    Matrix operator*(double rhs) const;		// Multiply on the rhs with a double.
    Matrix &operator*=(double rhs);		    // Multiply-assign on the rhs with a double.
    Matrix operator-()const;			    // Unary -(minus)
};


#endif //OV7_MATRIX_H
