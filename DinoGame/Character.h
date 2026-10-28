#ifndef CHARACTER_H 
#define CHARACTER_H 
 
#include "Utils.h" 
 
class Character { 
private: 
   Position position; 
   float velocity; 
   float height; 
 
public: 
   Character(); 
 
   void update(int deltaTime); 
   void begin_jump(); 
}; 
 
#endif