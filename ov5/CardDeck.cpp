//
// Created by tysse on 05.02.2018.
//

#include <iostream>
#include <iomanip>
using namespace std;
#include "utilities.h"
#include "Card.h"
#include "CardDeck.h"

static const int MAXSUIT = 4;
static const int MINSUIT = 1;
static const int MAXRANK = 14;
static const int MINRANK = 2;
static const int TOTALCARDS = 52;

CardDeck::CardDeck() {
    int cardCounter = 0;
    for (int suit = MINSUIT; suit <= MAXSUIT; suit++){
        for (int rank = MINRANK; rank <= MAXRANK; rank++){
            Card newCard((Suit)suit, (Rank(rank)));
            cards[cardCounter] = newCard;
            cardCounter++;
        }
    }
    currentCardIndex = 0;
}

void CardDeck::swap(int cardA, int cardB) {
    Card tempCard;
    tempCard = cards[cardA];
    cards[cardA] = cards[cardB];
    cards[cardB] = tempCard;
}

void CardDeck::print() {
    for(int i = 0; i < TOTALCARDS; i++){
        cout << cards[i].toString() << endl;
    }
}

void CardDeck::printShort() {
    for(int i = 0; i < TOTALCARDS; i++){
        cout << cards[i].toStringShort() << endl;
    }
}

void CardDeck::shuffle() {
    int timesShuffled = 0;
    while (timesShuffled < 3){
        for (int i = 0; i < TOTALCARDS; i++){
            int newIndex = randomWithLimits(0, TOTALCARDS-1);
            CardDeck::swap(i, newIndex);
        }
        timesShuffled++;
    }
}

void CardDeck::checkForReshuffle(){
    if (currentCardIndex > 40){
        shuffle();
        currentCardIndex = 0;
        cout << "The deck has been reshuffled" << endl;
        cout<<setfill('-')<<setw(60)<<"-"<<endl;
    }
}

Card CardDeck::drawCard() {
    currentCardIndex += 1;
    return cards[currentCardIndex-1];
}