#include "Game.h"  

Game::Game() 
   : prevTimestamp(0),  
     gameSpeed(500), // starting update speeed  
     cactusCol(15),  
     score(0), 
     obstacleActive(false) {  
}  

void Game::begin() {  
   display.begin();  
   prevTimestamp = millis();  
   randomSeed(analogRead(A0)); // Seed randomizer using background static voltage noise (random.seed())  
   drawScore();  
}  

void Game::update() {  
   unsigned long currentTimestamp = millis();  
  
   if (currentTimestamp - prevTimestamp < (unsigned long)gameSpeed) {  
      return;  
   }  
  
   prevTimestamp = currentTimestamp;  
    
   // Handle physics frame updates
   character.update(); 
   doCactus(); 
   doDino(); 
   drawScore();  
}  

void Game::doDino() {  
   // Clean previous frames around dino path
   display.writeCharAt(0, character.getCol(), ' ');  
   display.writeCharAt(1, character.getCol(), ' ');  
  
   // Draw character at updated row layout
   display.writeCharAt(character.getRow(), character.getCol(), dinoChar);  
}  

void Game::doCactus() {  
   if (!obstacleActive && random(3) == 0) {  
      obstacleActive = true;  
      cactusCol = 15;  
   }  
  
   if (!obstacleActive) {  
      return;  
   }  
  
   // Clear old cactus frame
   display.writeCharAt(1, cactusCol, ' ');  
  
   cactusCol--;  // Move obstacle one space to the left
  
   // Out of bounds check
   if (cactusCol < 0) {
      obstacleActive = false;
      score++;
      if (gameSpeed > 150) gameSpeed -= 25; // Accelerate game speed slightly 
      return;
   }

   // Collision check against Dino
   if (cactusCol == character.getCol() && character.getRow() == 1) {  
      display.clearRow(0);
      display.clearRow(1);
      display.writeTextAt(0, 3, "GAME OVER");  
      display.writeTextAt(1, 3, "Score: ");
      display.writeIntAt(1, 10, score);
      while(true); // Halt execution
   } 
    
   display.writeCharAt(1, cactusCol, cactusChar);  
}  

void Game::drawScore() {  
   // Keep score fixed on the right half of the top row
   display.writeTextAt(0, 9, "Sc:");  
   display.writeIntAt(0, 12, score);  
} 
