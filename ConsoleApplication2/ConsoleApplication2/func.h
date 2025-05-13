#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

void mapPrint(char*, int, int);

void virtualF11Press();

void fillTextField(char[], string, int);

void newCursorPosition(int , int );

void printChar(int , int , char );

void printString(int, int , string);

void clearElement(int, int);

int NPCChoose(int);

void printStat(string, string, int);

void dialogueClear(int, int);

void dialoguePrint(int, int, string);

void playerMove(int, int, int, int);

void hideCursor();

void levelUp(int&, int&, int&, int&, int&, int&);

void showMenu();

void showControls();