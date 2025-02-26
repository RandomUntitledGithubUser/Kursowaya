#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

int main()
{
    //const int n = 156;
    int spawnY = 14;
    int spawnX = 59;
    const int n = 30;
    const int m = 120;
    char arr[n][m];
    



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1) {
                arr[i][j] = '-';
            }
            else if (j == 0 || j == m - 1) {
                arr[i][j] = '|';
            }
            else {
                arr[i][j] = ' ';
            }
        }
    }
    arr[spawnY][spawnX] = 'O';
    
    for (int i = 0; i <n ; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    while (true) {
        if (_kbhit()) {
            switch (_getch()) {
                
            // Стрелка вверх
            case 72:{
                if (arr[spawnY-1][spawnX] == '-') {
                    break;
                }
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
                break;
            }
            // Стрелка вниз
            case 80: {
                if (arr[spawnY+1][spawnX] == '-') {
                    break;
                }
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
                break;
            }
            // Стрелка влево
            case 75: {
                if (arr[spawnY][spawnX-1] == '|') {
                    break;
                }
                system("cls");
                spawnX--;
                arr[spawnY][spawnX] = 'O';
                arr[spawnY][spawnX+1] = ' ';
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        cout << arr[i][j];
                    }
                    cout << '\n';
                }
                break;
            }
            // Стрелка вправо
            case 77: {
                if (arr[spawnY][spawnX + 1] == '|') {
                    break;
                }
                system("cls");
                spawnX++;
                arr[spawnY][spawnX] = 'O';
                arr[spawnY][spawnX-1] = ' ';
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        cout << arr[i][j];
                    }
                    cout << '\n';
                }
                break;
            }
            }
        }
    }
    cout << "Hello World!";
}



//72 Стрелка вверх
//80 Стрелка вниз
//75 Стрелка влево
//77 Стрелка вправо