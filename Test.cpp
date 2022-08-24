#include <iostream>
#include <cmath>

using namespace std;


int matrix[4][4];

void printBoard(){
    cout << endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printArray(int arr[4]){
    cout << endl;
    
    for(int i = 0; i < 4; i++)
        cout << arr[i] << " ";

    cout << endl << endl;
}

void transposeMatrix(int* arr, int size){
    // *(*(arr + row) + col) == arr[row][col]
}

void flipRow(int* arr, int size){
    int tmp;
    int flips = floor(size / 2);
    
    for(int i = 0; i < flips; i++){
        tmp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = tmp;
    }
}

void flipRows(int* arr, int size){
    for(int i = 0; i < size; i++)
        flipRow(&arr[i*4], 4);
}

void flipCol(int* arr, int size){

}

void flipCols(int* arr, int size){

}


void turnMatrixCW90(){
    transposeMatrix((int *)matrix, 4);
    flipRows((int *)matrix, 4);
}

void turnMatrixCCW90(){
    transposeMatrix((int *)matrix, 4);
    flipCols((int *)matrix, 4);
}

void turnMatrix180(){
    flipRows((int *)matrix, 4);
    flipCols((int *)matrix, 4);
}


int main(){
    
    for(int i = 0; i < 4; i++)
        for(int j = 1; j < 5; j++)
            matrix[i][j - 1] = i * 4 + j;

    printBoard();
    
    flipRows((int *)matrix, 4);

    printBoard();
    

    cout << "Done" << endl;
    return 0; 
}