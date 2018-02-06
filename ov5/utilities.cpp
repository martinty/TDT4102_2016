//
// Created by tysse on 05.02.2018.
//
#include <iostream>
#include <sstream>
using namespace std;
#include "utilities.h"

string suitToString(Suit cardSuit){
    switch (cardSuit){
        case CLUBS:
            return "Clubs";
        case DIAMONDS:
            return "Diamonds";
        case HEARTS:
            return "Harts";
        case SPADES:
            return "Spades";
        default:
            return "Error";
    }
}

string rankToString(Rank cardRank){
    switch (cardRank){
        case TWO:
            return "Two";
        case THREE:
            return "Three";
        case FOUR:
            return "Four";
        case FIVE:
            return "Five";
        case SIX:
            return "Six";
        case SEVEN:
            return "Seven";
        case EIGHT:
            return "Eight";
        case NINE:
            return "Nine";
        case TEN:
            return "Ten";
        case JACK:
            return "Jack";
        case QUEEN:
            return "Queen";
        case KING:
            return "King";
        case ACE:
            return "Ace";
        default:
            return "Error";
    }
}

string toString(CardStruck card){
    return rankToString(card.r) + " of " + suitToString(card.s);
}

string intToString(int number){
    std::stringstream ss;
    ss << number;
    return ss.str();
}

string toStringShort(CardStruck card){
    string cardRankShort = intToString(int(card.r));
    string cardSuit = suitToString(card.s);
    string cardSuitShort = cardSuit.substr(0, 1);
    return cardSuitShort + cardRankShort;
}

int randomWithLimits(int min, int max){
    return rand() % (max-min) + min ;
}