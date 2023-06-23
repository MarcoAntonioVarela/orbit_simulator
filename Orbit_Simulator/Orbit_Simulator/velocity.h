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

/**********************************
* VELOCITY
***********************************/
class Velocity
{
   friend class TestPart;
   protected:
      int dx;
      int dy;
   public:
      void update(const Acceleration & acceleration);
};