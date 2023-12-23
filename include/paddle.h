#ifndef _PADDLE_H_
#define _PADDLE_H_

#include "raylib.h"

class Paddle{
 private:
   int x;
   int y;
   int width;
   int height;
   Color color;
   int speed;

 public:
   Paddle(int x, int y, int width, int height, Color color);

   void drawPaddle() const;

   void movePaddle(int keyUp, int keyDown);

   void setSpeed(int speed);

   int getX() const;

   int getY() const;

   int getWidth() const;

   int getHeight() const;
};

#endif