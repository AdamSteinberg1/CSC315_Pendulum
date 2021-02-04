#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include "prototypes.h"

void setup_opengl(int width, int height)
{
    glShadeModel(GL_FLAT);

    glClearColor(0, 0, 0, 0);

    glViewport(0, 0, width, height);

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float ratio = (float) width / (float) height;
    gluPerspective(60.0, ratio, 1.0, 1024.0);

    glMatrixMode(GL_MODELVIEW);
}


void init()
{
  /* First, initialize SDL's video subsystem. */
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
      /* Failed, exit. */
      std::cerr << "Video initialization failed: " << SDL_GetError() << std::endl;
      quit(1);
  }

  //Get information about the current video settings.
  const SDL_VideoInfo* info = SDL_GetVideoInfo();

  if(!info)
  {
      /* This should probably never happen. */
      std::cerr << "Video query failed: " << SDL_GetError() << std::endl;;
      quit(1);
  }

  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  //Dimensions of our window.
  //a width and height of 0 makes the resolution default to the display resolution
  int width = 0;
  int height = 0;

  int bpp = info->vfmt->BitsPerPixel;   // Color depth in bits of our window.

  int flags = SDL_OPENGL | SDL_FULLSCREEN;  //Flags for fullscreen
  //flags = SDL_OPENGL | SDL_RESIZABLE; //Flags for windowed

  if(SDL_SetVideoMode(width, height, bpp, flags) == 0)
  {
      std::cerr << "Video mode set failed: " << SDL_GetError() << std::endl;;
      quit(1);
  }

  //we now have to query what the display resolution is
  SDL_Surface* surface = SDL_GetVideoSurface();
  width = surface->w;
  height = surface->h;

  setup_opengl(width, height);
}
