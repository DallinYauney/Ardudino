#ifndef DISPLAY_H 
#define DISPLAY_H 
 
#include <Arduino.h> 
#include <LiquidCrystal.h> 
#include "Utils.h" 
 
class Display { 
private: 
   Position cursor; 
 
public: 
   LiquidCrystal display; 
 
   Display(); 
 
   void begin(); 
   void writeCharAt(int row, int col, char character); 
   void writeTextAt(int row, int col, const char* text); 
   void scrollLeft(); 
}; 
 
#endif