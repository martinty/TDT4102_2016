//
// Created by tysse on 03.02.2018.
//

#include <iostream>
#include <cstdlib>
using namespace std;

#include "utilities.h"

int randomWithLimits(int min, int max){
    return rand() % (max-min) + min ;
}

void randomizeCString(char min, char max, char table[], int length){
    auto minInt = int(min);
    auto maxInt = int(max) + 1;
    for (int i = 0; i < length; i++){
        int number = randomWithLimits(minInt, maxInt);
        table[i] = char(number);
    }
}

void incrementByValueNumTimes(int *startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        *startValue += increment;
    }
}

void swapNumbers(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int table[], int length){
    for (int i = 0; i < length; i++){
        cout << table[i] << "  ";
    }
    printf("\n");
}

void randomizeArray(int table[], int length){
    for (int i = 0; i < length; i++){
        table[i] = randomWithLimits(0, 100);
    }
}

void sortArray(int table[], int length){
    for (int i = 0; i < length-1; i++){
        for (int j = 0; j < length-1; j++){
            if (table[j] > table[j+1]){
                swapNumbers(&table[j], &table[j+1]);
            }
        }
    }
}

double medianOfArray(int table[], int length){
    if(length%2){
        return double(table[(length-1)/2]);
    } else{
        return ( double(table[length/2-1]) + double(table[length/2]) ) / 2;
    }
}

void readInputToCString(char table[], char min, char max, int length){
    cout << "Skriv inn en bokstav mellom " << min << " og " << max << endl;
    cout << "Du skal totalt skive inn " << length << " bokstaver" << endl;
    char letter;
    int i = 0;
    while(i < length){
        cout << "Bokstav nr. " << i+1 << ": ";
        cin >> letter;
        letter = toupper(letter);
        if ( int(min) <= int(letter) and  int(max) >= int(letter)){
            table[i] = letter;
            i++;
        }else{
            cout << "Ugyldig bokstav!" << endl;
        }
    }
}

int countOccurencesOfCharacter(char table[], int length, char letter){
    int counter = 0;
    for(int i = 0; i < length; i++){
        if (table[i] == letter){
            counter++;
        }
    }
    return counter;
}

void countOccurencesOfGrades(int gradeCount[], char gradeTable[], int tableLength, int gradeLength){
    for(int i = 0; i < gradeLength; i++){
        gradeCount[i] = countOccurencesOfCharacter(gradeTable, tableLength, char(int('A')+i));
    }
}

double calculateAverageGrade(int gradeCount[], int gradeLength, int grades){
    double averageGrade;
    int totalGradeSum = 0;
    for (int i = 0; i < gradeLength; i++){
        totalGradeSum += gradeCount[i]*(i+1);
    }
    averageGrade = double(totalGradeSum)/grades;
    return averageGrade;
}

