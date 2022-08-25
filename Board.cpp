// Methods for Board class
#include "Board.h"


Board::Board(){
    setZeroes();
    createTile();
    createTile();
}


void Board::printBoard(){
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            cout << tiles[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}


void Board::createTestingBoard(){
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            tiles[i][j] = i*4 + j;
}


void Board::moveUp(){
    turnBoardCCW90();
    printBoard();
    turnBoardCW90();
    printBoard();
}


void Board::moveDown(){
    turnBoardCW90();
    printBoard();
    turnBoardCCW90();
    printBoard();
}


void Board::moveRight(){
    turnBoard180();
    printBoard();
    turnBoard180();
    printBoard();
}


void Board::moveLeft(){
    printBoard();
}


void Board::createTile(){
    int tile = selectNewTile();

    if(tile == -1){
        cout << "Problem generating new tile" << endl;
        exit(EXIT_FAILURE);
    }

    int row = floor(tile / boardSize);
    int col = tile % boardSize;

    tiles[row][col] = selectTileValue();
}


int Board::selectNewTile(){
    int const length = 16; // COME BACK TO THIS
    int arr[length];
    int row;
    int col;

    for(int i = 0; i < length; i++)
        arr[i] = i;

    shuffle(arr, length);

    for(int i = 0; i < length; i++)
        if(tiles[arr[i] / 4][arr[i] % 4] == 0)
            return arr[i];

    return -1;
}


int Board::selectTileValue(){
    int probability = randNum(9);

    if(probability == 0)
        return 4;
    else
        return 2;
}


int Board::randNum(int max){
    return rand() % (max + 1);
}


void Board::shuffle(int* arr, int length){
    int temp;
    int j;
    
    for(int i = length - 1; i != 0; i--){
        j = randNum(i);

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}


void Board::setZeroes(){
    for(int i = 0; i < boardSize; i++)
        for(int j = 0; j < boardSize; j++)
            tiles[i][j] = 0;
}


void Board::turnBoard180(){
    flipRows((int *)tiles, boardSize);
    flipCols((int *)tiles, boardSize);
}


void Board::turnBoardCCW90(){
    transposeMatrix((int *)tiles, boardSize);
    flipCols((int *)tiles, boardSize);
}


void Board::turnBoardCW90(){
    transposeMatrix((int *)tiles, boardSize);
    flipRows((int *)tiles, boardSize);
}


void Board::transposeMatrix(int* arr, int size){
    int tmp;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < i; j++){
            tmp = arr[i*size + j];
            arr[i*size + j] = arr[j*size + i];
            arr[j*size + i] = tmp;
        }
    }
}


void Board::flipRows(int* arr, int size){
    for(int i = 0; i < size; i++)
        flipArray(&arr[i*size], size);
}


void Board::flipCols(int* arr, int size){
    int array[4];
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++)
            array[j] = arr[j*size + i];

        flipArray(array, size);

        for(int j = 0; j < size; j++)
            arr[j*size + i] = array[j];
    }
}


void Board::flipArray(int* arr, int size){
    int tmp;
    int flips = floor(size / 2);
    
    for(int i = 0; i < flips; i++){
        tmp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = tmp;
    }
}