/***********************************************************************
* Source File:
*    Angle : Implementation of the Angle class
* Author:
*    Efrain Gomez Fajardo
* Summary:
*     Where each Orbital Object is facing. 0 is up
************************************************************************/
#include "angle.h"

// Default constructor.
Angle::Angle() : aRadians(0.0) {}

// Copy constructor.
Angle::Angle(const Angle& rhs)
{
   aRadians = rhs.aRadians;
}

// Non-default constructor.
Angle::Angle(double degrees)
{
   aRadians = convertToRadians(degrees);
}

// Converts radians into degrees.
double Angle::convertToDegrees(double radians)
{
   return radians * (180.0 / PI);
}

// Converts degrees into radians.
double Angle::convertToRadians(double degrees)
{
   return degrees / (180.0 / PI);
}

// Converts an angle above
// 0 and 2 Pi to be between that range.
double Angle::normalize(double radians)
{
   while (radians < 0 || radians > PI2)
   {
      if (radians < 0)
      {
         radians += (PI2);
      }
      if (radians >= (PI2))
      {
         radians -= (PI2);
      }
   }
   return radians;
}

// Stores the given angle.
void Angle::set(double radians)
{
   aRadians = normalize(radians);
}
