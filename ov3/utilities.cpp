//
// Created by tysse on 02.02.2018.
//

#include <cstdlib>
#include <random>
using namespace std;
#include "utilities.h"

int randomWithLimits(int min, int max){
    return rand() % (max-min) + min ;
}

int modernRandomWithLimits(int min, int max, default_random_engine& generator){
    uniform_int_distribution<int> uniform(min, max);
    return uniform(generator);
}