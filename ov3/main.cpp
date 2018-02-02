#include <iostream>
#include <ctime>
#include <random>
using namespace std;
#include "cannonball.h"
#include "utilities.h"


int main() {

    random_device seeder;
    default_random_engine generator(seeder());
    modernRandomWithLimits(20, 60, generator);

    //testFunctions();
    //testTargetPractice();
    srand (time(NULL));
    playTargetPractice();

    return 0;
}