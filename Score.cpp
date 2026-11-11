#include "Display.h"
#include <string>

class Score {
    private:
    int score;

    public:
    void display(Display display) {
        int digits = log10(score);
        display.writeTextAt(0, 16 - digits, std::to_string(score));
    }

    void update(int deltaTime) {
        score += deltaTime / 5;
    }
};