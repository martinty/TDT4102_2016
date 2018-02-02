#include<iostream>
#include "ov1.h"
using namespace std;

int main() {

    //fibonacci(10);
    //triangleNumbersBelow(100);
    //cout << boolalpha << isTriangleNumber(120) << endl;
    //squareNumberSum(10);
    //max(13, 12);
    //cout << boolalpha << isPrime(47) << endl;
    //naivePrimeNumberSearch(100);
    //cout << findGreatestDivisor(105) << endl;

    srand (time(NULL));
    int size = rand() % 100 + 1;
    int list[size];
    for (int i = 0; i < size; i++){
        list[i] = (rand() % 200) - 100;
    }
    compareListOfNumbers(list, size);
    return 0;
}

