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

   // Constructors
   DreamChaser() : OrbitalObject() {}
   DreamChaser(Position position, Velocity velocity, Angle angle) : OrbitalObject(position, velocity, angle) {}

   // Virtual method
   void draw(ogstream& og)
   {
      og.drawShip(position, angle.get(), thrust);
   }
   
   // virtual override
   void update();

   // For getting keystrokes so it can move
   void move(const Interface*& pUI);


private:
   bool thrust = false;
};