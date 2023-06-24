/***********************************************************************
* Header File:
*    GPS : One of the Satelites that orbits the Earth
* Author:
*    Efrain Gomez Fajardo
* Summary:
*    The atttributes and methods related to GPS.
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



class DummyGPS : protected GPS
{
public:
   bool getPosition() const { return false; }
   bool getVelocity() const { return false; }
   bool getAngle()    const { return false; }
};



class StubGps5050 : protected DummyGPS
{
   friend TestHandleCollision;
   protected:
      Position position = Position(50.0, 50.0);
};


