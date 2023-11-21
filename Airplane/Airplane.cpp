#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>

using namespace std;

// Class representing the game map
class map {
public:
    map() {
        // Initialize default values for map properties
        width = 20;
        height = 20;
        sleepTime = 200;
        frame = 0;
        gameover = false;
    }

    // Getter and setter methods for map properties
    int getWidth() {
        return width;
    }

    void setWidth(int W) {
        width = W;
    }

    int getHeight() {
        return height;
    }

    void setHeight(int H) {
        height = H;
    }

    int getSleepTime() {
        return sleepTime;
    }

    void setSleepTime(int T) {
        sleepTime = T;
    }

    int getFrame() {
        return frame;
    }

    void setFrame(int F) {
        frame = F;
    }

    bool getGameover() {
        return gameover;
    }

    void setGameover(bool G) {
        gameover = G;
    }

    bool getPrintBullet() {
        return printBullet;
    }

    void setPrintBullet(bool P) {
        printBullet = P;
    }

    bool getPrintEnemy() {
        return printEnemy;
    }

    void setPrintEnemy(bool P) {
        printEnemy = P;
    }

    bool getPringPlayer() {
        return printPlayer;
    }

    void setPrintPlayer(bool P) {
        printPlayer = P;
    }

    int getCollision() {
        return collision;
    }

    void setCollision(int C) {
        collision = C;
    }

    int getDeleteEnemy() {
        return deleteEnemy;
    }

    void setDeleteEnemy(int DE) {
        deleteEnemy = DE;
    }

    int getDeleteBullet() {
        return deleteBullet;
    }

    void setDeleteBullet(int DB) {
        deleteBullet = DB;
    }

private:
    int width, height, sleepTime, frame, collision, deleteEnemy, deleteBullet;
    bool gameover, printBullet, printEnemy, printPlayer;
};

// Class representing bullets
class bullet {
public:
    bullet(int X, int Y) {
        x = X;
        y = Y;
    }

    // Getter and setter methods for bullet properties
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    void setY(int Y) {
        y = Y;
    }
private:
    int x, y;
};

// Class representing the player
class player {
public:
    player(map& M) {
        // Initialize default values for player properties
        health = 3;
        x = M.getWidth() / 2;
        y = M.getHeight() - 1;
        direction = '0';
    }

    // Getter and setter methods for player properties
    int getHealth() {
        return health;
    }

    void setHealth(int H) {
        health = H;
    }

    int getX() {
        return x;
    }

    void setX(int& X) {
        x = X;
    }

    int getY() {
        return y;
    }

    void setY(int& Y) {
        y = Y;
    }

    char getDirection() {
        return direction;
    }

    void setDirection(char D) {
        direction = D;
    }

    // Method for player actions (movement and shooting)
    void act(map& M, vector<bullet>& bullets) {
        if (_kbhit()) {
            switch (_getch()) {
            case 'a':
                if (x > 0) {
                    x--;
                } else {
                    x = 0;
                }
                direction = 'a';
                break;
            case 'd':
                if (x < M.getWidth() - 1) {
                    x++;
                } else {
                    x = M.getWidth() - 1;
                }
                direction = 'd';
                break;
            case 'w':
                if (y > 0) {
                    y--;
                } else {
                    y = 0;
                }
                direction = 'w';
                break;
            case 's':
                if (y < M.getHeight() - 1) {
                    y++;
                } else {
                    y = M.getHeight() - 1;
                }
                direction = 's';
                break;
            case ' ':
                bullets.push_back(bullet(x, y));
                break;
            case 27:
                M.setGameover(true);
                break;
            default:
                break;
            }
        }
    }

private:
    int x, y, health;
    char direction;
};

// Class representing enemies
class enemy {
public:
    enemy(map& M) {
        x = rand() % M.getWidth();
        y = 0;
    }

    // Getter and setter methods for enemy properties
    int getX() {
        return x;
    }

    void setX(int X) {
        x = X;
    }

    int getY() {
        return y;
    }

    void setY(int Y) {
        y = Y;
    }

private:
    int x, y;
};

// Class representing the player's score
class score {
public:
    score() {
        currentScore = 0;
        maxScore = 0;
    }

    // Getter and setter methods for score properties
    int getCurrentScore() {
        return currentScore;
    }

    void setCurrentScore(int s) {
        currentScore = s;
    }

    int getMaxScore() {
        return maxScore;
    }

