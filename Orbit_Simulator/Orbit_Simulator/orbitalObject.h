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
#include "uiDraw.h"
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

   // Getters
   Position getPosition() const { return position; }
   Velocity getVelocity() const { return velocity; }
   Angle    getAngle()    const { return angle; }

   // Used when collision happens
   void kill() { dead = true; }
   bool isDead() { return dead; }

   // Virtual methods
   virtual void draw(ogstream & og) = 0;
   virtual void update();
   virtual double getRadius() = 0;


private:
   bool dead = false;
};
