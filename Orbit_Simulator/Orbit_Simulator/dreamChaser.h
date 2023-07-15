/***********************************************************************
* Header File:
*    Dream Chaser: Definition of the Dream Chaser class
* Author:
*    Efrain Gomez Fajardo
* Summary:
*     This is the ship that the user can move. Bullets come from
*     here when they are created.
************************************************************************/
#pragma once
#include "orbitalObject.h"

class Interface;
/************************
* DREAM CHASER : ORBITAL OBJECT
*************************/
class DreamChaser : public OrbitalObject
{
public:
   double getRadius() {
      return 10.0;
   }
   // Constructors
   DreamChaser() : OrbitalObject() {}
   DreamChaser(Position position, Velocity velocity, Angle angle) : OrbitalObject(position, velocity, angle), frontShip(angle) {}

   // Virtual method
   void draw(ogstream& og)
   {
      og.drawShip(position, frontShip.get(), thrust);
   }

   // virtual override
   void update(double thruster);

   // For getting keystrokes so it can move
   void input(const Interface*& pUI);

private:
   Angle frontShip;
   bool thrust = false;

   // Changing the thrust
   void fireThruster() { thrust = true; }
   void stopThruster() { thrust = false; }
};