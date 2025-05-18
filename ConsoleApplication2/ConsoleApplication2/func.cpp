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

int NPCChoose(int posY) {
    switch (posY) {
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
    default: return -1;

    }
}

void printStat(string stat, string oldStat, int textPlacement) {
    string buffer = stat;
    stat = oldStat;

    while (buffer.length() > stat.length())
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

void levelUp(int &playerExp, int &statAtk, int &statHealth, int &statAgility, int& playerMaxExp, int& playerCurHealth) {
    dialoguePrint(39, 3, "LVL UP! Choose what to upgrade: [<] +3 Atk, [^] - + 10 HP, [>] - +2 Aglt");
   /* while (playerExp >= playerMaxExp) {
        if (_kbhit()) {
            switch (_getch()) {
            case 75: {
                statAtk += 3;
                playerExp = playerExp - playerMaxExp;
                playerMaxExp = playerMaxExp * 2;
                break;
            }
            case 73: {
                playerExp = playerExp - playerMaxExp;
                statHealth += 10;
                playerMaxExp = playerMaxExp * 2;
                break;
            }
            case 77: {
                playerExp = playerExp - playerMaxExp;
                statAgility += 2;
                playerMaxExp = playerMaxExp * 2;
                break;
            }
            }
        }
    }*/
    while (playerExp >= playerMaxExp) {
        if (_kbhit()) {
            char key = _getch();
            switch (key) {
            case 75: {
                statAtk += 3;
                break; 
            }
            case 72: {
                statHealth += 20;
                break; 
            }
            case 77: {
                statAgility += 2;
                break;
            }
            default: 
                continue;
            }
            playerExp -= playerMaxExp;
            playerMaxExp += 35;
        }
    }
    playerCurHealth = statHealth;
};

enum MenuOption { START = 0, CONTROLS, EXIT };

// Функция, отображающая экран управления
void showControls() {
    system("cls");
    cout << "Game control:\n";
    cout << "---------------------\n";
    cout << "[^]Up arrow - move up\n";
    cout << "[v]Down arrow - move down\n";
    cout << "[>]Right arrow - move right/left dialogue\n";
    cout << "[<]Left arrow - move left/next dialogue\n";
    cout << "\nPress any key to exit to main menu...";
    _getch();
}

// Функция главного меню
void showMenu() {
    int selected = START;
    const int totalOptions = 3;
    bool menuActive = true;

    while (menuActive) {
        // Очищаем экран
        system("cls");
        cout << "  _  __      _       _     _    ____                  _ \n";
        cout << " | |/ /     (_)     | |   | |  / __ \\                | | \n";
        cout << " | ' / _ __  _  __ _| |__ | |_| |  | |_   _  ___  ___| |\n";
        cout << " |  < | '_ \\| |/ _` | '_ \\| __| |  | | | | |/ _ \\/ __| __|\n";
        cout << " | . \\| | | | | (_| | | | | |_| |__| | |_| |  __/\\__ \\ |_ \n";
        cout << " |_|\\_\\_| |_|_|\\__, |_| |_|\\__|\\___\\_\\\\__,_|\\___||___/\\__|\n";
        cout << "                __/ |                                     \n";
        cout << "               |___/                                      \n";
        cout << "----------------------------------------------------------\n";
        cout << (selected == START ? ">> " : "  ") << "Start game\n";
        cout << (selected == CONTROLS ? ">> " : "  ") << "Controls\n";
        cout << (selected == EXIT ? ">> " : "  ") << "Exit\n";

        int key = _getch();

        if (key == 224) {
            key = _getch(); 
            if (key == 72) {            // Стрелка вверх
                selected = (selected - 1 + totalOptions) % totalOptions;
            }
            else if (key == 80) {     // Стрелка вниз
                selected = (selected + 1) % totalOptions;
            }
            else if (key == 77) {     // Стрелка вправо
                switch (selected) {
                case START:
                    
                    menuActive = false;
                    break;
                case CONTROLS:
                   
                    showControls();
                    break;
                case EXIT:
                   
                    exit(0);
                    break;
                }
            }
        }
    }
}