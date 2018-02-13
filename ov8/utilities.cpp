//
// Created by tysse on 12.02.2018.
//

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

#include "utilities.h"

void createAndWriteToFile(string fileName){
    string word;
    ofstream outStream(fileName);
    cout << "Write words for the file (write quit to stop): ";
    cin >> word;
    if (word == "quit"){
        outStream.close();
    }else{
        outStream << word;
        for(;;){
            cin >> word;
            if (word == "quit"){
                break;
            }
            outStream << "\n" << word;
        }
        outStream.close();
    }
}

void readFromFileAndAddLineNumbers(string fileName){
    ifstream inStream;
    inStream.open(fileName);
    if (inStream.fail()){
        cout << "File do not exist" << endl;
    } else{
        ofstream outStream("index_"+fileName);
        char nextLetter;
        int n = 1;
        inStream.get(nextLetter);
        outStream << n << ' ';
        while (!inStream.eof()){
            outStream << nextLetter;
            if (nextLetter == '\n'){
                n++;
                outStream << n << ' ';
            }
            inStream.get(nextLetter);
        }
        outStream.close();
        inStream.close();
    }
}

void createFile(string fileName){
    ofstream outStream(fileName);
    outStream.close();
}

void readFromFileAndMakeStatistic(string fileName){
    ifstream inStream;
    inStream.open(fileName);
    if (inStream.fail()){
        cout << "File do not exist" << endl;
    } else{
        cout << "Character statistics" << endl;
        char nextChar;
        int charCount[26] = {};
        int totalChars = 0;
        int charIndex;
        inStream.get(nextChar);
        while(!inStream.eof()){
            nextChar = tolower(nextChar);
            charIndex = int(nextChar);
            if(charIndex >= int('a') && charIndex <= int('z') ){
                charCount[charIndex-int('a')]++;
                totalChars++;
            }
            inStream.get(nextChar);
        }
        cout << "Total number of characters: " << totalChars << endl;
        auto intToCharIndex = int('a');
        for (unsigned int i = 1; i <= 26; i++) {
            cout << char(intToCharIndex) << ": " << charCount[i-1] << "\t\t";
            intToCharIndex++;
            if(i%4 == 0){
                cout << "\n";
            }
        }
        inStream.close();
    }
}

void wordStatisticFromFile(string fileName){
    ifstream inStream;
    inStream.open(fileName);
    if (inStream.fail()){
        cout << "File do not exist" << endl;
    } else{
        map<string, int> statistics;
        char nextChar;
        int totalWords = 0;
        int totalLines = 0;
        int charIndex;
        int averageWordLength = 0;
        string word;
        string longestWord;
        inStream.get(nextChar);
        while(!inStream.eof()){
            if (!totalLines){
                totalLines = 1;
            }
            nextChar = tolower(nextChar);
            charIndex = int(nextChar);
            if(charIndex >= int('a') && charIndex <= int('z')){
                word += nextChar;
            }else if(nextChar == ' ' || nextChar == '\n'){
                if (statistics.find(word) != statistics.end()){
                    statistics[word] += 1;
                }else{
                    statistics[word] = 1;
                }
                if (nextChar == '\n'){
                    totalLines++;
                }
                if (longestWord.length() < word.length()){
                    longestWord = word;
                }
                averageWordLength += word.length();
                totalWords++;
                word = "";
            } else if(charIndex == -91){    // å
                word += "aa";
            } else if(charIndex == -72){    // ø
                word += "oo";
            } else if(charIndex == -90){    // æ
                word += "ae";
            }
            inStream.get(nextChar);
        }
        inStream.close();
        if (statistics.find(word) != statistics.end()){
            statistics[word] += 1;
        }else {
            statistics[word] = 1;
        }
        averageWordLength += word.length();
        totalWords++;
        if (longestWord.length() < word.length()){
            longestWord = word;
        }
        cout << "Text statistics" << endl;
        cout << "Longest word: " << longestWord << endl;
        cout << "Number of words: " << totalWords << endl;
        cout << "Number of lines: " << totalLines << endl;
        cout << "Average word length: " << averageWordLength/totalWords << endl;
        map<string, int>::const_iterator key;
        for (key = statistics.begin(); key != statistics.end() ; key++) {
            cout << key->first << ": " << key->second << endl;
        }
    }
}