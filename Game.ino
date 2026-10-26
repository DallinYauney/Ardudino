#include "Character.ino"
#include "Display.ino"
#include "Utils.ino"

/**
 * The core logic for the game.
 * 
 * Responsible for:
 * 1. Generating obstacles
 * 2. Keeping track of the character
 * 3. Character-obstacle collisions & Game Over
 * 4. Writing to the display
 */
class Game {
    Display display;
    Character character;
    int prevTimestamp;
    int prevDeltaTime;
    int targetDeltaTime = 100; // 10 FPS

    public:
    Game() {
        display = Display();
        prevDeltaTime = targetDeltaTime; // Reasonable default
    }

    /**
     * Called by the main loop, responsible for updating the other components.
     */
    void update() {
        // TODO:
        // 1. Get current time (millis())
        // 2. Call all updates with prevDeltaTime
        // 3. Update prevDeltaTime based on current time (millis())
    }
};