/***********************************************************************
 * Source File:
 *   Simulator
 * Author:
 *   Marco Varela
 * Summary:
 *   Orbit simulator
 ************************************************************************/

#include "simulator.h"

void Simulator::handleCollision()
{
   // Here goes the code to handle the collision?
   

   // For the purpose of the example, let's set all objects as dead
   for (auto& obj : orbitalObjects)
      obj->isDead = true;
}

void Simulator::addOrbitalObject(OrbitalObject* object)
{
   orbitalObjects.push_back(object);
}
