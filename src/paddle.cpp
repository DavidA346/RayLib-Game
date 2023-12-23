#include "paddle.h"

//Initializes a paddle
Paddle::Paddle(int x, int y, int width, int height, Color color) : x(x), y(y), width(width), height(height), color(color), speed(3) {}

//Draws a paddle to the screen
void Paddle::drawPaddle() const{
    DrawRectangle(x, y, width, height, WHITE);
}

//Sets the speed of the paddle
void Paddle::setSpeed(int speed){
    this->speed = speed;
}

//Allows for paddle to move
void Paddle::movePaddle(int keyUp, int keyDown){
    if (IsKeyDown(keyUp)){
        y -= speed;
    }

    if (IsKeyDown(keyDown)){
        y += speed;
    }

    //Contains paddle inside of the screen
    if (y + height >= GetScreenHeight()){
        y = GetScreenHeight() - height;
    }

    if (y <= 0){
        y = 0;
    }
}

int Paddle::getX() const{
    return x;
}

int Paddle::getY() const{
    return y;
}

int Paddle::getWidth() const{
    return width;
}

int Paddle::getHeight() const{
    return height;
}