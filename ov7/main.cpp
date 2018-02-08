#include <iostream>
using namespace std;

#include "utilities.h"
#include "Matrix.h"

int main() {

    //createFibonacci();

    Matrix A(2);
    Matrix B(2);
    Matrix C(2);
    A.set(0,1,2); A.set(1,0,3); A.set(1,1,4);
    B.set(0,0,4); B.set(0,1,3); B.set(1,0,2);
    C.set(0,1,3); C.set(1,0,1.5); C.set(1,1,2);

    A += B + A - C * C;
    C = B * 2;
    B *= 2;
    B = -C;

    cout << A << endl;
    cout << B << endl;
    cout << C << endl;

    return 0;
}