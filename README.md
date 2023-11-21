# COMP3016-CW1
Development Environment
The code is written in C++ and appears to be designed to run on a console-based environment. The code uses features like keyboard input, screen clearing, and basic console output. The code seems compatible with Visual Studio, given the use of _getch() and system("cls"). The operating system version is not explicitly mentioned, but it should be compatible with Windows due to the use of windows.h and conio.h headers.

Gameplay
The game seems to be a simple aircraft battle game where the player controls an aircraft ('P') to evade enemies ('E') and shoot bullets ('*') to destroy them. The player's health decreases if the aircraft is hit by an enemy, and the game ends when health reaches zero. The player earns points by destroying enemies.

UML Design Diagram
Unfortunately, I cannot draw diagrams directly in this text-based environment. However, I can describe the structure based on the provided code.

Classes:

map: Represents the game map and its properties.
bullet: Represents bullets with coordinates.
player: Represents the player with health, coordinates, and direction.
enemy: Represents enemies with random initial coordinates.
score: Represents the player's score.
Relationships:

map contains properties like width, height, sleepTime, frame, and flags for printing entities.
player uses the map to initialize the player's position and direction.
enemy uses the map to generate random initial coordinates.
score keeps track of current and maximum scores.
Exception Handling and Test Cases
The code appears to lack extensive exception handling. It assumes correct user inputs and does not handle unexpected errors robustly. It would be beneficial to implement error checking for user inputs and handle potential exceptions in file operations or memory management.

As for test cases, it would be helpful to perform unit testing for individual functions, ensuring they behave as expected in various scenarios, such as boundary cases and invalid inputs.

Further Details
The code uses a simple console-based graphics approach to represent the game state. It relies on the console window for display and keyboard input for player interaction. The game loop includes logic for player movement, shooting, enemy movement, collision detection, and score tracking.

Video and Git Repository
Unfortunately, as a text-based AI developed by OpenAI, I don't have the capability to generate videos, and I cannot browse external links or repositories. You would need to create a video and share the repository link separately.

If you have any specific questions or need further assistance, feel free to ask!
