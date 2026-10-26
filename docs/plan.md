# Overall Project Plan

The idea is to connect an LCD to the arduino, along with one button to jump.

## Game Mechanics

There's a character on the left of the screen, and obstacles come from the right side (or, technically, which he encounters as he moves to the right) which he has to jump to avoid. The speed of the oncoming obstacles grows over time, and so do the points (kept track of on a separate LCD probably).


### Update

We borrow our update calls from real game engines like Unity. The basic idea is that we have a maximum framerate, which is controlled by a core part of the game, and all of the components are simply told how much (estimated) time has passed since the last frame. This means we can change the framerate without having to adjust all the components individually (useful for having speed not locked 1:1 with the framerate). This also means that, in the event of a one-off lag spike, the game can more or less recover and put things where they ought to be.

See also: [This helpful explainer video](https://www.youtube.com/watch?v=yGhfUcPjXuE)
