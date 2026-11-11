#include "Display.h"
#include <string>

// Implement methods for the DisplayCursor positioner class
// double colon "::" is the scope resolution operator.
// belongs to "def __init__(self):" context, telling C++ which class these functions belong to.
DisplayCursor::DisplayCursor() : row(0), col(0) {}

void DisplayCursor::set(int newRow, int newCol) {
   row = newRow;
   col = newCol;
}

void DisplayCursor::next() {
   col = (col + 1) % 16; // Matrix dimensions
}

int DisplayCursor::getRow() const { return row; }
int DisplayCursor::getCol() const { return col; }


// Implement Display logic methods
Display::Display()
   : cursor(),
     lcd(12, 11, 5, 4, 3, 2) {  // Pin mappings
}

void Display::begin() {
   lcd.begin(16, 2);
}

void Display::writeCharAt(int row, int col, char character) {
   lcd.setCursor(col % 16, row);
   lcd.write(character);
   cursor.set(row, col);
}

void Display::writeTextAt(int row, int col, const std::string text) {
   lcd.setCursor(col % 16, row);
   for(char letter : text) {
      lcd.print(letter);
   }
   // lcd.print(text);
}

void Display::writeIntAt(int row, int col, int value) {
   lcd.setCursor(col % 16, row);
   lcd.print(value);
}

void Display::clearRow(int row) {
   lcd.setCursor(0, row);
   for (int i = 0; i < 16; i++) {
      clearCharAt(row, i); //
   }
}

void Display::clearCharAt(int row, int col) {
   lcd.setCursor(col % 16, row);
   // F() macro: stores constant string literals directly in flash memory
   lcd.write(' ');  // Saves SRAM (dynamic memory), overwrite exactly 1 character
}
