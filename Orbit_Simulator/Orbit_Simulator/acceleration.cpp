/***********************************************************************
* Source File:
*    Acceleration : Implementation of the Acceleration class
* Author:
*    Efrain Gomez Fajardo
* Summary:
*    No class uses this class by composition. It is meant to be 
*    used only as a parameter.
************************************************************************/
#include "acceleration.h"
#include "angle.h"
#include <cmath>

/***********************************************************************
* ACCELERATION
* Every frame this function is called. It updates the position
* of every Orbital Object using the following formula:
* ddx = a sin(angle)
* ddy = a cos(angle)
************************************************************************/
Acceleration::Acceleration(Angle& angle, double acceleration)
{
   ddx = acceleration * sin(angle.get());
   ddy = acceleration * cos(angle.get());
}

void Acceleration::update(Angle& angle, double acceleration)
{
   ddx = acceleration * sin(angle.get());
   ddy = acceleration * cos(angle.get());
}

std::ostream& operator<<(std::ostream& out, const Acceleration& a)
{
   out << "(" << a.getDDX() << "m/s2 , " << a.getDDY() << "m/s2)";
   return out;
}

std::istream& operator>>(std::istream& in, Acceleration& a)
{
   double ddx;
   double ddy;
   in >> ddx >> ddy;

   a.setDDX(ddx);
   a.setDDY(ddy);

   return in;
}
