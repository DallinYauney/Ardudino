#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
#include "Character.h"
#include "Display.h"
#include "Obstacles/Obstacles.cpp"
#include "Score.cpp"

class Game {
private:
   Display display;
   Character character;
   // Obstacle obstacles;
   Score score;

   unsigned long prevTimestamp;
   int gameSpeed;

   // int cactusCol;
   // int score;
   // bool obstacleActive;

   // change binary literals
   // const char dinoChar = (char)0b10111100;
   // const char cactusChar = (char)0b11000001;

public:
   Game();

   void begin();
   void update();
};

#endif
