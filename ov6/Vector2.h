//
// Created by tysse on 07.02.2018.
//

#ifndef OV6_VECTOR2_H
#define OV6_VECTOR2_H


class Vector2 {
private:
    double vector[2];
public:
    Vector2();
    Vector2(double a, double b);
    void set(int row, double value);
    double get(int row) const;
    friend ostream &operator<<(ostream &os, const Vector2 &matrix);
    double dot(const Vector2 &rhs) const;
    double lengthSquared() const;
    double length() const;
    Vector2 &operator+=(const Vector2 &rhs);
    Vector2 &operator-=(const Vector2 &rhs);
    Vector2 operator+(const Vector2 &rhs)const;
    Vector2 operator-(const Vector2 &rhs)const;
    ~Vector2();
};

#endif //OV6_VECTOR2_H
