/***********************************************************************
* Header File:
*    Parts : When a GPS collides, it creates three different parts.
* Author:
*    Efrain Gomez Fajardo
* Summary:
*    Each Part is a different class, using the copy constructor to
*    help inherite the GPS's last position, velocity, and angle.
************************************************************************/

#include "orbitalObject.h"
#include "gps.h"
#pragma once

class TestPart;

/************************
* PART GPS CENTER : ORBITAL OBJECT
* This part stays in the same position
* as the original GPS
*************************/
class PartGpsRight : public OrbitalObject
{
   friend TestPart;
public:
   double getRadius() {
      return 8.0;
   }
   PartGpsRight() {}
   PartGpsRight(const GPS& rhs);
   void draw(ogstream& og) { og.drawGPSRight(position, angle.get(), Position(10.0, 10.0)); }
};

/************************
* PART GPS CENTER : ORBITAL OBJECT
* This part is going to be created in a 
* {-10, -10} position relative to the
* original GPS
*************************/
class PartGpsLeft : public OrbitalObject
{
   friend TestPart;
public:
   double getRadius() {
      return 8.0;
   }
   PartGpsLeft() {}
   PartGpsLeft(const GPS& rhs);
   void draw(ogstream& og) { og.drawGPSLeft(position, angle.get(), Position(-10.0, -10.0)); }
};

/************************
* PART GPS CENTER : ORBITAL OBJECT
* This part is going to be created in a
* {+10, +10} position relative to the
* original GPS
*************************/
class PartGpsCenter : public OrbitalObject
{
   friend TestPart;
public:
   double getRadius() {
      return 7.0;
   }
   PartGpsCenter() {}
   PartGpsCenter(const GPS& rhs);
   void draw(ogstream& og) { og.drawGPSCenter(position, angle.get()); }
};