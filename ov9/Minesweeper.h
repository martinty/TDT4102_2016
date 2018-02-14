//
// Created by tysse on 13.02.2018.
//

#ifndef OV9_MINESWEEPER_H
#define OV9_MINESWEEPER_H


#pragma once

struct Tile {
    bool open;
    bool mine;
    bool flag;
};

class Minesweeper {
private:
    int width, height, mines, openedTiles, flagCount;
    bool victory;
    Tile *gameMatrix;
public:
    Minesweeper(int w, int h, int m);
    ~Minesweeper();
    bool isGameOver();
    bool isGameWon() const;
    bool isTileOpen(int row, int col) const;
    bool isTileMine(int row, int col) const;
    bool isTileFlag(int row, int col) const;
    void openTile(int row, int col);
    void setRemoveFlag(int row, int col);
    int numAdjacentMines(int row, int col) const;
    void solveGame();
    bool legalDirection(int row, int col, int dy, int dx)const;
    int minesLeft() const;
    Minesweeper(const Minesweeper &) = delete;
    Minesweeper &operator=(const Minesweeper &) = delete;
};


#endif //OV9_MINESWEEPER_H
