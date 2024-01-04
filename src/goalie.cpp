#include "goalie.h"

//Initializes a paddle
Goalie::Goalie(int x, int y, int width, int height, Color color, bool isLeft) : x(x), y(y), width(width), height(height), color(color), speed(3), isLeft(isLeft) {
    //Initializes both textures
    if (isLeft){
        leftGoalieTexture = LoadTexture("include/blue_goalie.png");
    }
    else{
        rightGoalieTexture = LoadTexture("include/red_goalie.png");
    }
}

//Draws both goalies to the screen
void Goalie::drawGoalie() const{
    DrawTexture(leftGoalieTexture, x, y, WHITE);
    DrawTexture(rightGoalieTexture, x, y, WHITE);
}

//Sets the speed of the goalies
void Goalie::setSpeed(int speed){
    this->speed = speed;
}

//Allows for goalies to move
void Goalie::moveGoalie(int keyUp, int keyDown){
    if (IsKeyDown(keyUp)){
        y -= speed;
    }

    if (IsKeyDown(keyDown)){
        y += speed;
    }

    //Contains goalie inside of the screen
    if (y + height >= GetScreenHeight()){
        y = GetScreenHeight() - height;
    }

    if (y <= 0){
        y = 0;
    }
}

int Goalie::getX() const{
    return x;
}

int Goalie::getY() const{
    return y;
}

int Goalie::getWidth() const{
    return width;
}

int Goalie::getHeight() const{
    return height;
}