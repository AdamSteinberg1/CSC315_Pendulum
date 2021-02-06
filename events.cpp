#include <SDL/SDL.h>
#include <algorithm>
#include "prototypes.h"

extern double camTheta;
extern double camPhi;

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

void handle_mouse(SDL_MouseMotionEvent* mEvent)
{
  if(mEvent->state & SDL_BUTTON_LMASK) //if the left mouse button is pressed
                                       //i.e. left clicked and dragged
  {
      const double dragSpeed = 0.1;
      camTheta += dragSpeed * mEvent->xrel;
      camPhi  -= dragSpeed * mEvent->yrel;

      camPhi = std::clamp(camPhi, 1.0, 179.0); //phi cannot be 0 or 180,
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
          case SDL_MOUSEMOTION:
              //handle mouse movements
              handle_mouse(&event.motion);
              break;
          case SDL_KEYDOWN:
              // Handle key presses.
              handle_key_down(&event.key.keysym);
              break;
          case SDL_QUIT:
              // Handle quit requests (like Ctrl-c).
              quit(0);
              break;
        }
    }
}