    // Method to handle end of game and update max score
    void gameOver() {
        if (currentScore > maxScore) {
            maxScore = currentScore;
        }
        currentScore = 0;
    }

private:
    int currentScore, maxScore;
};

// Function to display the main menu
void menu() {
    system("cls");
    cout << endl << "Welcome to the Aircraft Battle Game!" << endl;
    cout << endl << "1.Start the game";
    cout << endl << "2.Help";
    cout << endl << "0.Exit";
}

// Function to display game instructions
void help() {
    system("cls");
    cout << endl << "This is an aircraft battle game that players can controla plane to evade enemies or shoot bullets to destroy them.\nDestroying enemies earns points, and if the player's planeis hit by an enemy, the health will decrease. When the\nhealth reaches zero, the game ends." << endl << endl;
    cout << endl << "In the game, 'P' represents the player-controlled aircraft, 'E' represents enemies, '*' represents bullets shot by\nthe player, and '#' represents the game boundaries." << endl << endl;
    cout << endl << "Press 'a' to move left, 'd' to move right, 'w' to move up, 's' to move down, 'esc' to end the game immediately,\nand 'space' to shoot bullets." << endl << endl;
    cout << endl << "Press any key to return to the menu." << endl;
    _getch();
}

// Function to draw the game screen
void draw(map& M, player& P,score& S, vector<enemy>& E, vector<bullet>& bullets) {
    try {
        system("cls");
        cout << endl << "Score:" << S.getCurrentScore() << "   Max Score:" << S.getMaxScore() << endl;
        for (int i = 0; i < M.getWidth() + 2; i++) {
            cout << "#";
        }
        cout << endl;

        M.setPrintPlayer(false);
        for (int i = 0; i < M.getHeight(); i++) {
            cout << "#";
            for (int j = 0; j < M.getWidth(); j++) {
                if (!M.getPringPlayer() && i == P.getY() && j == P.getX()) {
                    cout << "P";
                    M.setPrintPlayer(true);
                }
                else {
                    M.setPrintEnemy(false);
                    for (int e = 0; e < E.size(); e++) {
                        if (i == E[e].getY() && j == E[e].getX()) {
                            cout << "E";
                            M.setPrintEnemy(true);
                            break;
                        }
                    }
                    if (!M.getPrintEnemy()) {
                        M.setPrintBullet(false);
                        for (int k = 0; k < bullets.size(); k++) {
                            if (i == bullets[k].getY() && j == bullets[k].getX()) {
                                cout << "*";
                                M.setPrintBullet(true);
                                break;
                            }
                        }
                        if (!M.getPrintBullet()) {
                            cout << " ";
                        }
                    }
                }
            }
            cout << "#" << endl;
        }
        for (int i = 0; i < M.getWidth() + 2; i++) {
            cout << "#";
        }
        cout << endl << endl << "Health:" << P.getHealth() << endl;
    }
    catch (const exception& e) {
        cerr << "Exception in draw function: " << e.what() << endl;
    }
}

