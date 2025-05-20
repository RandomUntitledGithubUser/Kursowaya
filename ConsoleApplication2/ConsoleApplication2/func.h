#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Door {
    int posX, posY;
    bool closed = true;
    int questID;
    int idk;
};

struct Quest {
    string questName;
    int questCounter = 0;
    int questReq;
    int questID;
    string questTarget;
    string questText;
    bool questComplete;
    int questLineNum;
    int idleLineNum;
    int questPreCompleteLineNum;
    int questCompleteLineNum;
    int expReward;
};

struct Player {
    int questsCompleted;
    int playerAtk;
    int playerExp;
    int playerMaxExp;
    int playerHealth;
    int playerCurHealth;
    int player¿gility;
    int spawnY;
    int spawnX;
    int bonus¿gility;
};

struct NPC {
    string NPCName;
    string Dialogue[10];
    //string Answer[10];
    int wrongAnsw[3];
    int posX, posY;
    Quest quest;
};

struct Enemy {
    string enemyName;
    int posX, posY;
    int health, curHealth, atk, exp;
    int HPposX, HPposY;
};

void newCursorPosition(int, int);

void mapPrint(char*, int, int);

void fillTextField(char*, string, int);

void printChar(int , int , char );

void printString(int, int , string);

void clearElement(int, int);

void printStat(string, string, int);

void dialoguePrint(int, int, string);

void dialogueClear(int, int);


void hideCursor();

void playerMove(int, int, int, int);

void levelUp(int&, int&, int&, int&, int&, int&);

void virtualF11Press();

int NPCChoose(int);

void showMenu();

void showControls();

void processPlayerMovement(char arr[][156], int m,
    int& spawnX, int& spawnY, int& bufferX, int& bufferY,
    bool& combat, bool& dialogue, int& buffer,
    Door Doors[], int numDoors, int questID, int textPlacementY);