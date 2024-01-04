#ifndef _GOALIE_H_
#define _GOALIE_H_

#include "raylib.h"

class Goalie{
 private:
   int x;
   int y;
   int width;
   int height;
   Color color;
   int speed;
   Texture2D leftGoalieTexture;
   Texture2D rightGoalieTexture;
   bool isLeft;


 public:
   Goalie(int x, int y, int width, int height, Color color, bool isLeft);

   void drawGoalie() const;

   void moveGoalie(int keyUp, int keyDown);

   void setSpeed(int speed);

   int getX() const;

   int getY() const;

   int getWidth() const;

   int getHeight() const;
};

#endif