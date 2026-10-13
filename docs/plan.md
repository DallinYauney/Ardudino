# Overall Project Plan

The idea is to connect an LCD to the arduino, along with one button to jump.

## Project Structure

### Dependencies

This project was written in Arduino Studio 2.5, and uses the following libraries:

- LiquidCrystal by Arduino, Adafruit

### Files and Folders

Documentation lives in the `/docs` folder, and proposals are made by submitting pull requests to markdown documents within it.

References and specifications live inside `/docs/reference`, such as data sheets and schematics.

## Game Mechanics

There's a character on the left of the screen, and obstacles come from the right side (or, technically, which he encounters as he moves to the right) which he has to jump to avoid. The speed of the oncoming obstacles grows over time, and so do the points (kept track of on a separate LCD probably).

Obstacles are generated in groups. For example, one group might comprise a flying obstacle, and a few tiles later, a ground one. The purpose of using groups over pure random generation is that the obstacles are guaranteed to be traversable - it's possible that a random obstacle generator could make a wall of obstacles too high to be jumped over, but a *random obstacle group generator* will not have this problem.

**Intention:** There should be an extra way to control the character, beyond "Press Button to Begin Jump." Options include releasing the jump button to fast-fall (see also: Hollow Knight and SSBU) and to have extra buttons to move right/left. I'm also open to more ideas beyond these. Which one we go with will require testing, hence this being marked with "Intention", but I'm interested in something to this effect.
