#include <LiquidCrystal.h>

int dinoPos = 0;
int cactusPos = 17;
const int dinoChar = 0b10111100;
const int cactusChar = 0b11000001;
const int screenWidth = 40;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup(){
  lcd.begin(16,2);
}

void loop(){
  lcd.scrollDisplayLeft();
  doDino();
  doCactus();

  delay(350);
}

void doCactus() {
  if(random(3) == 0) {
    setChar(cactusPos, 1, cactusChar);
  }

  cactusPos += 1;
}

void doDino() {
  setChar(dinoPos, 1, ' ');
  dinoPos += 1;
  setChar(dinoPos, 1, dinoChar);
}

void setChar(int col, int row, char character) {
  lcd.setCursor(col % 40, row);
  lcd.write(character);
}










