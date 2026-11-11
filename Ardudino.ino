#include "Game.h"

int dinoPos = 0;
int cactusPos = 17;
const int dinoChar = 0b10111100;
const int cactusChar = 0b11000001;
const int screenWidth = 40;

//track score, increase speed vars
int score = 0;
int gameSpeed = 500; // Started slower than original 350ms
bool obstacleActive = false;

Game game;

void setup(){
  delay(50);
  game.begin();
}

void loop(){
  game.update();

  delay(gameSpeed); // Uses dynamic speed variable
}
