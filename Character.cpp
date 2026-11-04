#include "Character.h"  

// Implement methods for the CharacterPosition class
CharacterPosition::CharacterPosition() : row(1), col(2) {}

void CharacterPosition::set(int newRow, int newCol) {
   row = newRow;
   col = newCol;
}

void CharacterPosition::next() {
   col = (col + 1) % 16;
}

int CharacterPosition::getRow() const { return row; }
int CharacterPosition::getCol() const { return col; }


// Implement Character logic methods
Character::Character()  
   : position(), jumpTimer(0) {  
}  

void Character::update() {  
   if (jumpTimer > 0) {  
      jumpTimer--;  
      if (jumpTimer == 0) {
         position.set(1, 2); // Return down to row 1 
      }
   }  
}  

int Character::getCol() { return position.getCol(); }
int Character::getRow() { return position.getRow(); }

void Character::jump() {  
   if (position.getRow() == 1) { // catch infinite double-jumping
      position.set(0, 2); // Jump up to row 0
      jumpTimer = 3; // stay in midair for 3 loops        
   }
} 
