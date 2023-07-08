/***********************************************************************
* Header File:
*   Simulator
* Author:
*   Marco Varela
* Summary:
*   Orbit simulator
************************************************************************/
#pragma once
#include "orbitalObject.h"
#include "dreamChaser.h"
#include <list>

class TestHandleCollision;
class Interface;
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
   void input(const Interface*& pUI);

private:
   DreamChaser* dreamChaser;
   std::list<OrbitalObject*> orbitalObjects;
   Position ptUpperRight;           // Size of the screen.

   // Helper functions
   void reset();
   void handleCollision();
   void destroy();

};
