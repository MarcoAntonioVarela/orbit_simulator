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
* UPDATE
* Every frame this function is called. It updates the position
* of every Orbital Object using the following formula:
* ddx = a sin(angle)
* ddy = a cos(angle)
************************************************************************/
void Acceleration::update(const Angle& angle, double acceleration)
{
   ddx = acceleration * sin(angle.get());
   ddy = acceleration * cos(angle.get());
}
