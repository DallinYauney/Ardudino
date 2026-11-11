#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <string>
#include "Utils.h"

// Concrete implementation of the IPositionable interface for tracking cursor position
class DisplayCursor : public IPositionable {
private:
   int row; // explicit declaration
   int col;

public:
   DisplayCursor();
   void set(int newRow, int newCol) override;  // match signature
   void next() override;
   int getRow() const override;
   int getCol() const override;
};

class Display {
private:
   DisplayCursor cursor; // Uses the concrete implementation internally
   LiquidCrystal lcd;  // Class composition

public:
   Display();

   void begin();
   void writeCharAt(int row, int col, char character);
   void writeTextAt(int row, int col, const std::string text);
   void writeIntAt(int row, int col, int value);
   void clearRow(int row);
   void clearCharAt(int row, int col);
};

#endif
