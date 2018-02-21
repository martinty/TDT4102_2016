//
// Created by tysse on 14.02.2018.
//

#ifndef OV10_VECTOR_H
#define OV10_VECTOR_H


class Vector: public Matrix {
public:
    Vector(): Matrix(){};
    Vector(unsigned int nRows, double value): Matrix(nRows, 1, value){};
    explicit Vector(const Matrix &other);
    void set(unsigned int row, double value);
    double get(unsigned int row) const;
    double dot(const Vector &rhs) const;
    double lengthSquared() const;
    double length() const;
};


#endif //OV10_VECTOR_H
