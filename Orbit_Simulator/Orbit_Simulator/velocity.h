/***********************************************************************
* Header File:
*    Velocity : Change in position over a determined period of time
* Author:
*    Efrain Gomez Fajardo
* Summary:
*    Every Orbital Object has a velocity,expressed in meters per second
************************************************************************/

#pragma once

class Acceleration;
class TestPart;

/**********************************
* VELOCITY
***********************************/
class Velocity
{
   friend TestPart;
   protected:
      double dx;
      double dy;
   public:
      Velocity() : dx(0.0), dy(0.0) {}
      Velocity(double dx, double dy) : dx(dx), dy(dy) {}
      void update(const Acceleration & acceleration);

      // Getters
      double getDX() const { return dx; }
      double getDY() const { return dy; }
};