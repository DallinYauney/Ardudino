#include "Character.h"
#include "Display.h"

// TODO: make different sprites for jump stuff
const char charCode = 0b10111100;

// Implement methods for the CharacterPosition class
CharacterPosition::CharacterPosition() : row(1), col(2) {}

void CharacterPosition::set(int newRow, int newCol) {
   row = newRow;
   col = newCol;
}

/**
 * The character doesn't move forward so don't call this. It's just
 * here because the interface requires it.
 */
void CharacterPosition::next() {
   col = (col + 1) % 16;
}

int CharacterPosition::getRow() const { return row; }
int CharacterPosition::getCol() const { return col; }


// Implement Character logic methods
Character::Character()
   : position(), jumpTimer(0) {
}

/**
 * Takes the button state and calculates whether a jump should be started.
 * We don't have button functionality yet so this is just a placeholder.
 */
void Character::handleJump() {
   return;
}

/**
 * Updates the position of the character on the display.
 * TODO: Set custom sprites for intermediate heights.
 */
void Character::updatePosition() {
   if(height < 100) {
      position.set( position.getRow(), 1);
   } else {
      position.set( position.getRow(), 0);
   }
}

void Character::update(int deltaTime) {
   /// VELOCITY
   handleJump();
   velocity -= 0.6 * deltaTime; // apply gravity

   // prevent speed accumulating on the ground
   if(height <= 0)
      velocity = 0;

   // TODO: do cool velocity things like having the gravity be less when button is pushed and what not.

   /// HEIGHT
   height += velocity; // apply velocity

   // prevent character from falling through the ground
   if(height <= 0)
      height = 0;
   
   updatePosition();
}

void Character::display(Display display) {
   display.writeCharAt(
      position.getRow(),
      position.getCol(),
      charCode
   );
}

int Character::getCol() { return position.getCol(); }
int Character::getRow() { return position.getRow(); }