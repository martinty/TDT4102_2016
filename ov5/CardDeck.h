//
// Created by tysse on 05.02.2018.
//

#ifndef OV5_CARDDECK_H
#define OV5_CARDDECK_H


class CardDeck {
private:
    Card cards[52];
    int currentCardIndex;
    void swap(int cardA, int cardB);
public:
    CardDeck();
    void print();
    void printShort();
    void shuffle();
    void checkForReshuffle();
    Card drawCard();
};


#endif //OV5_CARDDECK_H
