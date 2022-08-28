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
        void printScore();
        void printLargestTile();

        void playerMove();
        void getPlayerMove(char & move);
        void makePlayerMove(char move);
        
        void createTestingBoard();

    private:
        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();

        void moveTiles();
        void moveTileLine(int* arr, int size);
        int selectNewTile();
        int selectTileValue();
        void createTile(); 
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
        int score;
};

#endif