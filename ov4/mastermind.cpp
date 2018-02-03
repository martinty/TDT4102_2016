//
// Created by tysse on 03.02.2018.
//

#include <iostream>
#include <iomanip>
using namespace std;
#include "mastermind.h"
#include "utilities.h"

const int SIZE = 4;
const int LETTERS = 6;
const int MAXGUESSCOUNT = 10;
const char MIN = 'A';
const char MAX = char (int('A')+LETTERS-1);

void playMastermind(){
    char code[SIZE+1] = {};
    char guess[SIZE+1] = {};
    randomizeCString(MIN, MAX, code, SIZE);
    cout << "Play Mastermind!" << endl;
    cout<<setfill('-')<<setw(60)<<"-"<<endl;
    int game = 0;
    for (int i = MAXGUESSCOUNT; i > 0; i--){
        cout << "Antall forsøk igjen: " << i << endl;
        readInputToCString(guess, MIN, MAX, SIZE);
        game = checkCharactersAndPosition(code, guess);
        cout << "Ditt valg: " << guess << endl;
        cout << "Antall riktige bokstaver på riktig posisjon: " << game << endl;
        cout << "Antall riktige bokstaver uavhengig av posisjon: " << checkCharacters(code, guess) << endl;
        cout<<setfill('-')<<setw(60)<<"-"<<endl;
        if(game == SIZE){
            break;
        }
    }
    if (game == SIZE){
        cout << "Gratulerer, du vant!" << endl;
    } else{
        cout << "Beklager, du tapte!" << endl;
    }

}

int checkCharactersAndPosition(char code[], char guess[]){
    int counter = 0;
    for(int i = 0; i < SIZE; i++){
        if (code[i] == guess[i]){
            counter++;
        }
    }
    return counter;
}

int checkCharacters(char code[], char guess[]){
    int totalCounter = 0;
    for(int i = 0; i < LETTERS; i++){
        int codeCounter  = countOccurencesOfCharacter(code, SIZE, char(int(MIN)+i));
        int guessCounter  = countOccurencesOfCharacter(guess, SIZE, char(int(MIN)+i));
        if (codeCounter > 0 and guessCounter > 0){
            if (codeCounter <= guessCounter){
                totalCounter += codeCounter;
            } else{
                totalCounter += guessCounter;
            }
        }
    }
    return totalCounter;
}