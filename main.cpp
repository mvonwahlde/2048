#include "2048.h"
#include "Board.h"

// g++ main.cpp 2048.cpp Board.cpp -o 2048

int main(){
    initialize();
    
    Board* board = new Board;
    
    board->createTestingBoard();
    board->printBoard();
    board->moveDown();
    board->moveRight();
    board->moveUp();

    delete board;

    return 0;
}