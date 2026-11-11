#include "Game.h"

Game::Game()
   : prevTimestamp(0),
     gameSpeed(500) // starting update speeed 
   {
   display = Display();
   character = Character();
   score = Score();
}

void Game::begin() {
   display.begin();
   prevTimestamp = millis();
   randomSeed(analogRead(A0)); // Seed randomizer using background static voltage noise (random.seed())
}

void Game::update() {
   unsigned long currentTimestamp = millis();

   if (currentTimestamp - prevTimestamp < (unsigned long)gameSpeed) {
      return;
   }

   int deltaTime = currentTimestamp - prevTimestamp;
   prevTimestamp = currentTimestamp;

   // Handle physics frame updates
   character.update(deltaTime);
   // osbtacle.update(deltaTime);
   score.update(deltaTime);
   
   // Have each component render their contents to the display
   character.display(display);
   // obstacle.display(display);
   score.display(display); // Display renders on top of obstacles, so it gets called last
}