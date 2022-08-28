#include "2048.h"
#include "Board.h"

string commandFile = "commands.txt";
string dataFile = "data.txt";

void initialize(){
    srand((unsigned) time(NULL));
}


void checkFiles(){
    fstream commands("../2048-communications/"+commandFile); 
    fstream data("../2048-communications/"+dataFile);

    if(commands.fail()){
        cout << "ERROR: Unable to open " << commandFile << endl;
        exit(EXIT_FAILURE);
    } else if(data.fail()){
        cout << "ERROR: Unable to open" << dataFile << endl;
    }

    commands.close();
    data.close();
}


void userContinuePlaying(string prompt, bool & playing){
    char userResponse;
    
    cout << prompt << endl;

    do{
        cin >> userResponse;
    } while(userResponse != 'y' && userResponse != 'n');

    if(userResponse == 'y')
        playing = true;
    else
        playing = false;
}