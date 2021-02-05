//calculate metrics that are put on the screen
#include <SDL/SDL.h>
#include <cmath>


double getFPS()
{
  static Uint32 lastTime = 0; //only set to 0 on the first time this function is called
                              //otherwise has the value assigned to it last time the function was called

  Uint32 currTime = SDL_GetTicks(); //current timestamp in milliseconds
  Uint32 delta_t = currTime - lastTime; //the time since this function was last called. i.e. milliseconds per frame
  double fps =  1000.0 / delta_t;  // reciprocal of seconds per frame is frames per seconds (also convert from milliseconds to seconds)
  lastTime = currTime;
  return fps;
}

double getPeriod(double omega)
{
  static double period = 0;
  static double lastOmega = 0;
  static Uint32 lastTime = 0;

  if (omega == 0 || std::signbit(lastOmega) != std::signbit(omega)) //check if the pendulum has changed directions
  {
    Uint32 currTime = SDL_GetTicks();
    period = 2 * (currTime - lastTime) * 0.001;
    lastTime = currTime;
  }
  lastOmega = omega;
  return period;
}
