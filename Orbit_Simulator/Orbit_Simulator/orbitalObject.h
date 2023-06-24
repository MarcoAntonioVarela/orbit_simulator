#include "position.h"
#include "velocity.h"
#include "angle.h"
#pragma once
class OrbitalObject 
{
protected:
   Position position;
   Velocity velocity;
   Angle angle;
public:
   bool isDead = false;
   //virtual void update() = 0;
};
