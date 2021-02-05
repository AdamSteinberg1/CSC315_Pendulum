#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "prototypes.h"



int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    init();

    //initial angle
    double theta = M_PI  * 1.0;
    //initial angular velocity
    double omega = 0.05;

    double fps = 1;
    double period = 0;

    double t_step = -1;
    if(argc > 1)
    {
      t_step = strtod(argv[1], NULL);
    }

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
        if(t_step == -1)
          step(theta, omega, 1/fps);
        else
          step(theta, omega, t_step);
    }

    return 0;
}
