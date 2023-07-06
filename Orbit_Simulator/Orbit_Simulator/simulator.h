/***********************************************************************
* Header File:
*   Simulator
* Author:
*   Marco Varela
* Summary:
*   Orbit simulator
************************************************************************/
#pragma once
#include <vector>
#include <list>
#include "orbitalObject.h"

class TestHandleCollision;

/*********************************************
* SIMULATOR
* The main logic for the simulator
**********************************************/
class Simulator 
{
   friend TestHandleCollision;
public:

   // Constructors
   Simulator() : ptUpperRight(Position(0.0, 0.0)) {}
   Simulator(Position ptUpperRight) : ptUpperRight(ptUpperRight) { reset(); }

   // Public functions
   void add(OrbitalObject*& object);
   void draw(ogstream& og);
   void update();
   void input();

private:
   std::list<OrbitalObject*> orbitalObjects;
   Position ptUpperRight;           // Size of the screen.

   // Helper functions
   void reset();
   void handleCollision();
   void destroy();

};
