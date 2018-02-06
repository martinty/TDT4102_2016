#include <iostream>
#include <ctime>
using namespace std;
#include "utilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"

int main() {

    srand (time(NULL));

    Blackjack game;
    game.playGame();

    return 0;
}