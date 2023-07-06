/***********************************************************************
* Header File:
*    Hubble: Definition of the Hubble class
* Author:
*    Efrain Gomez Fajardo
* Summary:
*     The Hubble is one of the orbital objects.
************************************************************************/
#pragma once
#include "orbitalObject.h"


/************************
* DRAGON : ORBITAL OBJECT
*************************/
class Hubble : public OrbitalObject
{
public:

   // Constructors
   Hubble() : OrbitalObject() {}
   Hubble(Position position, Velocity velocity, Angle angle) : OrbitalObject(position, velocity, angle) {}

   // Virtual method
   void draw(ogstream& og)
   {
      og.drawHubble(position, angle.get());
   }
};