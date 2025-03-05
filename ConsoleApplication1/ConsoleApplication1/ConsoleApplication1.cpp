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

void mapPrint(char arr[], int m) {
    for (int j = 0; j < m; j++) {
        cout << arr[j];
    }
    cout << '\n';
}

//int dialoguePrint() {
//    for (int j = 0; j < m; j++) {
//        if (i == textPlacementY && j == 3 && dialogueCounter < 10) {
//            cout << NPCs[buffer].Dialogue[dialogueCounter];
//            j += NPCs[buffer].Dialogue[dialogueCounter].length() - 1;
//            dialogueCounter++;
//            if (dialogueCounter >= 10)
//                dialogueCounter = 0;
//        }
//        else {
//            cout << arr[i][j];
//        }
//    }
//}

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

int main()
{
    //Ввожу врагов, их корды, имена и статы
    Enemyes[0].posY = 22;
    Enemyes[0].posX = 22;
    Enemyes[0].health = 35;
    Enemyes[0].atk = 4;
    Enemyes[0].enemyName = "Skeleton";

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

    srand(time(NULL));

    int playerAtk = 10;
    int round = 1;
    int playerHealth = 100;

    int spawnY = 23;
    int spawnX = 59;
    int moveBufferX;
    int moveBufferY;

    int buffer = 0;
    int dialogueCounter = 0;
    int enemyActionChoose;

    const int n = 45;
    const int m = 156;

    const int textPlacementY = 39;
    const int textPlacementX = 3;

    bool combat = false;
    bool isMove = false;
    bool game = true;

    char arr[n][m];
    char combatArr[n][m];

    string statsAttack = "Attack: " + to_string(playerAtk);
    string statsHealth = "Health: " + to_string(playerHealth);
    string combatText1 = "Choose youre action: left arrow - attack, right arrow - protect";
    string bufferForStats;

    bool KOSTbILb = false;

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
    //Текстовые поля в интерфейсе игрока
    for (int i = 0, j = 122; i < statsAttack.length(); j++, i++)
        arr[textPlacementY][j] = statsAttack[i];

    for (int i = 0, j = 122; i < statsHealth.length(); j++, i++)
        arr[textPlacementY-1][j] = statsHealth[i];


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
    for (int i = textPlacementX; i < combatText1.length()+3; i++) {
        combatArr[textPlacementY-1][i] = combatText1[i-3];
    }
    
    //Спавн объектов на координатах
    arr[spawnY][spawnX] = 'O';  //Player

    arr[NPCs[0].posY][NPCs[0].posX] = '@';          //NPCs
    arr[NPCs[1].posY][NPCs[1].posX] = '@';
    arr[NPCs[2].posY][NPCs[2].posX] = '@';
    arr[NPCs[3].posY][NPCs[3].posX] = '@';

    arr[Enemyes[0].posY][Enemyes[0].posX] = '*';    //Enemyes

    //Первая отрисовка интерфейса
    for (int i = 0; i < n ; i++) {
        mapPrint(arr[i], m);
    
    }

    while (game) {
        if (_kbhit()) {
            switch (_getch()) {
            // Стрелка вверх
                //GetAsyncKeyState('S');
            case 72: {
                /*moveBufferY = spawnY;
                moveBufferX = spawnX;
                spawnY -= 1;
                isMove = true;*/
                
                if (arr[spawnY - 1][spawnX] == ' ') {
                    system("cls");
                    spawnY -= 1;
                    arr[spawnY][spawnX] = 'O';
                    arr[spawnY + 1][spawnX] = ' ';
                    for (int i = 0; i < n; i++) {
                        mapPrint(arr[i], m);
                    }

                }
                else if (arr[spawnY - 1][spawnX] == '*') {
                    system("cls");
                    combat = true;
                }
                else if (arr[spawnY - 1][spawnX] == '@') {
                    system("cls");

                    NPCChoose(spawnY - 1);
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if(i == textPlacementY && j == 3 && dialogueCounter < 10) {
                                if (dialogueCounter >= 10)
                                    dialogueCounter = 0;
                                
                                cout << NPCs[buffer].Dialogue[dialogueCounter];
                                j += NPCs[buffer].Dialogue[dialogueCounter].length() - 1;
                                
                                
                            }
                            else{
                                cout << arr[i][j];
                            }
                        }
                        cout << '\n';
                    }
                    dialogueCounter++;
                }
                if (arr[spawnY - 1][spawnX] != '@')
                    dialogueCounter = 0;

                break;
            }
                   // Стрелка вниз
            case 80: {
               /* moveBufferY = spawnY;
                moveBufferX = spawnX;
                spawnY +=1;
                isMove = true;*/

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

                    NPCChoose(spawnY +1);


                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (i == textPlacementY && j == 3 && dialogueCounter < 10) {
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
                /*moveBufferX = spawnX;
                moveBufferY = spawnY; 
                spawnX =spawnX -  1;
                isMove = true;*/

                if (arr[spawnY][spawnX - 1] == ' ') {
                    system("cls");
                    spawnX--;
                    arr[spawnY][spawnX] = 'O';
                    arr[spawnY][spawnX + 1] = ' ';
                    for (int i = 0; i < n; i++) {
                        mapPrint(arr[i], m);
                    }
                }
                else if (arr[spawnY][spawnX - 1] == '*') {
                    system("cls");
                    combat = true;
                }
                else if (arr[spawnY][spawnX-1] == '@') {
                    system("cls");

                    NPCChoose(spawnX - 1);

                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (i == textPlacementY && j == 3 && dialogueCounter < 10) {
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
                    //Передвижение по карте
                    if (arr[spawnY][spawnX + 1] == ' ') {
                        system("cls");
                        spawnX++;
                        arr[spawnY][spawnX] = 'O';
                        arr[spawnY][spawnX - 1] = ' ';
                        for (int i = 0; i < n; i++) {
                            mapPrint(arr[i], m);
                        }
                    }
                    //Встреча с "коллизией" врага
                    else if (arr[spawnY][spawnX + 1] == '*') {
                        system("cls");
                        combat = true;
                    }
                    //Разговор с NPC
                    else if (arr[spawnY][spawnX + 1] == '@') {
                        system("cls");
                        //Поиск нужного NPC для подгрузки диалогов по его X позиции(стоило бы сделать ещё и по Y) либо переработать по компактнее
                        NPCChoose(spawnX+1);


                    //    // Вывод экрана с учётом диалога
                    //    // Сначало просто цикл для собственно вывода
                        for (int i = 0; i < n; i++) {
                            for (int j = 0; j < m; j++) {

                    //            // Тут если я на месте, где должен быть диалог, то собственно вывожу его и меня счётчик на длину строки для того
                    //            // чтобы рамки не сломать
                                if (i == textPlacementY && j == 3 && dialogueCounter < 10) {
                                    cout << NPCs[buffer].Dialogue[dialogueCounter];
                                    j += NPCs[buffer].Dialogue[dialogueCounter].length() - 1;

                    //                // Счётчик того, на каком я сейчас из пунктов диалого, временное решение, в будующем полностью переработаю с
                    //                // надеждой на добавление механики диалого в вариантами ответа
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
            //Первый вывод экрана боя
            if (round == 1)
            {
                system("cls");
                for (int i = 0; i < n; i++) {
                    mapPrint(combatArr[i], m);
                }
            }
            if (_kbhit()) {
                switch (_getch()) {
                //Атака игрока
                //Есть идея о шансе на успешную атаку, либо механика критов, пока не решил
                case 75: {
                    system("cls");
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (i == textPlacementY && j == 3) {
                                Enemyes[0].health -= playerAtk;
                                string buff = "Enemy hit! Health left: " + to_string(Enemyes[0].health);
                                cout << buff;
                                j += buff.length()-1;
                            }
                            else if (i == textPlacementY - 1) {
                                cout << combatArr[i-1][j];
                            }
                            else {
                                cout << combatArr[i][j];
                            }
                        }
                        cout << '\n';
                    }
                    KOSTbILb = true;
                    break;
                }
                //Защита игрока (!ПЕРЕРАБОТАТЬ!) ИДЕИ:
                //1.Механика шансов на уклонение +новая стата "Ловкость", которая его повышает, тогда защита просто увеличит шанс уклонения
                //и все так же будет уменьшать входящий урон вдвое
                //2.Стата "Сила", которая будет давать поглощение %входящего урона(новый показатель брони),
                //тогда защита увеличит плоско(либо процентно(?)) показатель брони до следующего хода
                case 77: {
                    system("cls");
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (i == textPlacementY && j == 3) {
                                playerHealth = playerHealth - (Enemyes[0].atk / 2);
                                cout << "Youve bin hit!, your health is now " << playerHealth;
                                j += 36;
                            }
                            else {
                                cout << combatArr[i][j];
                            }
                        }
                        cout << '\n';
                    }
                    KOSTbILb = true;
                    break;
                }
                }
                //Победа в битве
                if (Enemyes[0].health <= 0) {
                    
                    combat = false;             //Отключает цикл боя
                   
                    arr[spawnY][spawnX] = ' ';  //Удаляет врага с карты и ставит на его место игрока
                    spawnX = Enemyes[0].posX;
                    spawnY = Enemyes[0].posY;
                    arr[spawnY][spawnX] = 'O';
                   
                    round = 1;                  //Сбрасывает счётчик раундов +небольшая задержка перед возвращением
                    Sleep(1700);
                    system("cls");
                    

                    //Обновление текстовых значений после боя(!сделать отдельной функцией!)
                    bufferForStats = statsAttack;
                    statsAttack = "Attack: " + to_string(playerAtk);
                    if (bufferForStats.length() > statsAttack.length())
                        statsAttack += " ";

                    
                    for (int i = 0, j = 122; i < statsAttack.length(); j++, i++)
                        arr[textPlacementY][j] = statsAttack[i];

                    bufferForStats = statsHealth;
                    statsHealth = "Health: " + to_string(playerHealth);
                    if (bufferForStats.length() > statsHealth.length())
                        statsHealth += " ";

                    for (int i = 0, j = 122; i < statsHealth.length(); j++, i++)
                        arr[textPlacementY - 1][j] = statsHealth[i];
                    
                    
                    for (int i = 0; i < n; i++) {
                        mapPrint(arr[i], m);
                    }
                    break;
                }
                //Атака врага(пока только атака, потом будет ещё защита(?) с рандомным выбором по формуле нужного действия
                //Нашёл ошибкц, пока не разберусь как переписать, починю костылём, всё равно боёвку пока не буду делать
                if (combat && KOSTbILb) {
                    enemyActionChoose = rand() % 3 + 1 + to_string(playerHealth).length();
                    if (enemyActionChoose < 6) {           //Проверка на действие врага
                        Sleep(1700);
                        system("cls");
                        for (int i = 0; i < n; i++) {
                            for (int j = 0; j < m; j++) {
                                if (i == textPlacementY && j == 3) {
                                    playerHealth -= Enemyes[0].atk;
                                    string buff = "Youve bin hit!, your health is now " + to_string(playerHealth);
                                    cout << buff;
                                    j += buff.length()-1;
                                }
                                else {
                                    cout << combatArr[i][j];
                                }
                            }
                            cout << '\n';
                        }
                        
                        KOSTbILb = false;
                    }
                    else if (enemyActionChoose > 5) {
                        KOSTbILb = false;
                    }
                }

            }
            round++;
        }
    }
    system("cls");
    cout << "Hello World!";
}



//72 Стрелка вверх
//80 Стрелка вниз
//75 Стрелка влево
//77 Стрелка вправо