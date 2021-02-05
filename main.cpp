#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include "prototypes.h"



int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    init();


    //initial angle
    double theta = M_PI  * 1.0;
    //initial angular velocity
    double omega = 0.05;

    double fps = 0;
    double period = 0;

    //render loop
    while(1)
    {
        // Process incoming events.
        process_events();
        // Draw the screen.
        display(theta, fps, period);
        //get fps for this frame
        fps = getFPS();
        //get most recent period
        period = getPeriod(omega);
        // Move the pendulum
        step(theta, omega, fps);
    }

    return 0;
}
