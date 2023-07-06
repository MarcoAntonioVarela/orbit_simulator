/***********************************************************************
* Source File:
*    Velocity : Implementation of the Velocity class
* Author:
*    Efrain Gomez Fajardo
* Summary:
*    
************************************************************************/

#include "acceleration.h"
#include "velocity.h"

const double SECONDS_PER_FRAME = 48.0;         // time
/***********************************************************************
* UPDATE
* Every frame this function is called. It updates the position
* of every Orbital Object using the following formula:
* dx = dx + at
* dy = dy + at
************************************************************************/
void Velocity::update(const Acceleration & acceleration)
{
   dx = dx + acceleration.getDDX() * SECONDS_PER_FRAME;
   dy = dy + acceleration.getDDY() * SECONDS_PER_FRAME;
}

std::ostream& operator<<(std::ostream& out, const Velocity& v)
{
   out << "(" << v.getDX() << "m , " << v.getDY() << "m)";
   return out;
}

std::istream& operator>>(std::istream& in, Velocity& a)
{
   double dx;
   double dy;
   in >> dx >> dy;

   a.setDX(dx);
   a.setDY(dy);

   return in;
}
