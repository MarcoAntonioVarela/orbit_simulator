/***********************************************************************
 * Source File:
 *   Simulator
 * Author:
 *   Marco Varela
 * Summary:
 *   Attributes and methods for Orbit simulator
 ************************************************************************/

#include <vector>
#include "orbitalObject.h"
#include "simulator.h"
#include "gps.h"
#include "bullet.h"

void Simulator::handleCollision()
{
      if (orbitalObjects[0]->getPosition() == orbitalObjects[1]->getPosition()) 
      {
         orbitalObjects[0]->kill();
         orbitalObjects[1]->kill();
      }
}
