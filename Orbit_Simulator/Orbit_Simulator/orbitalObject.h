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
#include <cassert>
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

   // Constructor
   OrbitalObject() : position(Position()), velocity(Velocity()), angle(Angle()) {}
   OrbitalObject(const Position& position, const Velocity& velocity, const Angle& angle) : position(position), velocity(velocity), angle(angle) {}

   Position getPosition() const { return position; }
   void kill() { isDead = true; }
   //virtual void update() = 0;

private:
   bool isDead = false;
};
