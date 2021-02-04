#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <cmath>
#include "prototypes.h"


int main(int argc, char* argv[])
{
    init();

    //initial angle
    double theta = M_PI  * 1.0;
    //initial angular velocity
    double omega = 0.05;

    //render loop
    while(1)
    {
        // Process incoming events.
        process_events();
        // Draw the screen.
        display(theta);
        // Move the pendulum
        step(theta, omega);
    }

    return 0;
}
