#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "prototypes.h"

#include <iostream>


int main(int argc, char* argv[])
{
    init();

    //render loop
    while(1)
    {
        // Process incoming events.
        process_events();
        // Draw the screen.
        display();
    }

    return 0;
}
