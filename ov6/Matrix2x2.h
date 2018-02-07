//
// Created by tysse on 06.02.2018.
//

#ifndef OV6_MATRIX2X2_H
#define OV6_MATRIX2X2_H


class Matrix2x2 {
private:
    double matrix[2][2];
public:
    Matrix2x2();
    Matrix2x2(double a, double b, double c, double d);
    double get(int row, int column) const;
    void set(int row, int column, double value);
    void print()const;
    friend ostream &operator<<(ostream &os, const Matrix2x2 &matrix);
    Matrix2x2 &operator+=(const Matrix2x2 &rhs);
    Matrix2x2 &operator-=(const Matrix2x2 &rhs);
    Matrix2x2 operator+(const Matrix2x2 &rhs)const;
    Matrix2x2 operator-(const Matrix2x2 &rhs)const;
    Matrix2x2 operator*(const Matrix2x2 &rhs)const;
    Matrix2x2 &operator*=(const Matrix2x2 &rhs);
    double det() const;
    Matrix2x2 inverse() const;
    ~Matrix2x2();
};

//Vector2 operator*(const Matrix2x2 &lhs, const Vector2 &rhs);


#endif //OV6_MATRIX2X2_H
