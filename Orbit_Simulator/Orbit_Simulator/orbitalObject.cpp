/***********************************************************************
* Source File:
*    Orbital Object : Implementation of the Orbital Object class
* Author:
*    Efrain Gomez Fajardo
* Summary:
*    Implementation of the abstract base class that all the objects
*    inside the list on Simulator
************************************************************************/
#include "orbitalObject.h"
#include "acceleration.h"
#include <cmath>
using namespace std;

// Constants
const double EARTH_RADIUS  = 6378000.0;          // radius
const double EARTH_GRAVITY = -9.8067;            // gravity
/*********************************************
* UPDATE
* Physics computations that happen every frame
*********************************************/
void OrbitalObject::update()
{
   // Compute height
   // h = sqrt(x^2 + y^2) - r
   double height = sqrt((position.getMetersX() * position.getMetersX()) + (position.getMetersY() * position.getMetersY())) - EARTH_RADIUS;

   // Compute gravity
   // gh = g (r/r + h)^2
   double gravity = -(EARTH_GRAVITY * ((EARTH_RADIUS / (EARTH_RADIUS + height)) * (EARTH_RADIUS / (EARTH_RADIUS + height))));

   // Compute acceleration
   Acceleration acceleration(angle, gravity);

   // Compute position
   position.update(velocity, acceleration);

   // Compute velocity
   velocity.update(acceleration);

   // Compute angle
   angle.update(position);

   #ifdef DEBUG
   cout << "Height:    " << height        << endl;
   cout << "Gravity:   " << gravity       << endl;
   cout << "Pos:       " << position      << endl;
   cout << "Vel:       " << velocity      << endl;
   cout << "Acc:       " << acceleration  << endl;
   cout << "Angle:     " << angle         << endl << endl;
   #endif
}
