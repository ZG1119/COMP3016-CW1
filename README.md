# Aircraft Battle Game Prototype

## Game Development Environment

The code was designed to be compatible with Visual Studio, a common integrated development environment for C++ on Windows. The provided functions like `_kbhit()` and `_getch()` indicate its Windows-specific nature.

## Gameplay Overview

The game is a console-based aircraft battle game. The player controls an aircraft ('P') and can move it horizontally and vertically using 'a', 'd', 'w', and 's' keys. Bullets can be shot using the spacebar. The objective is to evade enemies ('E') and shoot them down for points. The game ends if the player's health reaches zero.

## UML Design Diagram

### Classes

1. **map**
   - Properties: width, height, sleepTime, frame, gameover, printBullet, printEnemy, printPlayer, collision, deleteEnemy, deleteBullet
   - Methods: getWidth(), setWidth(), getHeight(), setHeight(), getSleepTime(), setSleepTime(), getFrame(), setFrame(), getGameover(), setGameover(), getPrintBullet(), setPrintBullet(), getPrintEnemy(), setPrintEnemy(), getPringPlayer(), setPrintPlayer(), getCollision(), setCollision(), getDeleteEnemy(), setDeleteEnemy(), getDeleteBullet(), setDeleteBullet()

2. **bullet**
   - Properties: x, y
   - Methods: getX(), getY(), setY()

3. **player**
   - Properties: x, y, health, direction
   - Methods: getHealth(), setHealth(), getX(), setX(), getY(), setY(), getDirection(), setDirection(), act()

4. **enemy**
   - Properties: x, y
   - Methods: getX(), setX(), getY(), setY()

5. **score**
   - Properties: currentScore, maxScore
   - Methods: getCurrentScore(), setCurrentScore(), getMaxScore(), gameOver()

### Functions

1. **menu()**: Display the main menu.
2. **help()**: Display game instructions.
3. **draw(map&, player&, score&, vector<enemy>&, vector<bullet>&)**: Draw the game screen.
4. **logic(map&, player&, score&, vector<enemy>&, vector<bullet>&)**: Handle game logic.
5. **gameOver(map&, player&, score&, vector<enemy>&, vector<bullet>&)**: Handle the game over screen.
6. **main()**: Main function containing the game loop and user interaction.

## Exception Handling and Test Cases

The code includes basic exception handling using try-catch blocks. However, the specific exceptions that can be thrown are not explicitly mentioned. Potential exceptions include array out of bounds errors, vector index errors, and issues related to dynamic memory management.

## Further Details

The game is a prototype with room for improvement. Additional testing and features would enhance its robustness and playability.

## Video Link
Unfortunately, as a text-based AI, I cannot view or link to external content.

## Game Git Repository

