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
#include "orbitalObject.h"

class TestHandleCollision;
class Simulator 
{
   friend TestHandleCollision;
public:
   void handleCollision();
   
   //void addOrbitalObject(OrbitalObject* object);

private:
   std::vector<OrbitalObject*> orbitalObjects;

};
