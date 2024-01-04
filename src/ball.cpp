#include "ball.h"

//Initializes a Ball
Ball::Ball(int x, int y, int radius, Color color) : x(x), y(y), radius(radius), color(color), xSpeed(3), ySpeed(3) {
    soccerBallTexture = LoadTexture("include/soccer_ball.png");
}

//Draws a ball to the screen
void Ball::drawBall() const{
    DrawTexture(soccerBallTexture, x - radius, y - radius, WHITE);
}

//Allows the ball to move
void Ball::ballMovement(){
    //Makes ball move
    x += xSpeed;
    y += ySpeed;

    //Contains the ball inside the screen
    if (y + radius >= GetScreenHeight() || y - radius <= 0){
        ySpeed *= -1;
    }

    //Resets the ball and increases the score
    if (x + radius >= 770){
        ++scoreLeft;
        reset();
    }

    if (x - radius <= 30){
        ++scoreRight;
        reset();
    }
}

//Checks for collion with paddles
void Ball::checkCollision(const Goalie& goalie){
    //Create a Rectangle for the paddle
    Rectangle goalieRect = {static_cast<float>(goalie.getX()), static_cast<float>(goalie.getY()), static_cast<float>(goalie.getWidth()), static_cast<float>(goalie.getHeight())};

    //If collision occurs then ball is moved accordinly
    if (CheckCollisionCircleRec(Vector2{static_cast<float>(x), static_cast<float>(y)}, radius, goalieRect)) {
        xSpeed *= -1;
    }
}

//Resets the ball in the middle and moves randomly
void Ball::reset(){
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    WaitTime(0.3);
    int resetSpeed[2] = {-1, 1};
    xSpeed *= resetSpeed[GetRandomValue(0, 1)];
    ySpeed *= resetSpeed[GetRandomValue(0, 1)];
}

int Ball::getScoreLeft() const{
    return scoreLeft;
}

int Ball::getScoreRight() const{
    return scoreRight;
}