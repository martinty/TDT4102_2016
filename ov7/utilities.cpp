//
// Created by tysse on 07.02.2018.
//

#include <iostream>
using namespace std;

#include "utilities.h"

void fillInFibonacciNumbers(int result[], int length){
    int a = 0;
    int b = 1;
    for (unsigned int i = 0; i < length; i++){
        result[i] = a;
        int temp = b;
        b = a+b;
        a = temp;
    }
}

void printArray(int arr[], int length){
    for (unsigned int i = 0; i < length; i++){
        cout << arr[i] << endl;
    }
}

void createFibonacci() {
    int n;
    cout << "How many Fibonacci numbers do you want: ";
    cin >> n;
    auto *fibonacciTable = new int[n]{};
    fillInFibonacciNumbers(fibonacciTable, n);
    printArray(fibonacciTable, n);
    delete[] fibonacciTable;
    fibonacciTable = nullptr;
}