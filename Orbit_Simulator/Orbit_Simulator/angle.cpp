/***********************************************************************
* Source File:
*    Angle : Implementation of the Angle class
* Author:
*    Efrain Gomez Fajardo
* Summary:
*     Where each Orbital Object is facing. 0 is up
************************************************************************/
#include "angle.h"
#include "position.h"
#include <cmath>
   
/**********************************************
* NON-DEFAULT CONSTRUCTOR
* Takes the angle in degrees and converts them in radians
***********************************************/
Angle::Angle(double degrees)
{
   aRadians = convertToRadians(degrees);
}

/**********************************************
* ANGLE : CONVERT TO RADIANS
* Used by the non-default constructor.
* Uses the math formula:
* radians = degrees / (180 / PI)
***********************************************/
double Angle::convertToRadians(double degrees)
{
   return degrees / (180.0 / PI);
}

/**********************************************
* ANGLE : NORMALIZE
* Converts an angle above
* 0 and 2 PI to be between that range.
***********************************************/
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

/**********************************************
* ANGLE : SET
* Helper function used to modify the radians 
***********************************************/
void Angle::set(double radians)
{
   aRadians = normalize(radians);
}

/**********************************************
* ANGLE : UPDATE
* Changes the angle based on the math formula:
* radians = atan(xe - xs, ye - ys) where
* xe : Position in x of the Earth
* ye : Position in y of the Earth
* xs : Position in x of the satellite
* ys : Position in y of the satellite
***********************************************/
void Angle::update(const Position& position)
{
   aRadians = atan2(0 - position.getMetersX(), 0 - position.getMetersY());
}

/******************************************
 * POINT : ASSIGNMENT
 * Assign a point
 *****************************************/
Angle& Angle::operator = (const Angle& a)
{
   aRadians = a.aRadians;
   return *this;
}

std::ostream& operator<<(std::ostream& out, const Angle& a)
{
   out << a.get() << "radians";
   return out;
}

std::istream& operator>>(std::istream& in, Angle& a)
{
   double aRadians;
   in >> aRadians;

   a.set(aRadians);

   return in;
}
