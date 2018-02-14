//
// Created by tysse on 13.02.2018.
//


#include <cstdlib>
using namespace std;
#include "utilities.h"

int randomWithLimits(int min, int max){
    return rand() % (max-min) + min ;
}