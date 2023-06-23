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
#include "orbital_object.h"

class Simulator {
public:
   void handleCollision();
   void addOrbitalObject(OrbitalObject* object);

private:
   std::vector<OrbitalObject*> orbitalObjects;
};
