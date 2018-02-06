//
// Created by tysse on 06.02.2018.
//

#ifndef OV5_BLACKJACK_H
#define OV5_BLACKJACK_H


class Blackjack {
private:
    CardDeck deck;
    int playerHand;
    int dealerHand;
    int playerCardsDrawn;
    int dealerCardsDrawn;
    int playerPoints;
    int dealerPoints;
public:
    Blackjack();
    bool isAce(Card *card);
    int getCardValue(Card *card);
    int getPlayerCardValue(Card *card);
    int getDealerCardValue(Card *card, int dealerHand);
    bool askPlayerDrawCard();
    void drawPlayersCard();
    void drawDealersCard();
    void drawInitialCards(bool *gamePoint);
    void playGame();

};


#endif //OV5_BLACKJACK_H
