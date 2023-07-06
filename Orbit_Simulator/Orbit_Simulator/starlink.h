/***********************************************************************
* Header File:
*    Starlink: Definition of the Starlink class
* Author:
*    Efrain Gomez Fajardo
* Summary:
*     The Starlink is one of the orbital objects.
************************************************************************/
#pragma once
#include "orbitalObject.h"

/************************
* STARLINK : ORBITAL OBJECT
*************************/
class Starlink : public OrbitalObject
{
public:

   // Constructors
   Starlink() : OrbitalObject() {}
   Starlink(Position position, Velocity velocity, Angle angle) : OrbitalObject(position, velocity, angle) {}

   // Virtual method
   void draw(ogstream& og)
   {
      og.drawStarlink(position, angle.get());
   }
};