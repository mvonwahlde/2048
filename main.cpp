#include "2048.h"
#include "Board.h"

// g++ main.cpp 2048.cpp Board.cpp -o 2048

// To work on
// ---------------------
// Documentation
// Proper board printing
// Not generating a new tile if no tiles moved


int main(){
    char userResponse;
    bool playing = false;
    bool gameOver = false;
    
    string const  openingPrompt = "Would you like to play 2048? (y/n)";
    string const playAgainPrompt = "Would you like to play again? (y/n)";

    userContinuePlaying(openingPrompt, playing);

    initialize();

    while(playing){

        gameOver = false;
        Board* board = new Board;

        while(gameOver == false)
            board->playerMove();

        board->printScore();
        board->printLargestTile();

        delete board;
        userContinuePlaying(playAgainPrompt, playing);
    }

    return 0;
}