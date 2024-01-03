#include "ball.h"

//Initializes a Ball
Ball::Ball(int x, int y, int radius, Color color) : x(x), y(y), radius(radius), color(color), xSpeed(2), ySpeed(2) {}

//Draws a ball to the screen
void Ball::drawBall() const{
    DrawCircle(x, y, radius, color);
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
void Ball::checkCollision(const Paddle& paddle){
    //Create a Rectangle for the paddle
    Rectangle paddleRect = {static_cast<float>(paddle.getX()), static_cast<float>(paddle.getY()), static_cast<float>(paddle.getWidth()), static_cast<float>(paddle.getHeight())};

    //If collision occurs then ball is moved accordinly
    if (CheckCollisionCircleRec(Vector2{static_cast<float>(x), static_cast<float>(y)}, radius, paddleRect)) {
        xSpeed *= -1;
    }
}

//Resets the ball in the middle and moves randomly
void Ball::reset(){
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

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