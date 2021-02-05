#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>

void drawPendulum(double theta)
{
  glPushMatrix();
  glTranslated(25.0, 4.0, 25.0);

    glPushMatrix();
    glRotated(theta * 180 / M_PI, 0,0,1);
    glTranslated(0,-0.2, 0);
    glRotated(90, 1,0,0);
    glColor3f (1.0,1.0,1.0);
    // Draw pendulum rod
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.1,   //bottom radius
            (GLdouble) 0.1,   //top radius
            (GLdouble) 6.0,   //height
            (GLint)    20,    //slices => makes the base an n-gon
            (GLint)    1 );   //stacks


    glTranslated(0, 0, 7);
    glColor3f(1, 0, 0);
    // Draw pendulum bob
    gluSphere(gluNewQuadric(),
            (GLdouble) 1.0,   //radius
            (GLint)    10,    //slices
            (GLint)    10);   //stacks

    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 0, -0.2);
    glColor3f(0,1,0);
    // Draw anchor rod
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.2,   //bottom radius
            (GLdouble) 0.2,   //top radius
            (GLdouble) 6.0,   //height
            (GLint)    20,    //slices => makes the base an n-gon
            (GLint)    1 );   //stacks
    glPopMatrix();


    glPushMatrix();
    glTranslated(0,0,5.8);
      glPushMatrix();
      glRotated(90, 1,0,0);
      glColor3f(0, 1, 1);
      //draw stand rod
      gluCylinder(gluNewQuadric(),
              (GLdouble) 0.2,   //bottom radius
              (GLdouble) 0.2,   //top radius
              (GLdouble) 10.0,   //height
              (GLint)    20,    //slices => makes the base an n-gon
              (GLint)    1 );   //stacks
      glPopMatrix();

      glTranslated(0, -10, 0);
      glScaled(5, 1, 5);
      glRotated(45, 0, 0, 1 );
      glRotated(180, 0, 1, 0);
      glColor3f(0, 0, 1);
      //draw platform
      gluCylinder(gluNewQuadric(), //this cylinder is actually a cube!
              (GLdouble) 1,   //bottom radius
              (GLdouble) 1,   //top radius
              (GLdouble) 1.5,   //height
              (GLint)    4,    //slices => makes the base an n-gon
              (GLint)    1 );   //stacks
      glPopMatrix();

    glPopMatrix();


  glPopMatrix();
}

void drawMan()
{
  glColor3f(1,1,1);
  glPushMatrix();

  glTranslated(20.0, 6, 35.0);
  glScaled(0.668920, 0.668920,0.668920 ); //scale to make man 5' 8"

  //head
  gluSphere(gluNewQuadric(),
          (GLdouble) 1.0,   //radius
          (GLint)    10,    //slices
          (GLint)    10);   //stacks

  glRotated(90, 1,0,0);
  //torso
  gluCylinder(gluNewQuadric(),
          (GLdouble) 0.2,   //bottom radius
          (GLdouble) 0.2,   //top radius
          (GLdouble) 10.0,   //height
          (GLint)    20,    //slices => makes the base an n-gon
          (GLint)    1 );   //stacks

  glPushMatrix();
  glTranslated(0,0,4);
    glPushMatrix();
    glRotated(90, 0, 1, 0);
    //arm 1
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.2,   //bottom radius
            (GLdouble) 0.2,   //top radius
            (GLdouble) 10.0,   //height
            (GLint)    20,    //slices => makes the base an n-gon
            (GLint)    1 );   //stacks
    glPopMatrix();

    glPushMatrix();
    glRotated(-90, 0, 1, 0);
    //arm 2
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.2,   //bottom radius
            (GLdouble) 0.2,   //top radius
            (GLdouble) 10.0,   //height
            (GLint)    20,    //slices => makes the base an n-gon
            (GLint)    1 );   //stacks
    glPopMatrix();
  glPopMatrix();

  glPushMatrix();
    glTranslated(0, 0, 10 );
      glPushMatrix();
      glRotated(45, 0, 1, 0);
      //leg 1
      gluCylinder(gluNewQuadric(),
              (GLdouble) 0.2,   //bottom radius
              (GLdouble) 0.2,   //top radius
              (GLdouble) 10.0,   //height
              (GLint)    20,    //slices => makes the base an n-gon
              (GLint)    1 );   //stacks
      glPopMatrix();

      glPushMatrix();
      glRotated(-45, 0, 1, 0);
      //leg 2
      gluCylinder(gluNewQuadric(),
              (GLdouble) 0.2,   //bottom radius
              (GLdouble) 0.2,   //top radius
              (GLdouble) 10.0,   //height
              (GLint)    20,    //slices => makes the base an n-gon
              (GLint)    1 );   //stacks
      glPopMatrix();
  glPopMatrix();

  glPopMatrix();
}


void display(double theta)
{

  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glLoadIdentity();   // Call this before setting the viewing position

  //Set camera parameters
  gluLookAt(  0.0,   5.0, 0.0,  // Eye Position
              25.0,   0.0, 25.0,  // Center of view
              0.0,   1.0, 0.0); // Up Vector

  drawPendulum(theta);
  drawMan();
  SDL_GL_SwapBuffers();
}
