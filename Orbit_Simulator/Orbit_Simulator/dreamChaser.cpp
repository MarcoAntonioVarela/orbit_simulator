/***********************************************************************
*  Source File:
*    Dream Chaser: Implementation of the Dream Chaser class
* Author:
*    Efrain Gomez Fajardo
* Summary:
*     This is the ship that the user can move. Bullets come from
*     here when they are created.
************************************************************************/
#include "dreamChaser.h"
#include "uiInteract.h"
#include "acceleration.h"

// Repeated constant. It is also in orbitalObject.cpp
const double EARTH_GRAVITY = -9.8067;            // gravity
const double EARTH_RADIUS = 6378000.0;           // radius

/*************************************************
* DREAM CHASER : UPDATE
* Specific implementation from the parent. 
* Since the angle is changed by the user, we
* are not calling angle::update
**************************************************/
void DreamChaser::update(double thruster)
{
   // Compute height
   // h = sqrt(x^2 + y^2)
   double height = sqrt((position.getMetersX() * position.getMetersX()) + (position.getMetersY() * position.getMetersY())) - EARTH_RADIUS;

   // Compute gravity
   // gh = g (r/r + h)^2
   double gravity = -(EARTH_GRAVITY * ((EARTH_RADIUS / (EARTH_RADIUS + height)) * (EARTH_RADIUS / (EARTH_RADIUS + height))));

   // Compute acceleration
   Acceleration acceleration;
   acceleration.update(angle, gravity + thruster);

   // Compute velocity
   velocity.update(acceleration);

   // Compute position
   position.update(velocity, acceleration);

#ifdef DEBUG
   cout << "Height:    " << height << endl;
   cout << "Gravity:   " << gravity << endl;
   cout << "Pos:       " << position << endl;
   cout << "Vel:       " << velocity << endl;
   cout << "Acc:       " << acceleration << endl;
   cout << "Angle:     " << angle << endl << endl;
#endif
}

/*************************************************
* DREAM CHASER : MOVE
* Getting input from the keyboard, and determine how the
* Dream Chaser is going to move
**************************************************/
void DreamChaser::move(const Interface*& pUI)
{
   double thruster = 0.0;
   if (pUI->isDown())
   {
      // Accelerate 2.0 m/s2
      thruster = 2.0;
      fireThruster();
   }
   else if (pUI->isRight())
   {
      // Angle changes 0.1 radians to the right
      angle++;
      stopThruster();
   }
   else if (pUI->isLeft())
   {
      // Angle changes 0.1 radians to the left
      angle--;
      stopThruster();
   }
   update(thruster);
}