// Function to handle game logic
void logic(map& M, player& P, score& S, vector<enemy>& E, vector<bullet>& bullets) {
    try {
        // Player action
        P.act(M, bullets);

        // Move enemies down or moveout if they reach the bottom
        M.setDeleteEnemy(0);
        for (int i = 0; i < E.size(); i++) {
            if (E[i].getY() < M.getHeight() - 1) {
                E[i].setY(E[i].getY() + 1);
            }
            else {
                E[i].setY(-1);
                M.setDeleteEnemy(M.getDeleteEnemy() + 1);
            }
        }
        // Delete enemies that reached the bottom
        if (M.getDeleteEnemy() != 0) {
            for (int i = 0; i < M.getDeleteEnemy(); i++) {
                for (int j = 0; j < E.size(); j++) {
                    if (E[j].getY() == -1) {
                        E.erase(E.begin() + j);
                        break;
                    }
                }
            }
        }
        // Move bullets up or moveout if they reach the top
        M.setDeleteBullet(0);
        for (int i = 0; i < bullets.size(); i++) {
            if (bullets[i].getY() > 0) {
                bullets[i].setY(bullets[i].getY() - 1);
            }
            else {
                bullets[i].setY(-1);
                M.setDeleteBullet(M.getDeleteBullet() + 1);
            }
        }
        // Delete bullets that reached the top
        if (M.getDeleteBullet() != 0) {
            for (int i = 0; i < M.getDeleteBullet(); i++) {
                for (int j = 0; j < bullets.size(); j++) {
                    if (bullets[j].getY() == -1) {
                        bullets.erase(bullets.begin() + j);
                        break;
                    }
                }
            }
        }
        // Check for collisions between bullets and enemies
        M.setCollision(0);
        for (int i = 0; i < E.size(); i++) {
            for (int j = 0; j < bullets.size(); j++) {
                if (bullets[j].getX() == E[i].getX() && (bullets[j].getY() == E[i].getY() || bullets[j].getY() + 1 == E[i].getY())) {
                    // Update score, mark enemy, bullet for deletion, and increase collision count
                    S.setCurrentScore(S.getCurrentScore() + 10);
                    E[i].setX(-1);
                    E[i].setY(-1);
                    bullets[j].setY(-1);
                    M.setCollision(M.getCollision() + 1);
                }
            }
        }
        // Delete enemies and bullets involved in collisions
        if (M.getCollision() != 0) {
            for (int i = 0; i < M.getCollision(); i++) {
                for (int j = 0; j < E.size(); j++) {
                    if (E[j].getX() == -1 && E[j].getY() == -1) {
                        E.erase(E.begin() + j);
                        break;
                    }
                }
                for (int k = 0; k < bullets.size(); k++) {
                    if (bullets[k].getY() == -1) {
                        bullets.erase(bullets.begin() + k);
                        break;
                    }
                }
            }
        }
        // Check for collisions between player and enemies
        for (int i = 0; i < E.size(); i++) {
            if (P.getX() == E[i].getX() && (P.getY() == E[i].getY() || P.getDirection() == 'w' && P.getY() + 1 == E[i].getY())) {
                // Remove enemy, reduce player health, and end the game if player health is zero
                E.erase(E.begin() + i);
                P.setHealth(P.getHealth() - 1);
                if (P.getHealth() <= 0) {
                    M.setGameover(true);
                }
                break;
            }
        }
        // Increase score
        S.setCurrentScore(S.getCurrentScore() + 1);

        // Adjust sleep time and add new enemies periodically
        if (M.getFrame() % 50 == 0) {
            M.setSleepTime(max(50, 200 - (M.getFrame() / 50) * 50));
        }
        // Add new enemies based on sleep time and frame count
        if (M.getSleepTime() == 200 && (M.getFrame() % 20 == 0)) {
            E.push_back(enemy(M));
        }
        else if (M.getSleepTime() == 150 && (M.getFrame() % 15 == 0)) {
            E.push_back(enemy(M));
        }
        else if (M.getSleepTime() == 100 && (M.getFrame() % 10 == 0)) {
            E.push_back(enemy(M));
        }
        else if (M.getSleepTime() == 50 && (M.getFrame() % 5 == 0)) {
            E.push_back(enemy(M));
        }
        // Pause execution to control game speed
        Sleep(M.getSleepTime());
        M.setFrame(M.getFrame() + 1);
    }
    catch (const exception& e) {
        cerr << "Exception in logic function: " << e.what() << endl;
    }
}

// Function to handle game over screen
void gameOver(map& M, player& P, score& S, vector<enemy>& E, vector<bullet>& bullets) {
    try {
        draw(M, P, S, E, bullets);
        S.gameOver();
        cout << endl << "Game Over!" << endl;
        cout << endl << "Press 'm' to return to the menu.";
        while (true) {
            if (_getch() == 'm') {
                break;
            }
        }
    }
    catch (const exception& e) {
        cerr << "Exception in gameOver function: " << e.what() << endl;
    }
}

int main() {
    try {
        // Initialize game score
        score Score;
        // Main game loop
        while (true) {
            // Display main menu
            menu();
            // Get user input for menu selection
            char option = _getch();
            // Perform actions based on user selection
            if (option == '1') {
                // Initialize random seed and game entities
                srand((unsigned)time(NULL));
                map Map;
                player Player(Map);
                enemy Enemy(Map);
                vector<enemy> enemies;
                vector<bullet> bullets;
                // Game loop until game over
                while (!Map.getGameover()) {
                    // Draw game screen
                    draw(Map, Player, Score, enemies, bullets);
                    // Handle game logic
                    logic(Map, Player, Score, enemies, bullets);
                }
                // Display game over screen
                gameOver(Map, Player, Score, enemies, bullets);
            }
            else if (option == '2') {
                // Display help screen
                help();
            }
            else if (option == '0') {
                // Exit the game
                return 0;
            }
        }
    }
    catch (const exception& e) {
        cerr << "Exception in main function: " << e.what() << endl;
        return 1;  // Return non-zero to indicate an error
    }
}
