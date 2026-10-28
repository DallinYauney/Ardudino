#include "Display.h" 
 
Display::Display() 
   : cursor{0, 0}, 
   display(12, 11, 5, 4, 3, 2) { 
} 
 
void Display::begin() { 
   display.begin(16, 2); 
   display.clear(); 
} 
 
void Display::writeCharAt(int row, int col, char character) { 
   display.setCursor(col % 16, row); 
   display.write(character); 
   cursor.setAfter(row, col); 
} 
 
void Display::writeTextAt(int row, int col, const char* text) { 
   display.setCursor(col % 16, row); 
   display.print(text); 
} 
 
void Display::scrollLeft() { 
   display.scrollDisplayLeft(); 
} 
 