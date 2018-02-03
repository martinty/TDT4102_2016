//
// Created by tysse on 03.02.2018.
//

#ifndef OV4_UTILITIES_H
#define OV4_UTILITIES_H


void incrementByValueNumTimes(int *startValue, int increment, int numTimes);
void swapNumbers(int *a, int *b);
void printArray(int list[], int length);
void randomizeArray(int table[], int length);
void sortArray(int table[], int length);
double medianOfArray(int table[], int length);
void randomizeCString(char min, char max, char table[], int length);
void readInputToCString(char table[], char min, char max, int length);
int countOccurencesOfCharacter(char table[], int length, char letter);
void countOccurencesOfGrades(int gradeCount[], char gradeTable[], int tableLength, int gradeLength);
double calculateAverageGrade(int gradeCount[], int gradeLength, int grades);

#endif //OV4_UTILITIES_H
