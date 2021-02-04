#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>


void display(double theta)
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();   // Call this before setting the viewing position

    //Set camera parameters
    gluLookAt(  0.0,   5.0, 0.0,  // Eye Position
                5.0,   0.0, 5.0,  // Center of view
                0.0,   1.0, 0.0); // Up Vector


    // Draw a blue cylinder
    glColor3f(0.0,1.0,0.0);
    glPushMatrix();
    glTranslated(5.0,4.0,5.0);
    glRotated(theta * 180 / M_PI, 0,0,1);
    glRotated(90, 1,0,0);
    glColor3f (0.0,0.0,1.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.2,   //bottom radius
            (GLdouble) 0.2,   //top radius
            (GLdouble) 6.0,   //height
            (GLint)    20,    //slices => makes the base an n-gon
            (GLint)    1 );   //stacks
    glPopMatrix();

    SDL_GL_SwapBuffers();
}
