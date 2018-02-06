//
// Created by tysse on 05.02.2018.
//

#include <iostream>
using namespace std;
#include "utilities.h"
#include "Card.h"

void Card::initialize(Suit cardSuit, Rank cardRank){
    r = cardRank;
    s = cardSuit;
    invalid = false;
} ;

Suit Card::getSuit() {
    return s;
}

Rank Card::getRank() {
    return r;
}

string Card::toString() {
    if (invalid){
        return "Invalid card";
    } else{
        return rankToString(r) + " of " + suitToString(s);
    }
}

string Card::toStringShort() {
    if (invalid){
        return "Invalid card";
    } else{
        string cardRankShort = intToString(int(r));
        string cardSuit = suitToString(s);
        string cardSuitShort = cardSuit.substr(0, 1);
        return cardSuitShort + cardRankShort;
    }
}

Card::Card() {
    invalid = true;
}

Card::Card(Suit cardSuit, Rank cardRank) {
    Card::initialize(cardSuit, cardRank);
}