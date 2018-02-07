//
// Created by tysse on 07.02.2018.
//

#ifndef OV6_UTILITIES_H
#define OV6_UTILITIES_H


Vector2 operator*(const Matrix2x2 &lhs, const Vector2 &rhs);
void equationSet();
void solveEquationSet(Matrix2x2 A, Vector2 z, Vector2 x);

#endif //OV6_UTILITIES_H
