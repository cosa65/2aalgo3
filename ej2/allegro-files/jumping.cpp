int main(int argc, char const *argv[])
{
    /* code */

//First of all, we need some information about the player who is performing the jump:
 
// xy coordinates
float x, y;
 
// velocity (in x and y, which means the speed we're going in each orthogonal direction)
float dx, dy;
 
// to keep track if the player can jump again so he doesn't perform another jump midair
bool mayJumpAgain = false;
 
// is true if the player is on the ground
bool isOnSolidGround; 
 
// game loop
while (true) {
    // first we check if the player is on solid ground
    if (isOnSolidGround) {
        // apply friction - we do this by reducing the x velocity
        dx *= 0.9;
 
        // handle the jump action (note: you need to set JUMP_KEY_IS_PRESSED to 
        // true when the key is pressed and to false when it's not somewhere in
        // your game loop)
        if (JUMP_KEY_IS_PRESSED == true) {
            // may the player jump again? (i.e. the jump key has been released
            // since we last performed a jump)
            if (mayJumpAgain) {
                dy = -10; // we set the y velocity to negative value so that we go up
                mayJumpAgain = false;
            }
        }
        else {
            // as up is not pressed anymore we can jump again
            mayJumpAgain = true;
        }
    }
 
    // handle the player running left
    if (RUNNING_LEFT_KEY_IS_PRESSED == true)
        dx = -3; // we want to go left so we set x velocity to a negative number
 
    // handle the player running right
    if (RUNNING_RIGHT_KEY_IS_PRESSED == true)
        dx = 3; // we want to go left so we set x velocity to a positive number
 
    // if we're falling we apply some gravity
    if (!isOnSolidGround)
        dy += 0.5; // we increase our velocity in y so that we start to go down
 
    // if the player is keeping the jump key pressed we continually decrease the
    // velocity in y, but less than the gravity above (e.g. 0.5), otherwise
    // we'll keep going up until the key is pressed. Doing this the jump will
    // be performed until a certain height (when dy > 0), after that only gravity
    // will be applied and the player will fall down
    if (JUMP_KEY_IS_PRESSED == true && !isOnSolidGround && dy > 0)
        dy -= 0.1; // got to be LESS than 0.5 in this example
 
    // let's make sure the player can't fall faster than a certain speed
    if (dy > 5)
        dy = 5;
 
    // update the position of the player
    x += dx;
    y += dy;
 
    // handle collision detection with ground
    if(playerCollidedWithGround()) {
        y = positionJustAboveGround;
        dy = 0;
        isOnSolidGround = true;
    }
 
    // collision detection is out of scope for this tutorial
    // for a basic platformer you need to check collision with tiles
    // depending on from which direction you hit the tile you need to do certain stuff
    // for example when you jump and hit a tile above you, you need to place the player
    // just below the tile and set dy = 0 so that he starts falling down
 
    // this game loop is incomplete of course, after this you need to do everything else
    // such as drawing, handling logic, updating enemies and bullets, etc...
}


    return 0;
}
