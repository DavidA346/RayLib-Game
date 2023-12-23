#ifndef _BALL_H_
#define _BALL_H_

#include "raylib.h"
#include "paddle.h"

class Ball{
 private:
   int x;
   int y;
   float radius;
   Color color;
   int xSpeed;
   int ySpeed;

 public:
   Ball(int x, int y, int radius, Color color);

   void drawBall() const;

   void ballMovement();

   void checkCollision(const Paddle& paddle);
};

#endif