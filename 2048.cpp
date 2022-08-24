#include "2048.h"
#include "Board.h"

string commandFile = "commands.txt";
string dataFile = "data.txt";

void initialize(){
    srand((unsigned) time(NULL));

    checkFiles();
        
    
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

/*
void openFile(fstream& file, string fileName, char mode){
    if(mode == 'r')
        file.open(fileName, ios::in);
    else if(mode == 'w')
        file.open(fileName, ios::out);

    if(file.fail()){
        cout << "Unable to open " << fileName << endl;
        exit(EXIT_FAILURE);
    }
}
*/