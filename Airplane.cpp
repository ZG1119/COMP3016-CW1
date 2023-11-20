#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameover;
const int width = 20;
const int height = 20;
int frame;
int enemyX, enemyY;  // 敌人的位置
int bulletsX[5], bulletsY[5];  // 多发子弹的位置

class player {
public:
    player() {
        health = 3;
        x = width / 2;
        y = height - 1;
    }

    int getHealth() {
        return health;
    }

    void setHealth(int& h) {
        this->health = h;
    }

    int getX() {
        return x;
    }

    void setX(int& x) {
        this->x = x;
    }

    int getY() {
        return y;
    }

    void setY(int& y) {
        this->y = y;
    }

    void act() {
        if (_kbhit()) {
            switch (_getch()) {
            case 'a':
                x--;
                break;
            case 'd':
                x++;
                break;
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
            case ' ':
                for (int i = 0; i < 5; i++) {
                    if (bulletsY[i] == 0) {
                        bulletsX[i] = x;
                        bulletsY[i] = y - 1;
                        break;
                    }
                }
                break;
            case 'q':
                gameover = true;
                break;
            }
        }
    }

private:
    int x, y, health;
};

class score {
public:
    score() {
        currentScore = 0;
        maxScore = 0;
    }

    int getCurrentScore() {
        return currentScore;
    }

    void setCurrentScore(int s) {
        currentScore = s;
    }

    int getMaxScore() {
        return maxScore;
    }

    void gameOver() {
        if (currentScore - 1  > maxScore) {
            maxScore = currentScore - 1;
        }
        currentScore = 0;
    }

private:
    int currentScore, maxScore;
};

void menu() {
    system("cls");
    cout << endl << "Welcome to the Aircraft Battle Game!" << endl;
    cout << endl << "1.Start the game";
    cout << endl << "2.Help";
    cout << endl << "0.Exit";
}

void help() {
    system("cls");
    cout << endl << "This is an aircraft battle game that players can controla plane to evade enemies or shoot bullets to destroy them.\nDestroying enemies earns points, and if the player's planeis hit by an enemy, the health will decrease. When the health\nreaches zero, the game ends." << endl;
    cout << endl << "Press 'a' to move left, 'd' to move right, 'w' to move up, 's' to move down, and 'space' to shoot bullets." << endl;
    cout << endl << "Press any key to return to the menu.";
    _getch();
}

void setup() {
    gameover = false;
    frame = 0;
    enemyX = rand() % width;
    enemyY = 0;
    for (int i = 0; i < 5; i++) {
        bulletsX[i] = 0;
        bulletsY[i] = 0;
    }
}

void draw(player& P,score& S) {
    system("cls");
    cout << endl << "Score:" << S.getCurrentScore() << "     Max Score:" << S.getMaxScore() << endl;
    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++) {
        cout << "#";
        for (int j = 0; j < width; j++) {
            if (i == P.getY() && j == P.getX())
                cout << "P"; // 玩家飞机
            else if (i == enemyY && j == enemyX)
                cout << "E"; // 敌人
            else {
                bool printBullet = false;
                for (int k = 0; k < 5; k++) {
                    if (i == bulletsY[k] && j == bulletsX[k]) {
                        cout << "|"; // 子弹
                        printBullet = true;
                    }
                }
                if (!printBullet)
                    cout << " ";
            }
        }
        cout << "#" << endl;
    }

    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl;
}

void logic(player& P, score& S) {

    P.act();

    // 移动敌人
    enemyY++;
    if (enemyY >= height) {
        enemyX = rand() % width;
        enemyY = 0;
    }

    // 移动子弹
    for (int i = 0; i < 5; i++) {
        if (bulletsY[i] > 0)
            bulletsY[i]--;
    }

    // 碰撞检测
    for (int i = 0; i < 5; i++) {
        if (bulletsX[i] == enemyX && bulletsY[i] == enemyY) {
            S.setCurrentScore(S.getCurrentScore() + 10);
            enemyX = rand() % width;
            enemyY = 0;
            bulletsX[i] = 0;
            bulletsY[i] = 0;
        }
    }

    if (P.getX() == enemyX && P.getY() == enemyY)
        gameover = true;
}

int main() {
    score Score;
    while (true) {
        menu();
        char option = _getch();
        if (option == '1') {
            setup();
            player Player;
            while (!gameover) {
                draw(Player, Score);
                logic(Player, Score);
                Score.setCurrentScore(Score.getCurrentScore() + 1);
                Sleep(150);
                frame++;
            }
            Score.gameOver();
            cout << "Game Over!" << endl;
            cout << endl << "Press 'm' to return to the menu.";
            while (true) {
                if (_getch() == 'm') {
                    break;
                }
            }
        }
        else if (option == '2') {
            help();
        }
        else if (option == '0') {
            return 0;
        }
    }
}