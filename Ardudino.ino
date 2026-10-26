#include "Game.ino"

Game game = Game();

void setup(){

}

// Currently, basically just acts as a runner for Game
void loop(){
    game.update();
}