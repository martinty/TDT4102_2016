//
// Created by tysse on 31.01.2018.
//

#include <iostream>
#include "ov1.h"
#include <list>
using namespace std;

int fibonacci(int n){
    int a = 0;
    int b = 1;
    printf("Fibonacci numbers:\n");
    for (int x = 1; x <= n; x += 1){
        int temp = b;
        b = a+b;
        a = temp;
        cout << x << " " << b << endl;
    }
    printf("-------\n");
    return b;
}

void triangleNumbersBelow(int n){
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ":" << endl;
    while (acc + num < n){
        acc = acc+num;
        num += 1;
        cout << acc << endl;
    }
    printf("-------\n");
}

bool isTriangleNumber(int number){
    int acc = 1;
    while (number > 0){
        number = number - acc;
        acc += 1;
    }
    if (number == 0){
        return true;
    } else{
        return false;
    }
}

int squareNumberSum(int n){
    int totalSum = 0;
    for (int i = 0; i < n; i++){
        totalSum += i*i;
        cout << i*i << endl;
    }
    cout << totalSum << endl;
    return totalSum;
}

int max(int a, int b){
    if (a > b){
        printf("A is greater then B\n");
        return a;
    } else{
        printf("B is greater then A\n");
        return b;
    }
}

bool isPrime(int n){
    for (int j = 2; j < n; j++){
        if (n%j == 0) {
            return false;
        }
    }
    return true;
}

void naivePrimeNumberSearch(int n){
    for (int i = 2; i < n; i++){
        if (isPrime(i)){
            cout << i << " is a prime" << endl;
        }
    }
}

int findGreatestDivisor(int n){
    for (int divisor = n - 1; divisor > 0; divisor--){
        if (n%divisor == 0){
            return divisor;
        }
    }
}

void compareListOfNumbers(int list[], int size){
    int r[3] = { 0, 0, 0 };
    for (int i = 0; i < size; i++){
        if (list[i] < 0) {
            r[0] += 1;
        } else if (list[i] == 0){
            r[1] += 1;
        } else{
            r[2] += 1;
        }
    }
    cout << "Size: " << size << endl;
    cout << r[0] << " numbers were below zero" << endl;
    cout << r[1] << " numbers were zero" << endl;
    cout << r[2] << " numbers were greater than zero" << endl;
}