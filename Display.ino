#include <LiquidCrystal.h>
#include "Character.ino"
#include "Utils.ino"

class Display {
    Position cursor;
    public: LiquidCrystal display;
    
    public:
    Display() {
        // TODO: Update this with the R/W (I think) pin
        display = LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
        position = Position {
            row: 1;
            col: 0;
        }
    }

    void writeCharAt(int row, int col, char character) {
        display.setCursor(row, col);
        display.write(character);
        cursor.setAfter(row, col);
    }
};