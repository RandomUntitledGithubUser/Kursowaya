#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include "func.h"

using namespace std;

struct NPC {
    string NPCName;
    string Dialogue[10];
    string Answer[10];
    int posX, posY;
    bool questTaken;
    bool questComplete;
}NPCs[4];

struct Enemy {
    string enemyName;
    int posX, posY;
    int health, curHealth , atk, exp;
    int HPposX, HPposY;
}Enemyes[3];

void mapPrint(char arr[], int m) {
    for (int j = 0; j < m; j++) {
        cout << arr[j];
    }
    cout << '\n';
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

int main()
{
    //Ввожу врагов, их корды, имена и статы
    Enemyes[0].posY = 22;
    Enemyes[0].posX = 22;
    Enemyes[0].health = 35;
    Enemyes[0].curHealth = 35;
    Enemyes[0].atk = 4;
    Enemyes[0].exp = 10;
    Enemyes[0].HPposX = 50;
    Enemyes[0].HPposY = 14;
    Enemyes[0].enemyName = "Skeleton";

    Enemyes[1].posY = 10;
    Enemyes[1].posX = 100;
    Enemyes[1].health = 50;
    Enemyes[1].atk = 8;
    Enemyes[1].exp = 25;
    Enemyes[1].enemyName = "Zombie";

    // Ввожу NPC, их корды, диалоги +идея сделать враждебных NPC(?)(не самое главное)
    NPCs[0].posY = 23;
    NPCs[0].posX = 61;
    NPCs[0].Dialogue[0] = "Hello there";
    NPCs[0].Dialogue[1] = "Do you want something?";
    NPCs[0].Dialogue[2] = "Hey, are you there?";
    NPCs[0].Dialogue[3] = "Did you here me???";
    NPCs[0].Dialogue[4] = "Bro? you okay?";
    NPCs[0].Dialogue[5] = "Why you.. Just stands.. here...";
    NPCs[0].Dialogue[6] = "And staring at me....";
    NPCs[0].Dialogue[7] = ".....";
    NPCs[0].Dialogue[8] = "Okay, im tired, just go away";
    NPCs[0].Dialogue[9] = "Man, KYS!!!!";

    NPCs[0].Answer[0] = "Hello man!";
    NPCs[0].Answer[1] = "Nuhh, don't interested!";

    NPCs[0].questComplete = false;
    NPCs[0].questTaken = false;

    NPCs[1].posY = 26;
    NPCs[1].posX = 100;
    NPCs[1].Dialogue[0] = "H";
    NPCs[1].Dialogue[1] = "Do you want something?";
    NPCs[1].Dialogue[2] = "Hey, are you there?";
    NPCs[1].Dialogue[3] = "Did you here me???";
    NPCs[1].Dialogue[4] = "Bro? you okay?";
    NPCs[1].Dialogue[5] = "Why you.. Just stands.. here...";
    NPCs[1].Dialogue[6] = "And staring at me....";
    NPCs[1].Dialogue[7] = ".....";
    NPCs[1].Dialogue[8] = "Okay, im tired, just go away";
    NPCs[1].Dialogue[9] = "Man, KYS!!!!";

    NPCs[2].posY = 9;
    NPCs[2].posX = 110;
    NPCs[2].Dialogue[0] = "ello there";
    NPCs[2].Dialogue[1] = "Do you want something?";
    NPCs[2].Dialogue[2] = "Hey, are you there?";
    NPCs[2].Dialogue[3] = "Did you here me???";
    NPCs[2].Dialogue[4] = "Bro? you okay?";
    NPCs[2].Dialogue[5] = "Why you.. Just stands.. here...";
    NPCs[2].Dialogue[6] = "And staring at me....";
    NPCs[2].Dialogue[7] = ".....";
    NPCs[2].Dialogue[8] = "Okay, im tired, just go away";
    NPCs[2].Dialogue[9] = "Man, KYS!!!!";

    NPCs[3].posX = 19;
    NPCs[3].posY = 19;
    NPCs[3].Dialogue[0] = " there";
    NPCs[3].Dialogue[1] = "Do you want something?";
    NPCs[3].Dialogue[2] = "Hey, are you there?";
    NPCs[3].Dialogue[3] = "Did you here me???";
    NPCs[3].Dialogue[4] = "Bro? you okay?";
    NPCs[3].Dialogue[5] = "Why you.. Just stands.. here...";
    NPCs[3].Dialogue[6] = "And staring at me....";
    NPCs[3].Dialogue[7] = ".....";
    NPCs[3].Dialogue[8] = "Okay, im tired, just go away";
    NPCs[3].Dialogue[9] = "Man, KYS!!!!";

    int playerAtk = 10;
    int playerExp = 0;
    int playerHealth = 100;
    int playerCurHealth = 100;
    int playerАgility = 2;
    int spawnY = 23;
    int spawnX = 59;
    int bonusАgility = 0;

    int round = 0;
    int buffer = 0;
    int bufferX;
    int bufferY;
    int counter = 0;
    int dialogueCounter = 0;
    const int n = 44;
    const int m = 156;
    const int textPlacementY = 39;
    const int textPlacementX = 3;
    bool combat = false;
    bool game = true;
    char arr[n][m];
    char combatArr[n][m];
    string statsAttack = "Attack: " + to_string(playerAtk);
    string statsHealth = "Health: " + to_string(playerCurHealth)+ "/" + to_string(playerHealth);
    string statsАgility = "Agility: " + to_string(playerАgility);
    string bufferForStats;
    bool EnemyAction = false;

    virtualF11Press();
    hideCursor();
   
    //Настройка границ и карты
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == 34 || i == n - 1) {
                arr[i][j] = '-';
            }
            else if (j == 0 || j == 119 || j == m - 1) {
                arr[i][j] = '|';
            }
            else {
                arr[i][j] = ' ';
            }
        }
    }

    //Текстовые поля в интерфейсе игрока
    fillTextField(arr[textPlacementY+1], statsАgility, 122);
    fillTextField(arr[textPlacementY], statsAttack, 122);
    fillTextField(arr[textPlacementY-1], statsHealth, 122);


    //Настройка границ и поля битвы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == 34 || i == n - 1) {
                combatArr[i][j] = '-';
            }
            else if (j == 0 || j == 119 || j == m - 1) {
                combatArr[i][j] = '|';
            }
            else {
                combatArr[i][j] = ' ';
            }
        }
    }

    //Спавн объектов на координатах


    arr[NPCs[0].posY][NPCs[0].posX] = '@';          //NPCs
    arr[NPCs[1].posY][NPCs[1].posX] = '@';
    arr[NPCs[2].posY][NPCs[2].posX] = '@';
    arr[NPCs[3].posY][NPCs[3].posX] = '@';

    arr[Enemyes[0].posY][Enemyes[0].posX] = '*';    //Enemyes

    //Первая отрисовка интерфейса
    for (int i = 0; i < n; i++) {
        mapPrint(arr[i], m);

    }
    
    newCursorPosition(spawnX, spawnY);//Player
    clearElement(spawnX, spawnY);
    printChar(spawnX, spawnY, 'O');

    while (game) {
        if (playerExp == 100) {
            if (_kbhit()) {
                switch (_getch()) {
                case 72: {
                    playerAtk += 3;
                    playerExp = 0;
                    break;
                }
                case 75: {
                    playerExp = 0;
                    playerHealth += 10;
                    break;
                }
                case 77: {
                    playerExp = 0;
                    playerАgility += 2;
                    break;
                }
                }
            }
        }
        if (_kbhit()) {
            switch (_getch()) {
                //Sleep(10);
            // Стрелка вверх
                //GetAsyncKeyState('S');
            case 72: {
                if (arr[spawnY - 1][spawnX] == ' ') {
                    bufferY = spawnY;
                    bufferX = spawnX;
                    spawnY--;
                    playerMove(spawnX, spawnY, bufferX, bufferY);
                }
                else if (arr[spawnY - 1][spawnX] == '*') {
                    system("cls");
                    combat = true;
                }
                else if (arr[spawnY - 1][spawnX] == '@') {
                    dialoguePrint(textPlacementY, textPlacementX, NPCs[NPCChoose(spawnY - 1)].Dialogue[dialogueCounter]);
                    dialogueCounter++;
                }
                if (arr[spawnY - 1][spawnX] != '@') {
                    dialogueClear(textPlacementY, textPlacementX);
                    dialogueCounter = 0;
                }
                break;
            }


                   // Стрелка вниз
            case 80: {
                if (arr[spawnY + 1][spawnX] == ' ') {
                    bufferY = spawnY;
                    bufferX = spawnX;
                    spawnY++;

                    playerMove(spawnX, spawnY, bufferX, bufferY);
                }

                else if (arr[spawnY + 1][spawnX] == '*') {
                    system("cls");
                    combat = true;
                }
                else if (arr[spawnY + 1][spawnX] == '@') {

                    buffer = NPCChoose(spawnY + 1);
                    dialoguePrint(textPlacementY, textPlacementX, NPCs[buffer = NPCChoose(spawnY + 1)].Dialogue[dialogueCounter]);
                    dialogueCounter++;
                }
                if (arr[spawnY + 1][spawnX] != '@') {
                    dialogueClear(textPlacementY, textPlacementX);
                    dialogueCounter = 0;
                }
                break;
            }
                   // Стрелка влево
            case 75: {
                if (arr[spawnY][spawnX - 1] == ' ') {
                    bufferX = spawnX;
                    bufferY = spawnY;
                    spawnX--;

                    playerMove(spawnX, spawnY, bufferX, bufferY);
                }
                else if (arr[spawnY][spawnX - 1] == '*') {
                    system("cls");
                    combat = true;
                }
                else if (arr[spawnY][spawnX - 1] == '@') {
                    //system("cls");

                    buffer = NPCChoose(spawnY);
                    dialoguePrint(textPlacementY, textPlacementX, NPCs[buffer = NPCChoose(spawnY)].Dialogue[dialogueCounter]);
                    dialogueCounter++;
                }
                if (arr[spawnY][spawnX - 1] != '@') {
                    dialogueClear(textPlacementY, textPlacementX);
                    dialogueCounter = 0;
                }
                break;
            }




                   // Стрелка вправо
            case 77: {
                //Передвижение по карте
                if (arr[spawnY][spawnX + 1] == ' ') {
                    bufferY = spawnY;
                    bufferX = spawnX;
                    spawnX++;

                    playerMove(spawnX, spawnY, bufferX, bufferY);
                }
                //Встреча с "коллизией" врага
                else if (arr[spawnY][spawnX + 1] == '*') {
                    system("cls");
                    combat = true;
                }
                //Разговор с NPC
                else if (arr[spawnY][spawnX + 1] == '@') {
                    //Поиск нужного NPC для подгрузки диалогов по его X позиции(стоило бы сделать ещё и по Y) либо переработать по компактнее
                    buffer = NPCChoose(spawnY);
                    // Вывод диалога
                    dialoguePrint(textPlacementY, textPlacementX, NPCs[buffer = NPCChoose(spawnY)].Dialogue[dialogueCounter]);
                    dialogueCounter++;

                }
                if (arr[spawnY][spawnX + 1] != '@') {
                    dialogueClear(textPlacementY, textPlacementX);
                    dialogueCounter = 0;
                }
                break;
            }
            }
        }
        // Бой
        while (combat) {
            //Первый вывод экрана боя
            if (round == 0)
            {
                round++;
                system("cls");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        cout << combatArr[i][j];
                    }
                    cout << '\n';
                }
                dialoguePrint(2, 3, "round "  + to_string(round));

                printStat(statsHealth, "Health: " + to_string(playerCurHealth) + "/" + to_string(playerHealth), textPlacementY - 1);

                //Attack
                printStat(statsAttack, "Attack: " + to_string(playerAtk), textPlacementY);

                //Аgility
                printStat(statsАgility, "Agility: " + to_string(playerАgility), textPlacementY + 1);

                dialoguePrint(Enemyes[0].HPposY, Enemyes[0].HPposX, to_string(Enemyes[0].curHealth) + "/" + to_string(Enemyes[0].health));
            }
            if (_kbhit()) {
                switch (_getch()) {
                    //Атака игрока
                    //Есть идея о шансе на успешную атаку, либо механика критов, пока не решил
                case 75: {
                    Enemyes[0].curHealth -= playerAtk;
                    dialoguePrint(Enemyes[0].HPposY, Enemyes[0].HPposX, to_string(Enemyes[0].curHealth) + "/" + to_string(Enemyes[0].health));
                    dialoguePrint(textPlacementY, textPlacementX, "Enemy has been succesfuly hit!");
                    EnemyAction = true;
                    break;
                }
                       //Защита игрока (!ПЕРЕРАБОТАТЬ!) ИДЕИ:
                       //1.Механика шансов на уклонение +новая стата "Ловкость", которая его повышает, тогда защита просто увеличит шанс уклонения
                       //и все так же будет уменьшать входящий урон вдвое
                       //2.Стата "Сила", которая будет давать поглощение %входящего урона(новый показатель брони),
                       //тогда защита увеличит плоско(либо процентно(?)) показатель брони до следующего хода
                case 77: {
                    
                    buffer = (2 * playerАgility) / 3;
                    bonusАgility = buffer;
                    buffer = (playerHealth * .05) + (playerАgility * .02 * playerHealth);
                    playerCurHealth += buffer;

                    if (playerCurHealth > playerHealth)
                        playerCurHealth = playerHealth;

                    printStat(statsАgility, "Agility: " +to_string(playerАgility + bonusАgility), textPlacementY + 1);
                    printStat(statsHealth, "Health: " + to_string(playerCurHealth) + "/" + to_string(playerHealth), textPlacementY - 1);
                    dialoguePrint(textPlacementY, textPlacementX, "Youve healed " + to_string (buffer) + "HP and gain " + to_string(bonusАgility)+" bonus agility for 1 round");
                    Sleep(1700);
                    dialoguePrint(textPlacementY, textPlacementX, "Now you feel determined and ready for fight!");
                    Sleep(1700);

                    EnemyAction = true;
                    buffer = 0;
                    break;
                }
                }
                //Победа в битве
                if (Enemyes[0].curHealth <= 0) {

                    combat = false;             //Отключает цикл боя
                    playerExp += Enemyes[0].exp;
                    arr[Enemyes[0].posY][Enemyes[0].posX] = ' ';  //Удаляет врага с карты и ставит на его место игрока
                    //spawnX = Enemyes[0].posX;
                    //spawnY = Enemyes[0].posY;
                    //arr[spawnY][spawnX] = 'O';

                    round = 0;                  //Сбрасывает счётчик раундов +небольшая задержка перед возвращением
                    Sleep(1700);
                    system("cls");


                    //Обновление текстовых значений после боя(!сделать отдельной функцией!)

                    for (int i = 0; i < n; i++) {
                        mapPrint(arr[i], m);
                    }
                    //Player
                    newCursorPosition(spawnX, spawnY);
                    clearElement(spawnX, spawnY);
                    printChar(spawnX, spawnY, 'O');

                    //Health
                    printStat(statsHealth, "Health: " + to_string(playerCurHealth)+"/"+ to_string(playerHealth), textPlacementY - 1);

                    //Attack
                    printStat(statsAttack, "Attack: " + to_string(playerAtk), textPlacementY);

                    //Аgility
                    printStat(statsАgility, "Agility: " + to_string(playerАgility), textPlacementY + 1);
                    break;
                }

                //Атака врага(пока только атака, потом будет ещё защита(?) с рандомным выбором по формуле нужного действия
                //Нашёл ошибкц, пока не разберусь как переписать, починю костылём, всё равно боёвку пока не буду делать
                if (combat && EnemyAction) {
                    if ((playerАgility+bonusАgility)*2 <= Enemyes[0].atk) {
                        Sleep(1700);
                        playerCurHealth -= Enemyes[0].atk;
                        dialoguePrint(Enemyes[0].HPposY, Enemyes[0].HPposX, to_string(Enemyes[0].curHealth) + "/" + to_string(Enemyes[0].health));
                        dialoguePrint(textPlacementY, textPlacementX, "Youve bin hit!");
                        printStat(statsHealth, "Health: " + to_string(playerCurHealth) + "/" + to_string(playerHealth), textPlacementY - 1);
                    }
                    else {
                        Sleep(1700);
                        dialoguePrint(textPlacementY, textPlacementX, "Enemie miss!");
                    }
                    
                    bonusАgility = 0;
                    printStat(statsАgility, "Agility: " + to_string(playerАgility), textPlacementY + 1);
                    EnemyAction = false;
                    round++;
                    dialoguePrint(2, 3, "round " + to_string(round));
                }
            }
            
        }
    }
    system("cls");
    cout << "I dont really think you can somehow get there...";
}



//72 Стрелка вверх
//80 Стрелка вниз
//75 Стрелка влево
//77 Стрелка вправо