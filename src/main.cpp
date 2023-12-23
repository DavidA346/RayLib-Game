#include "raylib.h"
#include "ball.h"
#include "paddle.h"

int main(){
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    Ball* pongBall = new Ball(screenWidth / 2, screenHeight / 2, 5, WHITE);
    Paddle* paddleLeft = new Paddle(5, screenHeight / 2 - 70 / 2, 8, 70, WHITE);
    Paddle* paddleRight = new Paddle(screenWidth - 13, screenHeight / 2 - 70 / 2, 8, 70, WHITE);

    InitWindow(screenWidth, screenHeight, "Pong");

    SetTargetFPS(120);               // Set our game to run at 120 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) {   // Detect window close button or ESC key
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
            
            pongBall->ballMovement();
            paddleRight->movePaddle(KEY_UP, KEY_DOWN);
            paddleLeft->movePaddle(KEY_W, KEY_S);
            pongBall->checkCollision(*paddleLeft);
            pongBall->checkCollision(*paddleRight);

            DrawLine(screenWidth / 2, 0 , screenWidth / 2, screenHeight, WHITE);
            pongBall->drawBall();
            paddleRight->drawPaddle();
            paddleLeft->drawPaddle();
            DrawText(TextFormat("%i", pongBall->getScoreLeft()), (screenWidth / 4) - 20 / 2, 20, 80, WHITE);
            DrawText(TextFormat("%i", pongBall->getScoreRight()), 3 * (screenWidth / 4) - 20, 20, 80, WHITE);
            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    delete pongBall;
    delete paddleLeft;
    delete paddleRight;
    
    return 0;
}