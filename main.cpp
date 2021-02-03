#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "prototypes.h"

#include <iostream>


static void handle_key_down(SDL_keysym* keysym)
{
    switch(keysym->sym)
    {
      case SDLK_ESCAPE:
          quit(0);
          break;
      default:
          break;
    }
}

static void process_events()
{
    SDL_Event event;

    /* Grab all the events off the queue. */
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
          case SDL_KEYDOWN:
              /* Handle key presses. */
              handle_key_down(&event.key.keysym);
              break;
          case SDL_QUIT:
              /* Handle quit requests (like Ctrl-c). */
              quit(0);
              break;
        }
    }
}

static void draw_screen(void)
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();   // Call this before setting the viewing position

    // We are going to set our position to be down the Y-Axis looking at the
    // center of the coordinate frame.  The positive Z-Axis will be up.

    gluLookAt( 20.0,   0.0, 5.0,  // Eye
                0.0,   0.0, 0.0,  // Center
                0.0,   0.0, 1.0); // Up


    glEnable(GL_DEPTH_TEST);

    glColor3f(0.0,1.0,0.0);

    // This should be to draw a cylinder
    glPushMatrix();
    glTranslated(2.0,0.0,0.0);
    glColor3f (0.0,0.0,1.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.1,
            (GLdouble) 0.1,
            (GLdouble) 4.0,
            (GLint)    20,
            (GLint)    20 );
    glPopMatrix();

    // This should draw a green doughnut
    glPushMatrix();
    glRotated(90.0,0,1,0);
    glTranslatef(2.0,0.0,0.0);
    glColor3f (0.0,1.0,0.0);
    gluDisk(gluNewQuadric(),
            (GLdouble) 0.5,
            (GLdouble) 1.0,
            (GLint)     10,
            (GLint)     20 );
    glPopMatrix();

    // This should draw a red sphere
    glPushMatrix();
    glTranslatef(-3.0,1.0,1.0);
    glColor3f (1.0,0.0,0.0);
    gluSphere(gluNewQuadric(),
             (GLdouble) 1.5,
             (GLint)     10,
             (GLint)     10 );
    glPopMatrix();

    // This should draw a purple ellipsoid
    glPushMatrix();
    glTranslatef(-3.0,1.0,-4.0);
    glScalef(0.5,0.5,1.0);
    glColor3f (1.0,0.0,1.0);
    gluSphere(gluNewQuadric(),
             (GLdouble) 1.5,
             (GLint)     10,
             (GLint)     10 );
    glPopMatrix();

    SDL_GL_SwapBuffers();
}

static void setup_opengl(int width, int height)
{
    glShadeModel(GL_FLAT);

    glClearColor(0, 0, 0, 0);

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float ratio = (float) width / (float) height;
    gluPerspective(60.0, ratio, 1.0, 1024.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[])
{
    /* Information about the current video settings. */
    const SDL_VideoInfo* info = NULL;
    /* Dimensions of our window. */
    int width = 0;
    int height = 0;
    /* Color depth in bits of our window. */
    int bpp = 0;
    /* Flags we will pass into SDL_SetVideoMode. */
    int flags = 0;

    /* First, initialize SDL's video subsystem. */
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        /* Failed, exit. */
        std::cerr << "Video initialization failed: " << SDL_GetError() << std::endl;
        quit(1);
    }

    /* Let's get some video information. */
    info = SDL_GetVideoInfo();

    if(!info)
    {
        /* This should probably never happen. */
        std::cerr << "Video query failed: " << SDL_GetError() << std::endl;;
        quit(1);
    }

    bpp = info->vfmt->BitsPerPixel;


    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //flags = SDL_OPENGL | SDL_FULLSCREEN;
    flags = SDL_OPENGL | SDL_RESIZABLE | SDL_NOFRAME;

    if(SDL_SetVideoMode(width, height, bpp, flags) == 0) //a width and height of 0 makes the resolution default to the display resolution
    {
        std::cerr << "Video mode set failed: " << SDL_GetError() << std::endl;;
        quit(1);
    }

    //we know have to query what the display resolution is
    SDL_Surface* surface = SDL_GetVideoSurface();
    width = surface->w;
    height = surface->h;

    setup_opengl(width, height);

    //render loop
    while(1)
    {
        /* Process incoming events. */
        process_events();
        /* Draw the screen. */
        draw_screen();
    }

    return 0;
}
