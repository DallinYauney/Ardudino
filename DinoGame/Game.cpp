#include "Game.h" 
 
Game::Game()
   : prevTimestamp(0), 
   prevDeltaTime(100), 
   gameSpeed(500), 
   dinoPos(0), 
   cactusPos(17), 
   score(0),
   obstacleActive(false) { 
} 
 
void Game::begin() { 
   display.begin(); 
   prevTimestamp = millis(); 
   randomSeed(analogRead(A0)); 
 
   display.writeCharAt(1, dinoPos, dinoChar); 
   drawScore(); 
} 
 
void Game::update() { 
   unsigned long currentTimestamp = millis(); 
   unsigned long elapsed = currentTimestamp - prevTimestamp; 
 
   if (elapsed < (unsigned long)gameSpeed) { 
      return; 
   } 
 
   prevDeltaTime = (int)elapsed; 
   prevTimestamp = currentTimestamp; 
   
   character.update(prevDeltaTime);
   
   display.scrollLeft();
   
   doDino();
   doCactus();
   drawScore(); 
} 
 
void Game::doDino() { 
   display.writeCharAt(1, dinoPos, ' '); 
 
   dinoPos = (dinoPos + 1) % 40; 
 
   display.writeCharAt(1, dinoPos, dinoChar); 
} 
 
void Game::doCactus() { 
   if (!obstacleActive && random(3) == 0) { 
      obstacleActive = true; 
      cactusPos = 17; 
   } 
 
   if (!obstacleActive) { 
      return; 
   } 
 
   display.writeCharAt(1, cactusPos, ' '); 
 
   cactusPos = (cactusPos + 1) % 40; 
 
   if (cactusPos == dinoPos) { 
      score++; 
      obstacleActive = false;
      cactusPos = 17;
      
      if (gameSpeed > 100) {
         gameSpeed -= 25;
      }
      
      return; 
   }
   
   display.writeCharAt(1, cactusPos, cactusChar); 
} 
 
void Game::drawScore() { 
   display.writeTextAt(0, 0, "                "); 
   display.writeTextAt(0, 0, "Score: "); 
   display.display.setCursor(7, 0); 
   display.display.print(score); 
} 
