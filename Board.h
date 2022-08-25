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
        void createTile(); // move this back to private
        void createTestingBoard();

    private:

        int selectNewTile();
        int selectTileValue();
        int randNum(int max);
        void shuffle(int* arr, int length);
        void setZeroes();

        void turnBoard180();
        void turnBoardCCW90();
        void turnBoardCW90();
        void flipCols(int* arr, int size);
        void flipRows(int* arr, int size);
        void flipArray(int* arr, int size);
        void transposeMatrix(int* arr, int size);


        int tiles[4][4];
        int const boardSize = 4;
};

#endif