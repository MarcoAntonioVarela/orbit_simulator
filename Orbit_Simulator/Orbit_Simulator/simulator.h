/***********************************************************************
* Header File:
*   Simulator
* Author:
*   Marco Varela
* Summary:
*   Orbit simulator
************************************************************************/
#pragma once
#include "orbitalObject.h" // For the list to initialize
#include "dreamChaser.h"   // Since the user will manipule it, we need to know it here
#include "star.h"          // For STAR
#include <list>            // For std::list

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
   void update(const Interface*& pUI);

private:
   std::list<OrbitalObject*> orbitalObjects;
   std::list<Star> stars;
   Position ptUpperRight;           // Size of the screen.

   // Helper functions
   void reset();
   void handleCollision();
   void destroy();

};
