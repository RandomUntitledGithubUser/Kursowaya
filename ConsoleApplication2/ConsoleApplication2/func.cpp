#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include "func.h"

using namespace std;

void mapPrint(char* arr, int m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i * m + j];
        }
        cout << '\n';
    }
}

void virtualF11Press() {
    INPUT input[2] = {};

    input[0].type = INPUT_KEYBOARD;
    input[0].ki.wVk = VK_F11;
    input[0].ki.dwFlags = 0;

    input[1].type = INPUT_KEYBOARD;
    input[1].ki.wVk = VK_F11;
    input[1].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(2, input, sizeof(INPUT));
}


void fillTextField(char arr[], string textField, int placementX) {
    for (int i = 0, j = placementX; i < textField.length(); j++, i++)
        arr[j] = textField[i];
};

void newCursorPosition(int posX, int posY) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {
        static_cast<SHORT>(posX),
        static_cast<SHORT>(posY)
    };
    SetConsoleCursorPosition(console, position);
}

void printChar(int posX, int posY, char object) {
    newCursorPosition(posX, posY);
    cout << object;
}

void printString(int posX, int posY, string text) {
    newCursorPosition(posX, posY);
    cout << text;
}

void clearElement(int posX, int posY) {
    printChar(posX, posY, ' ');
}

int NPCChoose(int pos) {
    switch (pos) {
    case 23: {
        return 0;
    }
    case 26: {
        return 1;
    }
    case 9: {
        return 2;
    }
    case 19: {
        return 3;
    }

    }
}

void printStat(string stat, string oldStat, int textPlacement) {
    string buffer = stat;
    stat = oldStat;

    if (buffer.length() > stat.length())
        stat += " ";

    for (int i = 0; i < stat.length(); i++) {
        newCursorPosition(122 + i, textPlacement);
        clearElement(122 + i, textPlacement);
    }

    newCursorPosition(122, textPlacement);
    printString(122, textPlacement, stat);
}

void dialogueClear(int y, int x) {
    for (int i = x; i < 118; i++) {
        newCursorPosition(i, y);
        clearElement(i, y);
        printChar(i, y, ' ');
    }
}

void dialoguePrint(int y, int x, string strings) {
    dialogueClear(y, x);
    newCursorPosition(x, y);
    printString(x, y, strings);
};



void playerMove(int spawnX, int spawnY, int bufferX, int bufferY) {
    newCursorPosition(spawnX, spawnY);
    clearElement(spawnX, spawnY);
    printChar(spawnX, spawnY, 'O');

    newCursorPosition(bufferX, bufferY);
    clearElement(bufferX, bufferY);
    printChar(bufferX, bufferY, ' ');
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void levelUp(int &playerExp, int &statAtk, int &statHealth, int &statAgility) {
    if (playerExp == 100) {
        if (_kbhit()) {
            switch (_getch()) {
            case 72: {
                statAtk += 3;
                playerExp = 0;
                break;
            }
            case 75: {
                playerExp = 0;
                statHealth += 10;
                break;
            }
            case 77: {
                playerExp = 0;
                statAgility += 2;
                break;
            }
            }
        }
    }

};