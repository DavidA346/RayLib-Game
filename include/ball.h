#ifndef _BALL_H_
#define _BALL_H_

#include "raylib.h"
#include "goalie.h"

class Ball{
 private:
   int x;
   int y;
   float radius;
   Color color;
   int xSpeed;
   int ySpeed;
   int scoreLeft = 0;
   int scoreRight = 0;
   Texture2D soccerBallTexture;

 public:
   Ball(int x, int y, int radius, Color color);

   void drawBall() const;

   void ballMovement();

   void checkCollision(const Goalie& goalie);

   void reset();

   int getScoreLeft() const;

   int getScoreRight() const;

   void resetScore();
   
};

#endif