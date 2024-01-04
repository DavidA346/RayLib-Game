#include "raylib.h"
#include "ball.h"
#include "goalie.h"

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
    Texture2D backgroundTexture = LoadTexture("include/soccer_field.png");
    //Texture2D mainMenuTexture = LoadTexture("include/main_menu.png");

    Ball* pongBall = new Ball(screenWidth / 2, screenHeight / 2, 5, WHITE);
    Goalie* goalieLeft = new Goalie(40, screenHeight / 2 - 70 / 2, 45, 76, WHITE, true);
    Goalie* goalieRight = new Goalie(715, screenHeight / 2 - 70 / 2, 45, 76, WHITE, false);

    GameState game= IN_PROGRESS;
    bool isBlue = true;

    SetTargetFPS(120);               // Set our game to run at 120 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) {   // Detect window close button or ESC key
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            // if (game == MENU){
            //     ClearBackground(WHITE);
            //     DrawText("SOCCER PONG", screenWidth / 4, 50, 50, BLACK);
            //     DrawTexture(mainMenuTexture, screenWidth / 3 + 20, 100, WHITE);
            //     DrawRectangle(screenWidth / 3, 250, 250, 50, BLACK);
            //     DrawText("Press Enter", screenWidth / 3 + 26, 250, 30, WHITE);

            //     if (IsKeyPressed(KEY_ENTER)){
            //         game = IN_PROGRESS;
            //     }
            // }

            if (game == IN_PROGRESS){
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

                pongBall->drawBall();
                goalieRight->drawGoalie();
                goalieLeft->drawGoalie();

                DrawText(TextFormat("%i", pongBall->getScoreLeft()), (screenWidth / 4) - 20 / 2, 30, 80, WHITE);
                DrawText(TextFormat("%i", pongBall->getScoreRight()), 3 * (screenWidth / 4) - 20, 30, 80, WHITE);
                    pongBall->ballMovement();
                    goalieRight->moveGoalie(KEY_UP, KEY_DOWN);
                    goalieLeft->moveGoalie(KEY_W, KEY_S);
                    pongBall->checkCollision(*goalieLeft);
                    pongBall->checkCollision(*goalieRight);


                    if (pongBall->getScoreLeft() == 1) {
                        isBlue = true;
                        game = WINNER;
                    }
                    else if (pongBall->getScoreRight() == 1){
                        isBlue = false;
                        game = WINNER;
                    }
                }

            else if (game == WINNER){
                ClearBackground(WHITE);
                if (isBlue){
                    DrawText("BLUE IS THE WINNER", screenWidth / 6, screenHeight / 2 - 100, 50, BLUE);
                }

                else{
                    DrawText("RED IS THE WINNER", screenWidth / 6, screenHeight / 2 - 100, 50, RED);
                }
            }
      
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(backgroundTexture);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    delete pongBall;
    delete goalieLeft;
    delete goalieRight;
    
    return 0;
}