//
// Created by tysse on 03.02.2018.
//
#include <iostream>
#include <iomanip>
using namespace std;

#include "utilities.h"
#include "tests.h"

void testCallByValue(){
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimes(&v0, increment, iterations);
    cout << "v0: " << v0-increment*iterations
              << " increment: " << increment
              << " iterations: " << iterations
              << " result: " << v0 << endl;
}

void testSwapNumbers(){
    int a = 10;
    int b = 20;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    swapNumbers(&a, &b); printf("Swapped numbers!\n");
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

void testTablesSorting(){
    int length = 5;
    int percentages[length] = {};
    randomizeArray(percentages, length);
    printArray(percentages, length);
    swapNumbers(&percentages[0], &percentages[1]);
    printArray(percentages, length);
    sortArray(percentages, length);
    printArray(percentages, length);
    cout << "Median: " << medianOfArray(percentages, length) << endl;
}

void testCStrings(){
    int tableLength = 8*5;
    char min = 'A';
    char max = 'E';
    int gradeLength = int(max) - int(min) + 1;
    char grades[tableLength+1] = {};
    int gradeCount[gradeLength] = {};
    int choice;
    cout << "Ønsker du random karakterer? [ja=1][nei=0}" << endl;
    cin >> choice;
    if (choice){
        randomizeCString(min, max, grades, tableLength);
        cout << grades << endl;
        countOccurencesOfGrades(gradeCount, grades, tableLength, gradeLength);
        printArray(gradeCount, gradeLength);
        cout << setprecision(2) <<  calculateAverageGrade(gradeCount, gradeLength, tableLength) << endl;
    } else{
        readInputToCString(grades, min, max, tableLength);
        cout << grades << endl;
        countOccurencesOfGrades(gradeCount, grades, tableLength, gradeLength);
        printArray(gradeCount, gradeLength);
        cout << setprecision(2) <<  calculateAverageGrade(gradeCount, gradeLength, tableLength) << endl;
    }
}