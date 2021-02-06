#include <GL/glu.h>
#include <cmath>

struct Vec3
{
  double x;
  double y;
  double z;
};

//returns a × b
Vec3 cross(Vec3 a, Vec3 b)
{
  Vec3 result;
  result.x = a.y*b.z - a.z*b.y;
  result.y = a.z*b.x - a.x*b.z;
  result.z = a.x*b.y - a.y*b.x;
  return result;
}

//shrinks or stretchs a vector so that its magnitude is 1
Vec3 normalize(Vec3 v)
{
  double magnitude = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
  Vec3 result;
  result.x = v.x/magnitude;
  result.y = v.y/magnitude;
  result.z = v.z/magnitude;
  return result;
}

//moves camera so that it has the spherical coordinates (radius, theta, phi)
void setCamera(double theta, double phi)
{
  const double radius = 30.0; //how far away the camera is from the origin

  Vec3 camPos; //vector pointing from origin to camera
  //spherical coordinates to cartesian coordinantes
  camPos.x = radius * cos(theta) * sin(phi);
  camPos.y = radius * cos(phi);
  camPos.z = radius * sin(theta) * sin(phi);

  Vec3 look; //vector pointing where the camera is looking
  look.x = -camPos.x;
  look.y = -camPos.y;
  look.z = -camPos.z;

  Vec3 globalUp = {0.0, 1.0, 0.0};
  Vec3 right = cross(look, globalUp);
  Vec3 camUp = normalize(cross(right, look));

  gluLookAt(camPos.x, camPos.y, camPos.z, // Camera Position
              0, 0, 0,                    // Center of view
              camUp.x, camUp.y, camUp.z); // Up Vector
}
