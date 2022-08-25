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
    int tmp;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < i; j++){
            tmp = arr[i*size + j];
            arr[i*size + j] = arr[j*size + i];
            arr[j*size + i] = tmp;
        }
    }
}

void flipArray(int* arr, int size){
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
        flipArray(&arr[i*size], size);
}

void flipCols(int* arr, int size){
    int array[4];
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++)
            array[j] = arr[j*size + i];

        flipArray(array, size);

        for(int j = 0; j < size; j++)
            arr[j*size + i] = array[j];
    }
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
    turnMatrix180();
    printBoard();
    

    cout << "Done" << endl;
    return 0; 
}