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
class GPS : public OrbitalObject
{
   friend class TestPart;
   public:

      // Constructors
      GPS() : OrbitalObject() {};
      GPS(Position position, Velocity velocity, Angle angle) : OrbitalObject(position, velocity, angle) {};

      // Virtual methods
      void draw(ogstream& og)
      {
         og.drawGPS(position, angle.get());
      }
};


/************************
* DUMMY GPS : GPS
*************************/
class DummyGPS : public GPS
{
public:
   DummyGPS() : GPS() {};
   bool getPosition() const { return false; }
   bool getVelocity() const { return false; }
   bool getAngle()    const { return false; }
};


/************************
* STUB GPS : DUMMY GPS
* Stub class for the position
* x = 50.0
* y = 50.0
*************************/
class StubGps5050 : public DummyGPS
{
   friend TestHandleCollision;
private:
   void set() { position = Position(50.0, 50.0); }
public:
   StubGps5050() : DummyGPS() { set(); }
};
