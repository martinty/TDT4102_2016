//
// Created by tysse on 13.02.2018.
//

#include "utilities.h"
#include "Minesweeper.h"

Minesweeper::Minesweeper(int w, int h, int m) {
    width = w;
    height = h;
    mines = m;
    openedTiles = 0;
    flagCount = 0;
    victory = false;
    gameMatrix = new Tile[width*height];
    for (unsigned int i = 0; i < width*height; i++){
        gameMatrix[i].open = false;
        gameMatrix[i].mine = false;
        gameMatrix[i].flag = false;
    }
    int randomIndex;
    while(m > 0){
        randomIndex = randomWithLimits(0, width*height);
        if(!gameMatrix[randomIndex].mine){
            gameMatrix[randomIndex].mine = true;
            m--;
        }
    }
}

Minesweeper::~Minesweeper() {
    width = 0;
    height = 0;
    mines = 0;
    openedTiles = 0;
    flagCount = 0;
    victory = false;
    delete[] gameMatrix;
    gameMatrix = nullptr;
}

bool Minesweeper::isGameOver() {
    for (unsigned int i = 0; i < width*height; i++){
        if (gameMatrix[i].open && gameMatrix[i].mine){
            for (unsigned int j = 0; j < width*height; j++){
                if(gameMatrix[j].flag && gameMatrix[j].mine){
                    gameMatrix[j].flag = !gameMatrix[j].flag;
                }
            }
            return true;
        }
    }
    if(width*height - openedTiles == mines){
        for (unsigned int j = 0; j < width*height; j++){
            if(gameMatrix[j].flag && gameMatrix[j].mine){
                gameMatrix[j].flag = !gameMatrix[j].flag;
            }
        }
        victory = true;
        return true;
    }
    return false;
}

bool Minesweeper::isGameWon() const {
    return victory;
}

bool Minesweeper::isTileOpen(int row, int col) const {
    return gameMatrix[row*width + col].open;
}

bool Minesweeper::isTileMine(int row, int col) const {
    return gameMatrix[row*width + col].mine;
}

bool Minesweeper::isTileFlag(int row, int col) const {
    return gameMatrix[row*width + col].flag;
}

void Minesweeper::openTile(int row, int col) {
    if(!isTileFlag(row,col)){
        gameMatrix[row*width + col].open = true;
        openedTiles++;
        if(numAdjacentMines(row, col) == 0){
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if(legalDirection(row,col,y,x)){
                        if (!isTileMine(row + y, col + x) && !isTileOpen(row + y, col + x)) {
                            openTile(row+y,col+x);
                        }
                    }
                }
            }
        }
    }
}

void Minesweeper::setRemoveFlag(int row, int col) {
    if(!isTileOpen(row, col)){
        if (isTileFlag(row, col)){
            gameMatrix[row * width + col].flag = false;
            flagCount--;
        } else{
            gameMatrix[row * width + col].flag = true;
            flagCount++;
        }
    }
}

int Minesweeper::numAdjacentMines(int row, int col) const {
    int adjacentMines = 0;
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if(legalDirection(row, col, y, x)){
                if (isTileMine(row + y, col + x)) {
                    adjacentMines++;
                }
            }
        }
    }
    return adjacentMines;
}

void Minesweeper::solveGame() {
    for (int i = 0; i < width * height; i++) {
        if(!gameMatrix[i].mine){
            gameMatrix[i].open = true;
            openedTiles++;
        }
    }
}

bool Minesweeper::legalDirection(int row, int col, int dy, int dx)const {

    // The center
    if(row > 0 && col > 0 && row < height-1 && col < width-1){
        return true;
    }

    // The lines around
    else if(row == 0 && col > 0 && col < width-1){
        if(dy == -1){
            return false;
        }
    } else if(row == height-1 && col > 0 && col < width-1){
        if(dy == 1){
            return false;
        }
    } else if(col == 0 && row > 0 && row < height-1){
        if(dx == -1){
            return false;
        }
    } else if(col == width-1 && row > 0 && row < height-1){
        if(dx == 1){
            return false;
        }

    // The corners
    } else if(row == 0 && col == 0){
        if(dy == -1 || dx == -1){
            return false;
        }
    } else if(row == 0 && col == width-1){
        if(dy == -1 || dx == 1){
            return false;
        }
    } else if(row == height-1 && col == 0) {
        if(dy == 1 || dx == -1){
            return false;
        }
    }else if(row == height-1 && col == width-1) {
        if(dy == 1 || dx == 1){
            return false;
        }
    }
    return true;
}

int Minesweeper::minesLeft() const {
    return mines-flagCount;
}