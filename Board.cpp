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
}


void Board::moveUp(){
    
}


void Board::moveDown(){

}


void Board::moveRight(){

}


void Board::moveLeft(){

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