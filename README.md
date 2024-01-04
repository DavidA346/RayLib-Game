Soccer Pong Game using raylib
Welcome to Soccer Pong, an exciting blend of classic Pong gameplay with a soccer twist. This game, developed using the raylib library, promises an engaging and competitive experience. Soccer Pong features two goalies, a soccer ball, and a vibrant soccer field background. I created this game as a way to stregnthen my C++ skills as well create a fun new project using raylib. I love soccer and have played it ever since a child, so I decided to add it to my game. This was a lot of fun to and has taught me a lot about coding. Some future additions I would like to make are things such: addind music, creating clickable buttons, and different options for choosing a custom player.

Game Overview
Soccer Pong introduces dynamic gameplay where two players control goalies to defend their goals and score points by launching the ball into their opponent's goal. The first player to reach a score of 5 emerges victorious. The game combines fast-paced action with strategic goalie movements, creating an immersive and enjoyable gaming experience.

How to Play

Menu State:

Upon launching the game, you'll be greeted with the main menu.
Press "Enter" to transition to the In-Progress state.

In-Progress State:

Use the arrow keys (Up and Down) to control the right goalie.
Utilize the keys 'W' and 'S' to control the left goalie.
Score goals against your opponent while defending your own goal.
Keep an eye on the score displayed at the top of the screen.

Winner State:

The game ends when one player reaches a score of 5.
A winner screen displays the winning color (Blue or Red).
Press 'Enter' to initiate a rematch or 'Q' to quit the game.

Code Structure
The codebase is organized into three main components:

ball.h
Defines the Ball class, responsible for managing the soccer ball's behavior.
Handles movement, collisions, and scoring.

goalie.h
Defines the Goalie class, managing the goalies' behavior and movements.
Handles drawing on the screen.

Main Game File (main.cpp)
Initializes the game, sets up the window, and loads necessary textures.
Manages the game loop, including the menu, in-progress state, and winner state.
Player input controls goalie movements, and collisions with the ball are detected.
The winner is determined based on the score, offering players the choice to play again or quit.

Dependencies
This game relies on the raylib library. Ensure that raylib is installed or included in your project.

How to Build and Run
Ensure that raylib is installed or properly included in your project.
Compile the code using your preferred compiler, ensuring proper library linkage.
Run the compiled executable.
Enjoy the fast-paced and thrilling experience of Soccer Pong! Feel free to contribute, report issues, or suggest improvements. Happy gaming!
