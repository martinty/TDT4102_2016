//
// Created by tysse on 06.02.2018.
//
#include <iostream>
#include <iomanip>
using namespace std;
#include "utilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"

static const int BLACKJACK = 21;

Blackjack::Blackjack() {
    playerPoints = 0;
    dealerPoints = 0;
    deck.shuffle();
}

bool Blackjack::isAce(Card *card){
    switch (card->getRank()){
        case ACE:
            return true;
        default:
            return false;
    }
}

int Blackjack::getCardValue(Card* card) {
    switch (card->getRank()){
        case ACE:
            return -1;
        default:
            auto cardValue = int(card->getRank());
            if(cardValue > 10){
                return 10;
            } else{
                return cardValue;
            }
    }
}

int Blackjack::getPlayerCardValue(Card *card) {
    if(isAce(card)){
        string answer;
        for(;;){
            cout << "Do you want the Ace to be of value 1 og 11? [1 / 11] ";
            cin >> answer;
            if (answer == "1"){
                return 1;
            } else if (answer == "11"){
                return 11;
            }
            cout << "Incorrect answer!" << endl;
        }
    } else{
        return getCardValue(card);
    }
}

int Blackjack::getDealerCardValue(Card *card, int dealerHand) {
    if(isAce(card)){
        if(dealerHand+11 > 21){
            return 1;
        } else{
            return 11;
        }
    } else{
        return getCardValue(card);
    }
}

bool Blackjack::askPlayerDrawCard() {
    string answer;
    for(;;){
        cout << "Do you want a new card? [yes / no] ";
        cin >> answer;
        if(answer == "yes"){
            return true;
        } else if(answer == "no"){
            return false;
        }
        cout << "Incorrect answer!" << endl;
    }
}

void Blackjack::drawPlayersCard() {
    Card newCard = deck.drawCard();
    playerCardsDrawn++;
    cout << "Players " << playerCardsDrawn << ". card: " << newCard.toString() << endl;
    playerHand += getPlayerCardValue(&newCard);
}

void Blackjack::drawDealersCard() {
    Card newCard = deck.drawCard();
    dealerCardsDrawn++;
    cout << "Dealers " << dealerCardsDrawn << ". card: " << newCard.toString() << endl;
    dealerHand += getDealerCardValue(&newCard, dealerHand);
}

void Blackjack::drawInitialCards(bool *gamePoint) {

    playerHand = 0;
    dealerHand = 0;
    playerCardsDrawn = 0;
    dealerCardsDrawn = 0;

    while (playerCardsDrawn+dealerCardsDrawn < 4){
        drawPlayersCard();
        drawDealersCard();
    }
    cout << "Players hand: " << playerHand << endl;
    cout << "Dealers hand: " << dealerHand << endl;
    if (playerHand == BLACKJACK){
        cout << "Blackjack! Player win!" << endl;
        playerPoints++;
        *gamePoint = true;
    } else if (dealerHand == BLACKJACK){
        cout << "Dealer win!" << endl;
        dealerPoints++;
        *gamePoint = true;
    }
}

void Blackjack::playGame() {

    bool drawNewCard = true;
    while(drawNewCard) {
        bool gamePoint = false;
        deck.checkForReshuffle();
        drawInitialCards(&gamePoint);
        while (!gamePoint) {
            if (askPlayerDrawCard()) {
                drawPlayersCard();
                if (playerHand > BLACKJACK) {
                    cout << "Players hand: " << playerHand << endl;
                    cout << "Dealer win!" << endl;
                    dealerPoints++;
                    gamePoint = true;
                } else if (playerHand == BLACKJACK) {
                    cout << "Players hand: " << playerHand << endl;
                    cout << "Blackjack! Player win!" << endl;
                    playerPoints++;
                    gamePoint = true;
                } else if (dealerHand >= 17) {
                    cout << "Players hand: " << playerHand << endl;
                    cout << "Dealers hand: " << dealerHand << endl;
                } else {
                    drawDealersCard();
                    if (dealerHand > BLACKJACK) {
                        cout << "Players hand: " << playerHand << endl;
                        cout << "Dealers hand: " << dealerHand << endl;
                        cout << "Player win!" << endl;
                        playerPoints++;
                        gamePoint = true;
                    } else if (dealerHand == BLACKJACK) {
                        cout << "Players hand: " << playerHand << endl;
                        cout << "Dealers hand: " << dealerHand << endl;
                        cout << "Dealer win!" << endl;
                        dealerPoints++;
                        gamePoint = true;
                    } else {
                        cout << "Players hand: " << playerHand << endl;
                        cout << "Dealers hand: " << dealerHand << endl;
                    }
                }
            } else {
                bool checkWin = true;
                while (dealerHand < 17) {
                    drawDealersCard();
                    if (dealerHand > BLACKJACK) {
                        cout << "Players hand: " << playerHand << endl;
                        cout << "Dealers hand: " << dealerHand << endl;
                        cout << "Player win!" << endl;
                        checkWin = false;
                        playerPoints++;
                        gamePoint = true;
                    } else if (dealerHand == BLACKJACK) {
                        cout << "Players hand: " << playerHand << endl;
                        cout << "Dealers hand: " << dealerHand << endl;
                        cout << "Dealer win!" << endl;
                        checkWin = false;
                        dealerPoints++;
                        gamePoint = true;
                    } else {
                        cout << "Players hand: " << playerHand << endl;
                        cout << "Dealers hand: " << dealerHand << endl;
                    }
                }
                if (checkWin) {
                    if (dealerHand >= playerHand) {
                        cout << "Dealer win!" << endl;
                        dealerPoints++;
                        gamePoint = true;
                    } else {
                        cout << "Player win!" << endl;
                        playerPoints++;
                        gamePoint = true;
                    }
                }
            }
        }
        cout<<setfill('-')<<setw(60)<<"-"<<endl;
        cout << "Players points: " << playerPoints << endl;
        cout << "Dealers points: " << dealerPoints << endl;
        string answer;
        for(;;){
            cout << "Do you want to play a new round? [yes / no] ";
            cin >> answer;
            if(answer == "yes"){
                break;
            } else if(answer == "no"){
                drawNewCard = false;
                break;
            }
            cout << "Incorrect answer!" << endl;
        }
        cout<<setfill('-')<<setw(60)<<"-"<<endl;
    }
}