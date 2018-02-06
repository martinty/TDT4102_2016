//
// Created by tysse on 05.02.2018.
//

#ifndef OV5_CARD_H
#define OV5_CARD_H


class Card {
private:
    Suit s;
    Rank r;
    bool invalid;
public:
    void initialize(Suit cardSuit, Rank cardRank);
    Suit getSuit();
    Rank getRank();
    string toString();
    string toStringShort();
    Card();
    Card(Suit cardSuit, Rank cardRank);
};


#endif //OV5_CARD_H
