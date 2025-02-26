#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

struct NPC {
    string NPCName;
    string Dialogue[10];
    int posX, posY;
    bool friendly;
}NPCs[4];

struct Enemy {
    string enemyName;
    int posX, posY;
    int health, atk;
}Enemyes[3];


int main()
{
    Enemyes[0].posY = 22;
    Enemyes[0].posX = 22;
    Enemyes[0].health = 35;
    Enemyes[0].atk = 4;
    Enemyes[0].enemyName = "Skeleton";


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
    int playerHealth = 100;
    int spawnY = 23;
    int spawnX = 59;
    int buffer = 0;
    int dialogueCounter = 0;
    const int n = 45;
    const int m = 156;
    const int textPlacement = 39;
    bool combat = false;
    bool game = true;
    char arr[n][m];
    char combatArr[n][m];

    //Настройка границ и карты
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i==34 || i == n-1) {
                arr[i][j] = '-';
            }
            else if (j == 0 || j==119 || j == m - 1) {
                arr[i][j] = '|';
            }
            else {
                arr[i][j] = ' ';
            }
        }
    }


    //Настройка границ и поля битвы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == 34 || i == n - 1) {
                combatArr[i][j] = '-';
            }
            else if (j == 0 || j == 119 || j == m - 1) {
                arr[i][j] = '|';
            }
            else {
                combatArr[i][j] = ' ';
            }
        }
    }
    
    //Спавн объектов на координатах
    arr[spawnY][spawnX] = 'O';  //игрок
    arr[NPCs[0].posY][NPCs[0].posX] = '@';          //NPC
    arr[NPCs[1].posY][NPCs[1].posX] = '@';
    arr[NPCs[2].posY][NPCs[2].posX] = '@';
    arr[NPCs[3].posY][NPCs[3].posX] = '@';
    arr[Enemyes[0].posY][Enemyes[0].posX] = '*';    //Enemyes

    //Первая отрисовка интерфейса
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    while (game) {
        if (_kbhit()) {
            switch (_getch()) {
                
            // Стрелка вверх
            case 72: {
                if (arr[spawnY - 1][spawnX] == ' ') {
                    system("cls");
                    spawnY -= 1;
                    arr[spawnY][spawnX] = 'O';
                    arr[spawnY + 1][spawnX] = ' ';
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            cout << arr[i][j];
                        }
                        cout << '\n';
                    }

                }
                else if (arr[spawnY - 1][spawnX] == '*') {
                    system("cls");
                    combat = true;
                }
                else if (arr[spawnY - 1][spawnX] == '@') {
                    system("cls");
                    
                    switch (spawnY - 1) {
                    case 23: {
                        buffer = 0;
                        break;
                    }
                    case 26: {
                        buffer = 1;
                    }
                    case 9: {
                        buffer = 2;
                        break;
                    }
                    case 19: {
                        buffer = 3;
                        break;
                    }

                    }
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if(i == textPlacement && j == 3 && dialogueCounter < 10) {
                                cout << NPCs[buffer].Dialogue[dialogueCounter];
                                j += NPCs[buffer].Dialogue[dialogueCounter].length() - 1;
                                dialogueCounter++;
                                if (dialogueCounter >= 10)
                                    dialogueCounter = 0;
                            }
                            else{
                                cout << arr[i][j];
                            }
                        }
                        cout << '\n';
                    }
                }
                if (arr[spawnY - 1][spawnX] != '@')
                    dialogueCounter = 0;
                break;
            }


            // Стрелка вниз
            case 80: {
                if (arr[spawnY + 1][spawnX] == ' ') {
                    system("cls");
                    spawnY += 1;
                    arr[spawnY][spawnX] = 'O';
                    arr[spawnY - 1][spawnX] = ' ';
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            cout << arr[i][j];
                        }
                        cout << '\n';
                    }
                }

                else if (arr[spawnY + 1][spawnX] == '*') {
                    system("cls");
                    combat = true;
                }
                else if (arr[spawnY + 1][spawnX] == '@') {
                    system("cls");

                    switch (spawnY + 1) {
                    case 23: {
                        buffer = 0;
                        break;
                    }
                    case 26: {
                        buffer = 1;
                    }
                    case 9: {
                        buffer = 2;
                        break;
                    }
                    case 19: {
                        buffer = 3;
                        break;
                    }
                    }


                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (i == textPlacement && j == 3 && dialogueCounter < 10) {
                                cout << NPCs[buffer].Dialogue[dialogueCounter];
                                j += NPCs[buffer].Dialogue[dialogueCounter].length() - 1;
                                dialogueCounter++;
                                if (dialogueCounter >= 10)
                                    dialogueCounter = 0;
                            }
                            else {
                                cout << arr[i][j];
                            }
                        }
                        cout << '\n';
                    }
                }
                if (arr[spawnY + 1][spawnX] != '@')
                    dialogueCounter = 0;
                break;
            }
            // Стрелка влево
            case 75: {
                if (arr[spawnY][spawnX - 1] == ' ') {
                    system("cls");
                    spawnX--;
                    arr[spawnY][spawnX] = 'O';
                    arr[spawnY][spawnX + 1] = ' ';
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            cout << arr[i][j];
                        }
                        cout << '\n';
                    }
                }
                else if (arr[spawnY][spawnX - 1] == '*') {
                    system("cls");
                    combat = true;
                }
                else if (arr[spawnY][spawnX-1] == '@') {
                    system("cls");

                    switch (spawnX - 1) {
                    case 23: {
                        buffer = 0;
                        break;
                    }
                    case 26: {
                        buffer = 1;
                    }
                    case 9: {
                        buffer = 2;
                        break;
                    }
                    case 19: {
                        buffer = 3;
                        break;
                    }

                    }
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (i == textPlacement && j == 3 && dialogueCounter < 10) {
                                cout << NPCs[buffer].Dialogue[dialogueCounter];
                                j += NPCs[buffer].Dialogue[dialogueCounter].length() - 1;
                                dialogueCounter++;
                                if (dialogueCounter >= 10)
                                    dialogueCounter = 0;
                            }
                            else {
                                cout << arr[i][j];
                            }
                        }
                        cout << '\n';
                    }
                }
                if (arr[spawnY][spawnX-1] != '@')
                    dialogueCounter = 0;
                break;
            }
            // Стрелка вправо
            case 77: {
                if (arr[spawnY][spawnX + 1] == ' ') {


                    system("cls");
                    spawnX++;
                    arr[spawnY][spawnX] = 'O';
                    arr[spawnY][spawnX - 1] = ' ';
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            cout << arr[i][j];
                        }
                        cout << '\n';
                    }
                }
                else if (arr[spawnY][spawnX + 1] == '*') {
                    system("cls");
                    combat = true;
                }

                else if (arr[spawnY][spawnX+1] == '@') {
                    system("cls");
                    switch (spawnX + 1) {
                    case 23: {
                        buffer = 0;
                        break;
                    }
                    case 26: {
                        buffer = 1;
                    }
                    case 9: {
                        buffer = 2;
                        break;
                    }
                    case 19: {
                        buffer = 3;
                        break;
                    }

                    }
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (i == textPlacement && j == 3 && dialogueCounter < 10) {
                                cout << NPCs[buffer].Dialogue[dialogueCounter];
                                j += NPCs[buffer].Dialogue[dialogueCounter].length() - 1;
                                dialogueCounter++;
                                if (dialogueCounter >= 10)
                                    dialogueCounter = 0;
                            }
                            else {
                                cout << arr[i][j];
                            }
                        }
                        cout << '\n';
                    }
                }
                if (arr[spawnY][spawnX+1] != '@')
                    dialogueCounter = 0;
                break;
            }
            }
        }
        // Бой
        while (combat) {
            /*for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << combatArr[i][j];
                }
                cout << '\n';
            }*/

            if (_kbhit()) {
                switch (_getch()) {
                //Атака
                    if (Enemyes[0].health <= 0) {
                        combat = false;
                        arr[spawnY][spawnX] = ' ';
                        spawnX = Enemyes[0].posX;
                        spawnY = Enemyes[0].posY;
                        arr[spawnY][spawnX] = 'O';
                        break;
                    }
                case 75: {
                    system("cls");
                    Enemyes[0].health -= playerAtk;
                    cout << "Enemy hit! Health left: " << Enemyes[0].health;
                    break;
                }
                //Защита
                case 77: {
                    playerHealth = playerHealth - (Enemyes[0].atk / 2);
                    break;
                }
                }
                
            }
        }
    }
    system("cls");
    cout << "Hello World!";
}



//72 Стрелка вверх
//80 Стрелка вниз
//75 Стрелка влево
//77 Стрелка вправо