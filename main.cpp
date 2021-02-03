#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <iostream>

static void quit(int code)
{
    SDL_Quit();
    exit(code);
}

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
    //TODO add drawing in here
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

    width = 640;
    height = 480;
    bpp = info->vfmt->BitsPerPixel;


    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    flags = SDL_OPENGL | SDL_RESIZABLE;

    if(SDL_SetVideoMode(width, height, bpp, flags) == 0)
    {
        std::cerr << "Video mode set failed: " << SDL_GetError() << std::endl;;
        quit(1);
    }

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
