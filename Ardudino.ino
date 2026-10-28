#include <LiquidCrystal.h>

int dinoPos = 0;
int cactusPos = 17;
const int dinoChar = 0b10111100;
const int cactusChar = 0b11000001;
const int screenWidth = 40;

//track score, increase speed vars
int score = 0;
int gameSpeed = 500; // Started slower than original 350ms
bool obstacleActive = false; 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  lcd.begin(16,2);
}

void loop(){
  lcd.scrollDisplayLeft();
  doDino();
  doCactus();

  // DISPLAY SCORE ON TOP ROW (Keeps it static as screen scrolls)
  lcd.setCursor((dinoPos) % 40, 0); 
  lcd.print("Score: ");
  lcd.print(score);

  delay(gameSpeed); // Uses dynamic speed variable
}

void doCactus() {
  if(!obstacleActive && random(3) == 0) {
    setChar(cactusPos, 1, cactusChar);
    obstacleActive = true;
  }

  // If cactus passes behind the dino, increment score and increase speed
  if (obstacleActive && (cactusPos % 40) == (dinoPos % 40)) {
    score++;
    obstacleActive = false;
    if (gameSpeed > 100) gameSpeed -= 25; // Accelerate game speed slightly
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
