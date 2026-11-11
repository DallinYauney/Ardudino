#include "Display.h"
#include "Character.h"
#include "ObstacleComponent.cpp"
#include <array> // standard C arrays are so awful

class Obstacle {
    private:
    float position;
    int row;
    std::array<ObstacleComponent, 12> components;

    public:
    Obstacle() {
        row = -1;
        position = -1;

        components = {
            // empty components (default constructor) are inserted by default I'm pretty sure
        };
    }

    /**
     * Displays its contents onto the screen 
     */
    void display(Display display) {
        for(ObstacleComponent component : components) {
            display.writeCharAt(
                row + component.getDRow(),
                // col + component.getDCol(),
                0 + component.getDCol(),
                component.getChar()
            );
        }
    }

    /**
     * Called every frame. Moves the obstacle's components.
     */
    void update(int deltaTime) {
        position -= 0.13 * deltaTime; // scroll left at set speed
    }

    bool hasCollision(CharacterPosition *player) {
        for(ObstacleComponent component : components) {
            if(component.getIsEmpty()) continue;

            int globalRow = row + component.getDRow();
            // int globalCol = col + component.getDCol();
            int globalCol = 0 + component.getDCol();
            if(
                player->getRow() == globalRow &&
                player->getCol() == globalCol
            ) {
                return true;
            }
        }
        return false;
    }

    /**
     * Calculates whether the whole obstacle has moved off
     * the left side of the screen.
     */
    bool isOffscreenLeft() {
        for(ObstacleComponent component : components) {
            if(component.getIsEmpty()) continue;

            int globalRow = row + component.getDRow();
            if(globalRow >= 0) return false;
        }
        return true;
    }
};