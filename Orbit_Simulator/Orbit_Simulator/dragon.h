/***********************************************************************
* Header File:
*    Dragon: Definition of the Dragon class
* Author:
*    Efrain Gomez Fajardo
* Summary:
*     The Dragon is one of the orbital objects.
************************************************************************/
#pragma once
#include "orbitalObject.h"

/************************
* DRAGON : ORBITAL OBJECT
*************************/
class Dragon : public OrbitalObject
{
public:

   double getRadius() {
      return 7.0;
   }

   // Constructors
   Dragon() : OrbitalObject() {}
   Dragon(Position position, Velocity velocity, Angle angle) : OrbitalObject(position, velocity, angle) {}

   // Virtual method
   void draw(ogstream& og)
   {
      og.drawCrewDragon(position, angle.get());
   }
};