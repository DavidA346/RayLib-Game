#include "raylib.h"
#include "ball.h"
#include "paddle.h"

int main(){
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Soccer Pong");

    Image backgroundImage = LoadImage("include/soccer_field.png");
    Texture2D backgroundTexture = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage);

    Ball* pongBall = new Ball(screenWidth / 2, screenHeight / 2, 5, WHITE);
    Paddle* paddleLeft = new Paddle(40, screenHeight / 2 - 70 / 2, 8, 70, WHITE);
    Paddle* paddleRight = new Paddle(750, screenHeight / 2 - 70 / 2, 8, 70, WHITE);

    SetTargetFPS(120);               // Set our game to run at 120 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) {   // Detect window close button or ESC key
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(WHITE);
            DrawTexture(backgroundTexture, 0, 0, WHITE);
            
            pongBall->ballMovement();
            paddleRight->movePaddle(KEY_UP, KEY_DOWN);
            paddleLeft->movePaddle(KEY_W, KEY_S);
            pongBall->checkCollision(*paddleLeft);
            pongBall->checkCollision(*paddleRight);

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
            paddleRight->drawPaddle();
            paddleLeft->drawPaddle();
            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(backgroundTexture);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    delete pongBall;
    delete paddleLeft;
    delete paddleRight;
    
    return 0;
}