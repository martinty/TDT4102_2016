#include <iostream>
#include <ctime>
using namespace std;

#include "tests.h"
#include "mastermind.h"

int main() {
    srand (time(NULL));

    //testCallByValue();
    //testSwapNumbers();
    //testTablesSorting();
    //testCStrings();

    playMastermind();

    return 0;
}