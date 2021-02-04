#include <SDL/SDL.h>
#include "prototypes.h"

void handle_key_down(SDL_keysym* keysym)
{
    switch(keysym->sym)
    {
      case SDLK_ESCAPE:
      case SDLK_q:
          quit(0);
          break;
      default:
          break;
    }
}

void process_events()
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
