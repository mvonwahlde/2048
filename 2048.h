#ifndef C2048_H
#define C2048_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;



void initialize();

void checkFiles();

void openFile(fstream&, string, char);

#endif