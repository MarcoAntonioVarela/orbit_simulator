/***********************************************************************
* Header File:
*    GPS : One of the Satelites that orbits the Earth
* Author:
*    Efrain Gomez Fajardo
* Summary:
*    When collision happens, it is destroyed, and it
*    created three different parts.
************************************************************************/

#include "orbitalObject.h"
#include "position.h"
#include "velocity.h"
#include "angle.h"
#pragma once


/************************
* GPS : ORBITAL OBJECT
*************************/
class GPS : protected OrbitalObject
{
   friend class TestPart;
   public:
      Position getPosition() const { return position; }
      Velocity getVelocity() const { return velocity; }
      Angle getAngle()       const { return angle; }
};