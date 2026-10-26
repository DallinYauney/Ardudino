// #include "Utils.ino"
#include "Display.ino"

class Character {
    Position position;
    float velocity;
    float height;

    Character() {
        velocity = 0;
        height = 0;
    }

    /**
     * Called every frame, with `deltaTime` representing the
     * number of milliseconds since the last call.
     */
    public: void update(int deltaTime) {
        // TODO: conditionally trigger begin_jump()
        // TODO: set correct row for character based on height (100+ means top row)
        
        velocity -= 0.01 * deltaTime; // gravity (very rough estimate)
        if(height <= 0) {
            // if on ground
            velocity = 0; // don't travel through the ground
            height = 0; // reset height if already in ground
        }
        height -= velocity * deltaTime; // apply velocity
    }


    void begin_jump() {
        velocity = 30;
    }
};