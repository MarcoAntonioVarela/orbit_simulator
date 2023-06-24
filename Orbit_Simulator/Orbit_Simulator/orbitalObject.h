/***********************************************************************
 * Header File:
 *   Orbital Object
 * Author:
 *   Efrain Gomez & Marco Varela
 * Summary:
 *   All the attributes and methods related to Orbital Object 
 ************************************************************************/

#include "position.h"
#include "velocity.h"
#include "angle.h"
#pragma once

class TestHandleCollision;

class OrbitalObject
{
   friend TestHandleCollision;
protected:

   Position position;
   Velocity velocity;
   Angle angle;

public:
   Position getPosition() const { return position; }
   bool isDead = false;
   void kill() { isDead = true; }
   //virtual void update() = 0;
};
