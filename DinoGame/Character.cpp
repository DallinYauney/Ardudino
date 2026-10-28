#include "Character.h" 
 
Character::Character() 
   : position{1, 0}, velocity(0), height(0) { 
} 
 
void Character::update(int deltaTime) { 
   velocity -= 0.01f * deltaTime; 
   height -= velocity * deltaTime; 
 
   if (height <= 0) { 
      height = 0; 
      velocity = 0; 
   } 
   // TODO: Select the display row based on height. 
} 
 
void Character::begin_jump() { 
   velocity = 30; 
} 
 