//
// Created by tysse on 05.02.2018.
//

#ifndef OV5_UTILITIES_H
#define OV5_UTILITIES_H

enum Suit {CLUBS = 1, DIAMONDS, HEARTS, SPADES};
enum Rank {TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};
struct CardStruck {Suit s; Rank r;};
string suitToString(Suit cardSuit);
string rankToString(Rank cardRank);
string toString(CardStruck card);
string intToString(int number);
string toStringShort(CardStruck card);
int randomWithLimits(int min, int max);

#endif //OV5_UTILITIES_H
