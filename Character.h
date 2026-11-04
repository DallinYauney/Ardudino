#ifndef CHARACTER_H  
#define CHARACTER_H  

#include "Utils.h"  

// Concrete implementation of IPositionable for character coordinates
class CharacterPosition : public IPositionable {
private:
   int row;
   int col;

public:
   CharacterPosition();
   void set(int newRow, int newCol) override;  
   void next() override;  
   int getRow() const override;
   int getCol() const override;
};

class Character {  
private:  
   CharacterPosition position;  
   int jumpTimer; //integer tracker

public:  
   Character();  
  
   void update();  
   int getCol();
   int getRow();
   void jump();
};  

#endif 
