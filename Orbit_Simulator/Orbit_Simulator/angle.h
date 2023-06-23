/***********************************************************************
* Header File:
*    Angle : Representation of an Angle
* Author:
*    Efrain Gomez Fajardo
* Summary:
*    
************************************************************************/

#pragma once
#define PI 3.1415926
#define PI2  PI * 2

/***********************************
* CLASS ANGLE
* Represents an angle. It is stored in
* radians
************************************/
class Angle
{
private:
   double aRadians;

   // Converts radians into degrees.
   double convertToDegrees(double radians);

   // Converts degrees into radians.
   double convertToRadians(double degrees);

   // Converts an angle above
   // 0 and 2 Pi to be between that range.
   double normalize(double radians);

public:

   //Constructors
   Angle();
   Angle(const Angle& rhs);
   Angle(double degrees);

   // Return the angle.
   double get() const { return aRadians; }

   // Stores the given angle.
   void set(double radians);
};