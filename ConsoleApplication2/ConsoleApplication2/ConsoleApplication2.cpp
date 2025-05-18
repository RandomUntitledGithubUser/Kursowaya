#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include "func.h"

using namespace std;

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
    int playerАgility;
    int spawnY;
    int spawnX;
    int bonusАgility;
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

struct Door {
    int posX, posY;
    bool closed = true;
    int questID;
    int idk;
};


int main()
{
    virtualF11Press();
    hideCursor();
    showMenu();
    system("cls");

    NPC NPCs[4];
    Enemy Enemyes[4];
    Door Doors[4];

    Doors[0].posX = 25;
    Doors[0].posY = 25;
    Doors[0].questID = 0;

    Doors[1].posX = 35;
    Doors[1].posY = 5;
    Doors[1].questID = 1;

    Doors[2].posX = 35;
    Doors[2].posY = 10;
    Doors[2].questID = 2;

    Doors[3].posX = 65;
    Doors[3].posY = 20;
    Doors[3].questID = 3;


    //Ввожу врагов, их корды, имена и статы
    Enemyes[0].posY = 22;
    Enemyes[0].posX = 22;
    Enemyes[0].health = 35;
    Enemyes[0].curHealth = 35;
    Enemyes[0].atk = 4;
    Enemyes[0].exp = 25;
    Enemyes[0].HPposX = 50;
    Enemyes[0].HPposY = 8;
    Enemyes[0].enemyName = "Skeleton";

    Enemyes[1].posY = 10;
    Enemyes[1].posX = 100;
    Enemyes[1].health = 50;
    Enemyes[1].curHealth = 50;
    Enemyes[1].atk = 8;
    Enemyes[1].exp = 60;
    Enemyes[1].HPposX = 50;
    Enemyes[1].HPposY = 8;
    Enemyes[1].enemyName = "Zombie";

    Enemyes[2].posY = 11;
    Enemyes[2].posX = 11;
    Enemyes[2].health = 100;
    Enemyes[2].curHealth = 100;
    Enemyes[2].atk = 20;
    Enemyes[2].exp = 250;
    Enemyes[2].HPposX = 50;
    Enemyes[2].HPposY = 12;
    Enemyes[2].enemyName = "Mage";

    Enemyes[3].posY = 14;
    Enemyes[3].posX = 15;
    Enemyes[3].health = 225;
    Enemyes[3].curHealth = 225;
    Enemyes[3].atk = 35;
    Enemyes[3].exp = 0;
    Enemyes[3].HPposX = 50;
    Enemyes[3].HPposY = 12;
    Enemyes[3].enemyName = "Necromancer";

    // Ввожу NPC, их корды, диалоги +идея сделать враждебных NPC(?)(не самое главное)
    NPCs[0].posY = 23;
    NPCs[0].posX = 61;
    NPCs[0].Dialogue[0] = "0 Hello there! I've heard about you.";
    NPCs[0].Dialogue[1] = "1 Your'e that brave hero who's quest to free our lands from that evil necromacer?";
    NPCs[0].Dialogue[2] = "2 Thats great! But you need to prove your skills first?. I can help with that!";
    NPCs[0].Dialogue[3] = "3 Theres some skeletons who ruining my crops, and you see, im too old for the fight";
    NPCs[0].Dialogue[4] = "4 So, Youre quest will be to kill those 3 skeletons. Seems not very hard to you, am i right?";
    NPCs[0].Dialogue[5] = "5 Ill be wait for you right here";
    NPCs[0].Dialogue[6] = "6 And, of course, I will grant you some reward for that!";
    NPCs[0].Dialogue[7] = "7 Hello there! Come back when complete my quest, my man!";
    NPCs[0].Dialogue[8] = "8 Hey, youv'e did it! Really nice, there's youre reward, friend!";
    NPCs[0].Dialogue[9] = "9 Hello there!";

    NPCs[0].quest.questTarget = "Skeleton";
    NPCs[0].quest.questLineNum = 6;
    NPCs[0].quest.idleLineNum = 7;
    NPCs[0].quest.questCompleteLineNum = 9;
    NPCs[0].quest.questPreCompleteLineNum = 8;
    NPCs[0].quest.expReward = 175;
    NPCs[0].quest.questReq = 1;
    NPCs[0].quest.questID = 0;
    NPCs[0].quest.questText = "Kill 3 skeletons: ";
    NPCs[0].quest.questComplete = false;



    NPCs[1].posY = 26;
    NPCs[1].posX = 100;
    NPCs[1].Dialogue[0] = "NPC 1; pos:(26,100)";
    NPCs[1].Dialogue[1] = "Do you want something?";
    NPCs[1].Dialogue[2] = "Hey, are you there?";
    NPCs[1].Dialogue[3] = "Did you here me???";
    NPCs[1].Dialogue[4] = "Bro? you okay?";
    NPCs[1].Dialogue[5] = "Why you.. Just stands.. here...";
    NPCs[1].Dialogue[6] = "6 And staring at me....";
    NPCs[1].Dialogue[7] = "fffffffffffffffff";
    NPCs[1].Dialogue[8] = "8 Okay, im tired, just go away";
    NPCs[1].Dialogue[9] = "9 Man, KYS!!!!";

    NPCs[1].quest.questTarget = "Zombie";
    NPCs[1].quest.questLineNum = 6;
    NPCs[1].quest.idleLineNum = 7;
    NPCs[1].quest.questCompleteLineNum = 9;
    NPCs[1].quest.questPreCompleteLineNum = 8;
    NPCs[1].quest.expReward = 550;
    NPCs[1].quest.questReq = 6;
    NPCs[1].quest.questID = 1;
    NPCs[1].quest.questText = "Kill 6 zombies: ";
    NPCs[1].quest.questComplete = false;


    NPCs[2].posY = 9;
    NPCs[2].posX = 110;
    NPCs[2].Dialogue[0] = "NPC 2; pos:(9 ,110)";
    NPCs[2].Dialogue[1] = "Do you want something?";
    NPCs[2].Dialogue[2] = "Hey, are you there?";
    NPCs[2].Dialogue[3] = "Did you here me???";
    NPCs[2].Dialogue[4] = "Bro? you okay?";
    NPCs[2].Dialogue[5] = "Why you.. Just stands.. here...";
    NPCs[2].Dialogue[6] = "6 And staring at me....";
    NPCs[2].Dialogue[7] = "daadasads";
    NPCs[2].Dialogue[8] = "8 Okay, im tired, just go away";
    NPCs[2].Dialogue[9] = "9 Man, KYS!!!!";

    NPCs[2].quest.questTarget = "Mage";
    NPCs[2].quest.questLineNum = 6;
    NPCs[2].quest.idleLineNum = 7;
    NPCs[2].quest.questCompleteLineNum = 9;
    NPCs[2].quest.questPreCompleteLineNum = 8;
    NPCs[2].quest.expReward = 1500;
    NPCs[2].quest.questReq = 2;
    NPCs[2].quest.questID = 2;
    NPCs[2].quest.questText = "Kill 2 mages: ";
    NPCs[2].quest.questComplete = false;


    NPCs[3].posX = 19;
    NPCs[3].posY = 19;
    NPCs[3].Dialogue[0] = "NPC 3; pos:(19 ,19)";
    NPCs[3].Dialogue[1] = "Do you want something?";
    NPCs[3].Dialogue[2] = "Hey, are you there?";
    NPCs[3].Dialogue[3] = "Did you here me???";
    NPCs[3].Dialogue[4] = "Bro? you okay?";
    NPCs[3].Dialogue[5] = "Why you.. Just stands.. here...";
    NPCs[3].Dialogue[6] = "6 And staring at me....";
    NPCs[3].Dialogue[7] = "111111";
    NPCs[3].Dialogue[8] = "8 Okay, im tired, just go away";
    NPCs[3].Dialogue[9] = "9 Man, KYS!!!!";
    NPCs[3].quest.questComplete = false;


    NPCs[3].quest.questTarget = "Necromancer";
    NPCs[3].quest.questLineNum = 6;
    NPCs[3].quest.idleLineNum = 7;
    NPCs[3].quest.questCompleteLineNum = 9;
    NPCs[3].quest.questPreCompleteLineNum = 8;
    NPCs[3].quest.expReward = 0;
    NPCs[3].quest.questReq = 1;
    NPCs[3].quest.questID = 3;
    NPCs[3].quest.questText = "Kill necromancer: ";

    Player player{};
    player.playerAtk = 10;
    player.playerExp = 0;
    player.playerMaxExp = 25;
    player.playerHealth = 100;
    player.playerCurHealth = 100;
    player.playerАgility = 2;
    player.questsCompleted = 0;
    int spawnY = 23;
    int spawnX = 59;
    int bonusАgility = 0;
    int drwX, drwY, drwCounter;

    int round = 0;
    int buffer = 0;
    int enemyID = -1;
    int bufferX = 0;
    int bufferY = 0;
    int counter = 0;
    int dialogueCounter = 0;
    int answerCounter = 0;
    int questCompletedCounter = 0;
    int questID = -1;
    const int n = 44;
    const int m = 156;
    const int textPlacementY = 39;
    const int textPlacementX = 3;
    bool combat = false;
    bool game = true;
    bool dialogue = false;

    bool questTaken = false;
    bool questComplete = false;

    char arr[n][m];
    char combatArr[n][m];
    string statsAttack = "Attack: " + to_string(player.playerAtk);
    string statsHealth = "Health: " + to_string(player.playerCurHealth) + "/" + to_string(player.playerHealth);
    string statsАgility = "Agility: " + to_string(player.playerАgility);
    string statsExp = "Exp: " + to_string(player.playerMaxExp) + "/" + to_string(player.playerExp);
    string questsCompleted = "Quests: " + to_string(questCompletedCounter);
    string bufferForStats;
    bool EnemyAction = false;

    char heroPortrait[15][32] = { 
        "      _,.                      ", 
        "    ,` -.)                     ", 
        "   ( _/-\\\\-._                  ", 
        "  /,|`--._,-^|            ,    ", 
        "  \\_| |`-._/||          ,'|    ", 
        "    |  `-, / |         /  /    ", 
        "    |     || |        /  /     ", 
        "     `r-._||/   __   /  /      ", 
        " __,-<_     )`-/  `./  /       ", 
        "'  \\   `---'   \\   /  /        ", 
        "    |           |./  /         ", 
        "    /           //  /          ", 
        "\\_/' \\         |/  /           ",
        "-------------------------------",
        "         Brave knight          "
    };

    char skeleton[25][61]{ 
        "                              _.--\"\"-._",
        "  .                         .\"         \".",
        " / \\    ,^.         /(     Y             |      )\\",
        "/   `---. |--'\\    (  \\__..'--   -   -- -'\"\"-.-'  )",
        "|        :|    `>   '.     l_..-------.._l      .'",
        "|      __l;__ .\'      \"-.__.||_.-\'v\'-._||`\"--- - ",
        " \\  .-' | |  `              l._       _.'",
        "  \\/    | |                   l`^^'^^'j",
        "        | |                _   \\_____/     _",
        "        j |               l `--__)-'(__.--' |",
        "        | |               | /`---``-----'\"1 | ,---- - .",
        "        | |               )/  `--' '---'   \\'-'  ___  `-.",
        "        | |              //  `-'  '`----'  /  ,-'   I`.  \\",
        "      _ L |_            //  `-.-.'`-----' /  /  |   |  `. \\",
        "     '._' / \\         _/(   `/   )- ---' ;  /__.J   L.__.\\ :",
        "      `._;/7(-.......'  /        ) (     |  |            | |",
        "      `._;l _'--------_/        )-'/     :  |___.    _._./ ;",
        "        | |                 .__ )-'\\  __  \\  \\  I   1   / /",
        "        `-'                /   `-\\-(-'   \\ \\  `.|   | ,' /",
        "                           \\__  `-'    __/  `-. `---'',-'",
        "                              )-._.-- (        `-----'",
        "                             )(  l\\ o (\'..-.",
        "                       _..--\' _\'-\' \'--\'.-. |",
        "                __,,-\'\' _,,-\'\'            \\ \\",
        "              f'. _,,-\'                    \\ \\"
    };

    char zombie[25][61]{
        "                              _.--\"\"-._",
        "                            .\"         \".",
        "        ,^.                Y    O        |      )\\",
        "        | |          /\\__..'--   -   -- -'\"\"-.-'  )",
        "        | |         '.     l_..-------.._l      .'",
        "        | |           \"-.__.||_.-\'v\'-._||`\"--- - ",
        "        | |                 l._       _.'",
        "        | |                   l`^^'^^'j",
        "        | |                _   \\_____/     _",
        "        | |               l `--__)-'(__.--' |",
        "        | |               | /`---``-----'\"1 | ,---- - .",
        "        | |               )/  `--' '---'   \\'-'  ___  `-.",
        "        | |              //  `-'  '`----'  /  ,-'   I`.  \\",
        "      _-L |_-'          //  `-.-.'`-----' /  /  |   |  `. \\",
        "     '._' / \\         _/(   `/   )- ---' ;  /__.J   L.__.\\ :",
        "      `._;/7(-.......'  /        ) (     |  |            | |",
        "      `._;l _'--------_/        )-'/     :  |___.    _._./ ;",
        "        | |                 .__ )-'\\  __  \\  \\  I   1   / /",
        "        `-'                /   `-\\-(-'   \\ \\  `.|   | ,' /",
        "                           \\__  `-'    __/  `-. `---'',-'",
        "                              )-._.-- (        `-----'",
        "                             )(  l\\ o (\'..-.",
        "                       _..--\' _\'-\' \'--\'.-. |",
        "                __,,-\'\' _,,-\'\'            \\ \\",
        "              f'. _,,-\'                    \\ \\"
    };

    char mage[21][61]{
        "            *********",
        "           *************",
        "          *****     *****",
        "         ***           ***",
        "        ***             ***                   /\\",
        "        **    x     X    **                   \\/",
        "        **       v       **                  _][_",
        "        ***             ***                   [] ",
        "        ****   ^^^^^   ****                  [  ]  ",
        "        *****         *****                  [  ]",
        "        ******       ********                ]  [",
        "      *********     **********               |  |",
        "   *************   ************              |  |",
        "  *************** ****************          *|  |",
        " ************************************    ****| <=>",
        "*********************************************|<===>",
        "*********************************************| <==>",
        "***************************** ***************| <=>",
        "******************************* *************|  |",
        "********************************** **********|  |*",
        "*********************************** *********|  |"
    };


    char necromancer[21][61]{
        "            *********",
        "           *************",
        "          *****     *****",
        "         ***    Z      ***                    /\\",
        "        ***             ***                  |  |",
        "        **  <X>     <->  **                  \\  /",
        "        **               **                  _][_",
        "        ***      ^      ***                   [] ",
        "        ****   ^^^^^   ****                  [  ]  ",
        "        *****  ^^^^^  *****                  [  ]",
        "        ******   V   ********                ]  [",
        "      *********     **********               |  |",
        "   *************   ************              |  |",
        "  *************** ****************          *|  |",
        " ************************************    ****| <=>",
        "*********************************************|<===>",
        "*********************************************| <==>",
        "***************************** ***************| <=>",
        "******************************* *************|  |",
        "********************************** **********|  |*",
        "*********************************** *********|  |"
    };
    

    //Настройка границ и карты
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == 34 || i == n - 1 || ((j > 120 && j < m - 2) && (i == 1 || i == 15))) {
                arr[i][j] = '-';
            }
            else if (j == 0 || j == 119 || ((j == 121 || j == m - 3) && (i > 1 && i < 15)) ||  j == m - 1) {
                arr[i][j] = '|';
            }
            else {
                arr[i][j] = ' ';
            }
        }
    }
    

   

    //Текстовые поля в интерфейсе игрока
    fillTextField(arr[textPlacementY + 1], statsАgility, 122);
    fillTextField(arr[textPlacementY], statsAttack, 122);
    fillTextField(arr[textPlacementY - 1], statsHealth, 122);
    fillTextField(arr[textPlacementY - 2], statsExp, 122);
    fillTextField(arr[textPlacementY - 3], questsCompleted, 122);
    fillTextField(arr[textPlacementY - 15], "Quest: ", 122);
    fillTextField(arr[textPlacementY - 14], "No quest", 122);


    //Настройка границ и поля битвы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == 34 || i == n - 1 || ((j > 120 && j < m - 2) && (i == 1 || i == 15))) {
                combatArr[i][j] = '-';
            }
            else if (j == 0 || j == 119 || ((j == 121 || j == m - 3) && (i > 1 && i < 15)) || j == m - 1) {
                combatArr[i][j] = '|';
            }
            else {
                combatArr[i][j] = ' ';
            }
        }
    }
    //Вывод арта персонажа
    for (int i = 2, k = 0; i < 17; i++, k++) {
        for (int j = 122, l = 0; j < m - 3; j++, l++) {
            arr[i][j] = heroPortrait[k][l];
            combatArr[i][j] = heroPortrait[k][l];
        }
    }
    //Текстовые поля в интерфейсе игрока во время боя
    fillTextField(combatArr[textPlacementY + 1], statsАgility, 122);
    fillTextField(combatArr[textPlacementY], statsAttack, 122);
    fillTextField(combatArr[textPlacementY - 1], statsHealth, 122);
    fillTextField(combatArr[textPlacementY - 2], statsExp, 122);
    fillTextField(combatArr[textPlacementY - 3], questsCompleted, 122);
    fillTextField(combatArr[textPlacementY - 15], "Quest: ", 122);
    fillTextField(combatArr[textPlacementY - 14], "No quest", 122);

    //Спавн объектов на координатах
    arr[Doors[0].posY][Doors[0].posX] = 'D';
    arr[Doors[1].posY][Doors[1].posX] = 'D';
    arr[Doors[2].posY][Doors[2].posX] = 'D';
    arr[Doors[3].posY][Doors[3].posX] = 'D';

    arr[NPCs[0].posY][NPCs[0].posX] = '@';          //NPCs
    arr[NPCs[1].posY][NPCs[1].posX] = '@';
    arr[NPCs[2].posY][NPCs[2].posX] = '@';
    arr[NPCs[3].posY][NPCs[3].posX] = '@';

    arr[Enemyes[0].posY][Enemyes[0].posX] = '*';
    arr[Enemyes[0].posY + 3][Enemyes[0].posX + 5] = '*';
    arr[Enemyes[0].posY + 7][Enemyes[0].posX - 3] = '*';   
    arr[Enemyes[1].posY][Enemyes[1].posX] = 'x'; 
    arr[Enemyes[1].posY + 2][Enemyes[1].posX - 3] = 'x'; 
    arr[Enemyes[1].posY + 5][Enemyes[1].posX + 4] = 'x';
    arr[Enemyes[2].posY][Enemyes[2].posX] = '+';
    arr[Enemyes[2].posY + 1][Enemyes[2].posX + 56] = '+';
    arr[Enemyes[2].posY + 1][Enemyes[2].posX + 56] = '#';//Enemyes

    //Первая отрисовка интерфейса
    mapPrint((char*)arr, m, n);


    newCursorPosition(spawnX, spawnY);//Player
    clearElement(spawnX, spawnY);
    printChar(spawnX, spawnY, 'O');

    while (game) {
        if (player.playerExp >= player.playerMaxExp) {
            //Обновление текстовых полей после увеличесн
            levelUp(player.playerExp, player.playerAtk, player.playerHealth, player.playerАgility, player.playerMaxExp, player.playerCurHealth);
            //HP
            printStat(statsHealth, "Health: " + to_string(player.playerCurHealth) + "/" + to_string(player.playerHealth), textPlacementY - 1);

            //Attack
            printStat(statsAttack, "Attack: " + to_string(player.playerAtk), textPlacementY);

            //Аgility
            printStat(statsАgility, "Agility: " + to_string(player.playerАgility), textPlacementY + 1);

            //Exp
            printStat(statsHealth, "Exp: " + to_string(player.playerMaxExp) + "/" + to_string(player.playerExp), textPlacementY - 2);

            dialogueClear(39, 3);
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
                    dialogueClear(39, 3);
                    playerMove(spawnX, spawnY, bufferX, bufferY);
                }
                else if (arr[spawnY - 1][spawnX] == '*' || arr[spawnY - 1][spawnX] == 'x' || arr[spawnY - 1][spawnX] == '+' || arr[spawnY - 1][spawnX] == '#') {
                    system("cls");
                    bufferY = spawnY - 1;
                    bufferX = spawnX;
                    combat = true;
                }
                else if (arr[spawnY - 1][spawnX] == '@') {
                    dialogue = true;
                    buffer = NPCChoose(spawnY - 1);
                }
                else if (arr[spawnY - 1][spawnX] == 'D') {
                    for (int i = 0; i < 4; i++) {
                        if (Doors[i].posY == spawnY - 1 && Doors[i].posX == spawnX && Doors[i].questID == questID) {
                            bufferY = spawnY;
                            bufferX = spawnX;
                            spawnY--;
                            arr[Doors[i].posY][Doors[i].posX] = ' ';
                            dialogueClear(39, 3);
                            playerMove(spawnX, spawnY, bufferX, bufferY);
                        }
                    }
                }
                break;
            }


                   // Стрелка вниз
            case 80: {
                if (arr[spawnY + 1][spawnX] == ' ') {
                    bufferY = spawnY;
                    bufferX = spawnX;
                    spawnY++;
                    dialogueClear(39, 3);
                    playerMove(spawnX, spawnY, bufferX, bufferY);
                }

                else if (arr[spawnY + 1][spawnX] == '*' || arr[spawnY + 1][spawnX] == 'x' || arr[spawnY + 1][spawnX] == '+' || arr[spawnY + 1][spawnX] == '#') {
                    system("cls");
                    bufferY = spawnY + 1;
                    bufferX = spawnX;
                    combat = true;
                }
                else if (arr[spawnY + 1][spawnX] == '@') {
                    dialogue = true;
                    buffer = NPCChoose(spawnY + 1);
                }
                else if (arr[spawnY + 1][spawnX] == 'D') {
                    for (int i = 0; i < 4; i++) {
                        if (Doors[i].posY == spawnY + 1 && Doors[i].posX == spawnX && Doors[i].questID == questID) {
                            bufferY = spawnY;
                            bufferX = spawnX;
                            spawnY++;
                            arr[Doors[i].posY][Doors[i].posX] = ' ';
                            dialogueClear(39, 3);
                            playerMove(spawnX, spawnY, bufferX, bufferY);
                        }
                    }
                }

                
                break;
            }
                   // Стрелка влево
            case 75: {
                if (arr[spawnY][spawnX - 1] == ' ') {
                    bufferX = spawnX;
                    bufferY = spawnY;
                    spawnX--;
                    dialogueClear(39, 3);
                    playerMove(spawnX, spawnY, bufferX, bufferY);
                }
                else if (arr[spawnY][spawnX - 1] == '*' || arr[spawnY][spawnX - 1] == 'x' || arr[spawnY][spawnX - 1] == '+' || arr[spawnY][spawnX - 1] == '#') {
                    system("cls");
                    bufferY = spawnY;
                    bufferX = spawnX - 1;
                    combat = true;
                }
                else if (arr[spawnY][spawnX - 1] == '@') {
                    dialogue = true;
                    buffer = NPCChoose(spawnY);
                }
                else if (arr[spawnY][spawnX - 1] == 'D') {
                    for (int i = 0; i < 4; i++) {
                        if (Doors[i].posY == spawnY && Doors[i].posX == spawnX-1 && Doors[i].questID == questID) {
                            bufferY = spawnY;
                            bufferX = spawnX;
                            spawnX--;
                            arr[Doors[i].posY][Doors[i].posX] = ' ';
                            dialogueClear(39, 3);
                            playerMove(spawnX, spawnY, bufferX, bufferY);
                        }
                    }
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
                    dialogueClear(39, 3);
                    playerMove(spawnX, spawnY, bufferX, bufferY);
                }
                //Встреча с "коллизией" врага
                else if (arr[spawnY][spawnX + 1] == '*' || arr[spawnY][spawnX + 1] == 'x' || arr[spawnY][spawnX + 1] == '+' || arr[spawnY][spawnX + 1] == '#') {
                    system("cls");
                    bufferY = spawnY;
                    bufferX = spawnX + 1;
                    combat = true;
                }
                //NPC
                else if (arr[spawnY][spawnX + 1] == '@') {
                    dialogue = true;
                    buffer = NPCChoose(spawnY);
                }
                //Дверь встреча
                else if (arr[spawnY][spawnX + 1] == 'D') {
                    for (int i = 0; i < 4; i++) {
                        if (Doors[i].posY == spawnY && Doors[i].posX == spawnX + 1 && Doors[i].questID == questID) {
                            bufferY = spawnY;
                            bufferX = spawnX;
                            spawnX++;
                            arr[Doors[i].posY][Doors[i].posX] = ' ';
                            dialogueClear(39, 3);
                            playerMove(spawnX, spawnY, bufferX, bufferY);
                        }
                    }
                }
                
                break;
            }
            }
        }

        //if (_kbhit()) {
        //    char key = _getch();
        //    switch (key) {
        //    case 72:  // стрелка вверх
        //        processPlayerMovement(arr, n, m,
        //            spawnX, spawnY,
        //            0, -1,
        //            combat, dialogue, buffer, bufferX, bufferY,
        //            questID, Doors, 4);
        //        break;
        //    case 80:  // стрелка вниз
        //        processPlayerMovement(arr, n, m,
        //            spawnX, spawnY,
        //            0, 1,
        //            combat, dialogue, buffer, bufferX, bufferY,
        //            questID, Doors, 4);
        //        break;
        //    case 75:  // стрелка влево
        //        processPlayerMovement(arr, n, m,
        //            spawnX, spawnY,
        //            -1, 0,
        //            combat, dialogue, buffer, bufferX, bufferY,
        //            questID, Doors, 4);
        //        break;
        //    case 77:  // стрелка вправо
        //        processPlayerMovement(arr, n, m,
        //            spawnX, spawnY,
        //            1, 0,
        //            combat, dialogue, buffer, bufferX, bufferY,
        //            questID, Doors, 4);
        //        break;
        //    }
        //}
        //Диалог
        while (dialogue) {
            //If wrong NPC ID
            if (buffer < 0 || buffer > 4) {
                dialogue = false;
                continue;
            }
            //If [buffer] NPCs quest is complete
            if (NPCs[buffer].quest.questComplete == true) {
                dialoguePrint(textPlacementY, textPlacementX, NPCs[buffer].Dialogue[NPCs[buffer].quest.questCompleteLineNum]);
                dialogue = false;
            }
            //if not
            else {
                //If quest taken, but not complete
                if (questTaken && !questComplete && buffer == questID) {
                    dialoguePrint(textPlacementY, textPlacementX, NPCs[buffer].Dialogue[NPCs[buffer].quest.idleLineNum]);
                    dialogue = false;
                }
                //if quest not taken and not comlete yet
                else if (!questTaken && !questComplete && !NPCs[buffer].quest.questComplete) {
                    //Outing first line
                    if (dialogueCounter == 0) {
                        dialoguePrint(textPlacementY, textPlacementX, NPCs[buffer].Dialogue[0]);
                        dialogueCounter++;
                    }
                    //if reach "quest line"
                    if (dialogueCounter == NPCs[buffer].quest.idleLineNum) {
                        questTaken = true;
                        dialogue = false;
                        questID = NPCs[buffer].quest.questID;
                        printStat("No quest", NPCs[questID].quest.questText + to_string(NPCs[questID].quest.questCounter), textPlacementY - 14);
                        fillTextField(arr[textPlacementY - 14], NPCs[questID].quest.questText + to_string(NPCs[questID].quest.questCounter), 122);
                        fillTextField(combatArr[textPlacementY - 14], NPCs[questID].quest.questText + to_string(NPCs[questID].quest.questCounter), 122);

                    }
                    //Outing all other lines
                    if (_kbhit()) {
                        switch (_getch()) {
                        case 75: {
                            dialoguePrint(textPlacementY, textPlacementX, NPCs[buffer].Dialogue[dialogueCounter]);
                            dialogueCounter++;
                            break;
                        }
                        case 77: {
                            dialogueCounter = 0;
                            dialogue = false;
                            break;
                        }
                        default: continue;
                        }
                    }
                }
                //Wrong NPC dialogue start(not that whos quest is taken)
                else if (questID != buffer) {
                    dialoguePrint(textPlacementY, textPlacementX, NPCs[buffer].Dialogue[NPCs[buffer].quest.idleLineNum]);
                    dialogue = false;
                }
                //Quest complete
                else if (questTaken && questComplete && buffer == questID) {
                    dialogueCounter = NPCs[buffer].quest.questPreCompleteLineNum;
                    dialoguePrint(textPlacementY, textPlacementX, NPCs[buffer].Dialogue[dialogueCounter]);
                    dialogueCounter++;
                    while (dialogueCounter < NPCs[buffer].quest.questCompleteLineNum) {
                        if (_kbhit()) {
                            switch (_getch()) {
                            case 75: {
                                dialoguePrint(textPlacementY, textPlacementX, NPCs[buffer].Dialogue[dialogueCounter]);
                                dialogueCounter++;
                                break;
                            }
                            }
                        }
                    }
                    //Обновление всех флагов и текстовых полей по завершению квеста
                    Sleep(1700);
                    printStat(NPCs[questID].quest.questText + to_string(NPCs[questID].quest.questCounter), "No quest", textPlacementY - 14);
                    fillTextField(arr[textPlacementY - 14], "                                 ", 122);
                    fillTextField(combatArr[textPlacementY - 14], "                                 ", 122);
                    fillTextField(arr[textPlacementY - 14], "No quest", 122);
                    fillTextField(combatArr[textPlacementY - 14], "No quest", 122);
                    questTaken = false;
                    questComplete = false;
                    NPCs[questID].quest.questComplete = true;
                    dialogue = false;
                    questID = -1;
                    dialogueCounter = 0;
                    player.questsCompleted++;
                    fillTextField(arr[textPlacementY - 3], "Quests: " + to_string(player.questsCompleted), 122);
                    fillTextField(combatArr[textPlacementY - 3], "Quests: " + to_string(player.questsCompleted), 122);
                    printStat(statsHealth, "Quests: " + to_string(player.questsCompleted), textPlacementY - 3);
                    player.playerExp += NPCs[buffer].quest.expReward;
                }
            }
            //72 Стрелка вверх
            //80 Стрелка вниз
            //75 Стрелка влево
            //77 Стрелка вправо 
        }
        // Бой
        while (combat) {
            //Первый вывод экрана боя
            if (round == 0)
            {
                round++;
                switch (arr[bufferY][bufferX]) {
                case '*': {
                    drwX = -32;
                    drwY = 1;
                    drwCounter = 25;
                    enemyID = 0;

                    break;
                }
                case 'x': {
                    drwX = -32;
                    drwY = 1;
                    enemyID = 1;
                    drwCounter = 25;
                    break;
                }
                case '+': {
                    drwX = -32;
                    drwY = 1;
                    enemyID = 2;
                    drwCounter = 21;
                    break;
                }
                case '#': {
                    drwX = -32;
                    drwY = 1;
                    enemyID = 3;
                    drwCounter = 21;
                    break;
                }
                default: enemyID = 0;
                }
                system("cls");
                mapPrint((char*)combatArr, m, n);
                //Вывод арта врага
                int Y = Enemyes[enemyID].HPposY + drwY;
                int X = Enemyes[enemyID].HPposX + drwX;
                for (int i = 0; i < drwCounter; i++) {
                    for (int j = 0; j < 61; j++) {
                        clearElement(X, Y);
                        switch (enemyID) {
                        case 0: {
                            printChar(X, Y, skeleton[i][j]);
                            break; 
                        }
                        case 1: {
                            printChar(X, Y, zombie[i][j]);
                            break;
                        }
                        case 2: {
                            printChar(X, Y, mage[i][j]);
                            break;
                        }
                        case 3: {
                            printChar(X, Y, necromancer[i][j]);
                            break;
                        }
                        }
                        X++;
                    }
                    Y++;
                    X = Enemyes[enemyID].HPposX + drwX;
                }

                dialoguePrint(2, 3, "round " + to_string(round));

                printStat(statsHealth, "Health: " + to_string(player.playerCurHealth) + "/" + to_string(player.playerHealth), textPlacementY - 1);

                //Attack
                printStat(statsAttack, "Attack: " + to_string(player.playerAtk), textPlacementY);

                //Аgility
                printStat(statsАgility, "Agility: " + to_string(player.playerАgility), textPlacementY + 1);

                //Exp
                printStat(statsHealth, "Exp: " + to_string(player.playerMaxExp) + "/" + to_string(player.playerExp), textPlacementY - 2);

                dialoguePrint(Enemyes[enemyID].HPposY, Enemyes[enemyID].HPposX, to_string(Enemyes[enemyID].curHealth) + "/" + to_string(Enemyes[enemyID].health));

                dialoguePrint(textPlacementY, textPlacementX, "Choose youre action: [<] - Attack, [>] - Block + heal");
            }
            
            if (_kbhit()) {   
                char key = _getch();
                switch (key) {
                    //Атака игрока
                    //Есть идея о шансе на успешную атаку, либо механика критов, пока не решил
                case 75: {
                    Enemyes[enemyID].curHealth -= player.playerAtk;
                    if (Enemyes[enemyID].curHealth < 0)
                        Enemyes[enemyID].curHealth = 0;
                    dialoguePrint(Enemyes[enemyID].HPposY, Enemyes[enemyID].HPposX, to_string(Enemyes[enemyID].curHealth) + "/" + to_string(Enemyes[enemyID].health));

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
                    //Формулы для получения бонусной ловкости и лечения
                    buffer = (2 * player.playerАgility) / 3;
                    bonusАgility = buffer;
                    buffer = (player.playerHealth * .05) + (player.playerАgility * .02 * player.playerHealth);
                    player.playerCurHealth += buffer;

                    if (player.playerCurHealth > player.playerHealth)
                        player.playerCurHealth = player.playerHealth;

                    printStat(statsАgility, "Agility: " + to_string(player.playerАgility + bonusАgility), textPlacementY + 1);
                    printStat(statsHealth, "Health: " + to_string(player.playerCurHealth) + "/" + to_string(player.playerHealth), textPlacementY - 1);
                    dialoguePrint(textPlacementY, textPlacementX, "Youve healed " + to_string(buffer) + "HP and gain " + to_string(bonusАgility) + " bonus agility for 1 round");
                    Sleep(1700);
                    dialoguePrint(textPlacementY, textPlacementX, "Now you feel determined and ready for fight!");
                    Sleep(1700);

                    EnemyAction = true;
                    buffer = 0;
                    break;
                }
                }
                //Победа в битве
                if (Enemyes[enemyID].curHealth <= 0) {

                    combat = false;             //Отключает цикл боя
                    EnemyAction = false;

                    player.playerExp += Enemyes[enemyID].exp + 2 * round;
                    Enemyes[enemyID].curHealth = Enemyes[enemyID].health;

                    arr[bufferY][bufferX] = ' ';  //Удаляет врага с карты и ставит на его место игрока
                    //Проверка для квеста
                    if (questID > -1 && Enemyes[enemyID].enemyName == NPCs[questID].quest.questTarget) {
                        NPCs[questID].quest.questCounter++;
                        printStat(NPCs[questID].quest.questText + " ", NPCs[questID].quest.questText + to_string(NPCs[questID].quest.questCounter), textPlacementY - 14);
                        fillTextField(arr[textPlacementY - 14], NPCs[questID].quest.questText + to_string(NPCs[questID].quest.questCounter), 122);
                    }
                    //Проверка на выполнение квеста
                    if (questID > -1 && NPCs[questID].quest.questCounter == NPCs[questID].quest.questReq) {
                        questComplete = true;
                    }
                    //spawnX = Enemyes[0].posX;
                    //spawnY = Enemyes[0].posY;
                    //arr[spawnY][spawnX] = 'O';

                    round = 0;                  //Сбрасывает счётчик раундов +небольшая задержка перед возвращением
                    Sleep(1700);
                    system("cls");


                    //Обновление текстовых значений после боя
                    mapPrint((char*)arr, m, n);

                    //Player
                    newCursorPosition(spawnX, spawnY);
                    clearElement(spawnX, spawnY);
                    printChar(spawnX, spawnY, 'O');

                    //Health
                    printStat(statsHealth, "Health: " + to_string(player.playerCurHealth) + "/" + to_string(player.playerHealth), textPlacementY - 1);

                    //Attack
                    printStat(statsAttack, "Attack: " + to_string(player.playerAtk), textPlacementY);

                    //Аgility
                    printStat(statsАgility, "Agility: " + to_string(player.playerАgility), textPlacementY + 1);

                    //Exp
                    printStat(statsHealth, "Exp: " + to_string(player.playerMaxExp) + "/" + to_string(player.playerExp), textPlacementY - 2);
                    break;
                }

                //Атака врага
                if (combat && EnemyAction) {
                    if ((player.playerАgility + bonusАgility) * 2 <= Enemyes[enemyID].atk) {
                        Sleep(1700);
                        player.playerCurHealth -= Enemyes[enemyID].atk;
                        dialoguePrint(Enemyes[enemyID].HPposY, Enemyes[enemyID].HPposX, to_string(Enemyes[enemyID].curHealth) + "/" + to_string(Enemyes[enemyID].health));
                        dialoguePrint(textPlacementY, textPlacementX, "Youve bin hit!");
                        printStat(statsHealth, "Health: " + to_string(player.playerCurHealth) + "/" + to_string(player.playerHealth), textPlacementY - 1);
                    }
                    else {
                        Sleep(1700);
                        dialoguePrint(textPlacementY, textPlacementX, "Enemie miss!");
                    }
                    //Обновление флагов
                    bonusАgility = 0;
                    printStat(statsАgility, "Agility: " + to_string(player.playerАgility), textPlacementY + 1);
                    EnemyAction = false;
                    round++;
                    Sleep(1700);
                    dialoguePrint(2, 3, "round " + to_string(round));
                    dialoguePrint(textPlacementY, textPlacementX, "Choose youre action: [<] - Attack, [>] - Block + heal");
                }
                //Проигрышь
                if (player.playerCurHealth <= 0) {
                    system("cls");
                    cout << "\n\n\n\n\n\n                     __     ______  _    _   _      ____   _____ ______ \n                     \\ \\   / / __ \\| |  | | | |    / __ \\ / ____|  ____|\n                      \\ \\_/ / |  | | |  | | | |   | |  | | (___ | |__   \n                       \\   /| |  | | |  | | | |   | |  | |\\___ \\|  __|  \n                        | | | |__| | |__| | | |___| |__| |____) | |____ \n                        |_|  \\____/ \\____/  |______\\____/|_____/|______|\n\n\n\n";
                    game = false;
                    combat = false;
                    system("pause");
                }
            }

        }
    }
    system("cls");
    cout << "I dont really think you can somehow get here, unless...";
}



//72 Стрелка вверх
//80 Стрелка вниз
//75 Стрелка влево
//77 Стрелка вправо