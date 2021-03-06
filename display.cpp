#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
#include <string>

#include "prototypes.h"

double camTheta = 225;
double camPhi = 80;

void drawPendulum(double theta)
{
  glPushMatrix();

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

  glTranslated(-5, 2, 10.0);
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

void drawMetrics(double fps, double period)
{
  //get window width and height
  SDL_Surface* surface = SDL_GetVideoSurface();
  int width = surface->w;
  int height = surface->h;

  //clear the modelview matrix
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  //set the projection matrix to a 2D orthographic projection in pixel coordinates
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0, width, 0, height);


  std::string fpsText = "FPS = " + std::to_string(fps);
  std::string periodText = "Period = " + std::to_string(period);

  void* font = GLUT_BITMAP_HELVETICA_18;
  int textHeight = 18; //this font has a height of 18


  glColor3f(1.0,1.0,1.0);
  //position on screen to start writing
  glRasterPos2i(0, 0);

  //write string
  for (char c : fpsText)
  {
      glutBitmapCharacter(font, c);
  }

  glRasterPos2i(0, textHeight);

  //write string
  for (char c : periodText)
  {
      glutBitmapCharacter(font, c);
  }

  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
}

void display(double theta, double fps, double period)
{

  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glLoadIdentity();   // Call this before setting the viewing position

  //Set camera parameters
  setCamera(camTheta*M_PI/180, camPhi*M_PI/180);

  drawPendulum(theta);
  drawMan();
  drawMetrics(fps, period);
  SDL_GL_SwapBuffers();
}
