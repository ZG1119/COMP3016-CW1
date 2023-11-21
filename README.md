# Aircraft Battle Game Prototype

## Game Development Environment

- **Visual Studio Version:** [17.7.4]
- **Operating System:** [Windows 11 Home Chinese Version]

## Gameplay Overview

The game is a console-based aircraft battle game. The player controls an aircraft ('P') and can move it horizontally and vertically using 'a', 'd', 'w', and 's' keys. Bullets can be shot using the spacebar. The objective is to evade enemies ('E') and shoot them down for points. When the player is hit by enemies ('E'), the health will be reduced. The game ends if the player's health reaches zero.

## UML Design Diagram

### Class Diagram
https://github.com/ZG1119/COMP3016-CW1/blob/main/ClassDiagram.png

### Use Case Diagram
https://github.com/ZG1119/COMP3016-CW1/blob/main/UseCaseDiagram.png

### Flow Chart
https://github.com/ZG1119/COMP3016-CW1/blob/main/FlowChart.png

## Exception Handling and Test Cases

### Exception Handling

This C++ code contains basic exception handling using "try", "catch", and "cerr". Exception handling is used to catch and handle potential runtime errors that may occur during program execution.

### Test Cases

- 1.**Movement Test: √**<br>
  Input: Press 'a', 'd', 'w', 's' keys to move the player in different directions.<br>
  Expected Outcome: The player should move left, right, up, and down respectively. The player does not move beyond the game boundaries.<br>

- 2.**Shooting Test: √**<br>
  Input: Press the space key to shoot bullets.<br>
  Expected Outcome: Bullets should be added to the game, and their position should be updated in subsequent frames. When the bullet hits the enemy, the enemy is eliminated, and the bullet disappears. When the bullet hits the map boundary, the bullet disappears.<br>

- 3.**Collision Test: √**<br>
  Input: Make the player collide with the enemy.<br>
  Expected Outcome: The player's health should decrease, and the game should end if the player's health reaches zero.<br>

- 4.**Enemy Generation Test: √**<br>
  Input: Play the game for some time.<br>
  Expected Outcome: New enemies should appear on the screen periodically. The game speed should increase over time.<br>

## Further Details

The game is a prototype with room for improvement. Additional testing and features would enhance its robustness and playability.

## Video Link
Unfortunately, as a text-based AI, I cannot view or link to external content.

## Game Git Repository

