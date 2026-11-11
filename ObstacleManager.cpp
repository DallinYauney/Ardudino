#include "Obstacles/Obstacles.cpp"
#include "Display.h"
#include "Character.h"
#include <array>

class ObstacleManager {
    private:
    // Obstacle obstacles[4];
    std::array<Obstacle, 4> obstacles;
    CharacterPosition *characterPosition;

    public:
    ObstacleManager(CharacterPosition *characterPosition) {
        characterPosition = characterPosition;
        // TODO: create four basic obstacles (ie not random - the first four obstacles 
        //   should always be the same)
    }

    /**
     * called every frame. returns true if the game should end, else false
     */
    bool update(int deltaTime) {
        // TODO: if an obstacle isOffscreenLeft, remove it and generate a new
        //   one in offscreen right in its place.


        // loop through each obstacle and modify their position
        for(Obstacle obstacle : obstacles) {
            obstacle.update(deltaTime);
        }

        // if an obstacle is colliding with the player (loop), return `true`
        for(Obstacle obstacle : obstacles) {
            if(obstacle.hasCollision(characterPosition)) return true;
        }

        return false;
    }

    void display(Display display) {
        for(Obstacle obstacle : obstacles) {
            obstacle.display(display);
        }
    }
};