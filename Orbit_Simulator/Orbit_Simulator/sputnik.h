/***********************************************************************
* Header File:
*    Sputnik: Definition of the Sputnik class
* Author:
*    Efrain Gomez Fajardo
* Summary:
*     The Sputnik is one of the orbital objects.
************************************************************************/
#pragma once
#include "orbitalObject.h"


/************************
* SPUTNIK : ORBITAL OBJECT
*************************/
class Sputnik : public OrbitalObject
{
public:

   // Constructors
   Sputnik() : OrbitalObject() {}
   Sputnik(Position position, Velocity velocity, Angle angle) : OrbitalObject(position, velocity, angle) {}

   // Virtual method
   void draw(ogstream& og)
   {
      og.drawSputnik(position, angle.get());
   }
};