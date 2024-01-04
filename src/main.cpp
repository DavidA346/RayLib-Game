#include "raylib.h"
#include "ball.h"
#include "goalie.h"

//Sets the state of the current game
enum GameState{
    MENU,
    IN_PROGRESS,
    WINNER
};

int main(){
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Soccer Pong");

    //Initializes both textures
    Texture2D backgroundTexture = LoadTexture("include/soccer_field.png");
    Texture2D mainMenuTexture = LoadTexture("include/main_menu.png");

    //Initializes the ball and goalies
    Ball* soccerBall = new Ball(screenWidth / 2, screenHeight / 2, 5, WHITE);
    Goalie* goalieLeft = new Goalie(40, screenHeight / 2 - 70 / 2, 45, 76, WHITE, true);
    Goalie* goalieRight = new Goalie(715, screenHeight / 2 - 70 / 2, 45, 76, WHITE, false);

    //Initialize the state to MENU
    GameState game= MENU;
    //Used for deciding winner
    bool isBlue = true;

    SetTargetFPS(120);               // Set our game to run at 120 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) {   // Detect window close button or ESC key
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            //Menu State
            if (game == MENU){
                //Loads Main Menu Texture
                ClearBackground(WHITE);
                DrawTexture(mainMenuTexture, 0, 0, WHITE);
                DrawText("Press Enter", screenWidth / 3 + 42, 350, 30, WHITE);

                //Switches state when Enter is pressed
                if (IsKeyPressed(KEY_ENTER)){
                    game = IN_PROGRESS;
                }
            }

            //IN_PROGRESS State
            if (game == IN_PROGRESS){
                //Loads Field Background
                ClearBackground(WHITE);
                DrawTexture(backgroundTexture, 0, 0, WHITE);

                //Right Goal
                DrawRectangle(0, 24, 30, 402, WHITE);
                    
                DrawText("G", 5, 160, 30, BLACK);
                DrawText("O", 5, 195, 30, BLACK);
                DrawText("A", 5, 230, 30, BLACK);
                DrawText("L", 5, 265, 30, BLACK);

                //Left Goal
                DrawRectangle(770, 24, 30, 402, WHITE);
                DrawText("G", 775, 160, 30, BLACK);
                DrawText("O", 775, 195, 30, BLACK);
                DrawText("A", 775, 230, 30, BLACK);
                DrawText("L", 775, 265, 30, BLACK);

                //Draws ball and goalies to screen
                soccerBall->drawBall();
                goalieRight->drawGoalie();
                goalieLeft->drawGoalie();

                //Draws scores to screen
                DrawText(TextFormat("%i", soccerBall->getScoreLeft()), (screenWidth / 4) - 20 / 2, 30, 80, WHITE);
                DrawText(TextFormat("%i", soccerBall->getScoreRight()), 3 * (screenWidth / 4) - 20, 30, 80, WHITE);

                //Allows for movement and collisions
                soccerBall->ballMovement();
                goalieRight->moveGoalie(KEY_UP, KEY_DOWN);
                goalieLeft->moveGoalie(KEY_W, KEY_S);
                soccerBall->checkCollision(*goalieLeft);
                soccerBall->checkCollision(*goalieRight);

                //Checks if player has one and changes to WINNER state
                if (soccerBall->getScoreLeft() == 5) {
                    isBlue = true;
                    game = WINNER;
                }

                else if (soccerBall->getScoreRight() == 5){
                    isBlue = false;
                    game = WINNER;
                }
            }

            //WINNER state
            else if (game == WINNER){
                ClearBackground(BLACK);

                //A winner screen is shown to the user depending on which color won and is asked to play again or quit
                if (isBlue){
                    DrawText("BLUE IS THE WINNER", screenWidth / 6, screenHeight / 2 - 100, 50, BLUE);
                    DrawText("Press 'Enter' to Play Again", screenWidth / 3, screenHeight / 2, 20, WHITE);
                    DrawText("Press 'Q' to Quit", screenWidth / 3 + 48, screenHeight / 2 + 100, 20, WHITE);
                    if (IsKeyDown(KEY_ENTER)){
                        soccerBall->resetScore();
                        game = MENU;
                    }
                    else if (IsKeyDown(KEY_Q)){
                        break;
                    }
                }

                else{
                    DrawText("RED IS THE WINNER", screenWidth / 6, screenHeight / 2 - 100, 50, RED);
                    DrawText("Press 'Enter' to Play Again", screenWidth / 3, screenHeight / 2, 20, WHITE);
                    DrawText("Press 'Q' to Quit", screenWidth / 3 + 48, screenHeight / 2 + 100, 20, WHITE);
                    if (IsKeyDown(KEY_ENTER)){
                        soccerBall->resetScore();
                        game = MENU;
                    }
                    else if (IsKeyDown(KEY_Q)){
                        break;
                    }
                }
            }
      
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(backgroundTexture);
    UnloadTexture(mainMenuTexture);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    //Frees objects created
    delete soccerBall;
    delete goalieLeft;
    delete goalieRight;
    
    return 0;
}