#include <cmath>

//equations to model the motion of the pendulum

// These two functions are the first and second derivative equations
// to be used in the Runge-Kutta method for the dynamical motion of the pendulum

double thetadot(double t, double theta, double omega)
{
   return omega;
}

double omegadot(double t, double theta, double omega)
{
   const double R = 1.00;  // Length of pendulum  (meters)
   const double g = 9.80;  // Normalized gravitational constant  (m/s^2)
   const double b = 0.1;  // Frictional damping constant
   const double m = 1.00;  // Mass in normalized gravitational units (kg)
   const double A = 0.00;  // Amplitude of initial driving force
   const double k = 0.00;  // Frequency parameter of initial driving force

   double num, denom;

   num = -b*omega + A*cos(k*t);

   denom = m*R*R;
   // To test limiting case of small theta, use following line of code
   //return -g/R*theta;


   return (-g/R*sin(theta)+num)/denom;

}


// This is the function that actually propagates the motion

void step(double & theta, double & omega, double fps)
{
  static double t = 0;
  // Time step variable
  double h;
  // variables for fourth-order Runge-Kutta method
  double k1, k2, k3, k4, j1, j2, j3, j4;

  h = 1.0 / fps;

// Fourth-Order Runge-Kutta propagation step for second order dynamical systems
  k1 = thetadot(t, theta, omega);
  j1 = omegadot(t, theta, omega);
  k2 = thetadot(t+h/2, theta+h/2*k1, omega+h/2*j1);
  j2 = omegadot(t+h/2, theta+h/2*k1, omega+h/2*j1);
  k3 = thetadot(t+h/2, theta+h/2*k2, omega+h/2*j2);
  j3 = omegadot(t+h/2, theta+h/2*k2, omega+h/2*j2);
  k4 = thetadot(t+h, theta+h*k3, omega+h*j3);
  j4 = omegadot(t+h, theta+h*k3, omega+h*j3);
  theta += h/6*(k1+2*k2+2*k3+k4);
  omega += h/6*(j1+2*j2+2*j3+j4);
  t += h;

  if(theta > 2 * M_PI)
    theta -= 2 * M_PI;
}
