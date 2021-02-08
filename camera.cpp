#include <GL/glu.h>
#include <cmath>

//moves camera so that it has the spherical coordinates (radius, theta, phi)
void setCamera(double theta, double phi)
{
  const double radius = 30.0; //how far away the camera is from the origin

  //spherical coordinates to cartesian coordinantes
  double camX = radius * cos(theta) * sin(phi);
  double camY = radius * cos(phi);
  double camZ = radius * sin(theta) * sin(phi);

  gluLookAt(camX, camY, camZ, // Camera Position
              0, 0, 0,                    // Center of view
              0, 1, 0);                   // Up Vector
}
