#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// Header file for board class
class Board {
    public:
        Board();

        void printBoard();

        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();

    private:
        void createTile();
        int selectNewTile();
        int selectTileValue();
        int randNum(int max);
        void shuffle(int* arr, int length);
        void setZeroes();

        int tiles[4][4];
        int const boardSize = 4;
};

#endif