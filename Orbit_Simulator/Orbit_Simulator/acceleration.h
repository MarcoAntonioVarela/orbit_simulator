/***********************************************************************
* Header File:
*    Acceleration : Implementation of the Acceleration class
* Author:
*    Efrain Gomez Fajardo
* Summary:
*    Change in Velocity in every frame
************************************************************************/
#pragma once
#include <iostream>

class Angle;
/**************
* ACCELERATION
***************/
class Acceleration
{
   protected:
      double ddx;
      double ddy;
   public:
      Acceleration() : ddx(0.0), ddy(0.0) {}
      Acceleration(Angle& angle, double acceleration);

      // Getters
      double getDDX() const { return ddx; }
      double getDDY() const { return ddy; }
      
      // Setters
      void setDDX(double ddx) { this->ddx = ddx; }
      void setDDY(double ddy) { this->ddy = ddy; }
};

// stream I/O useful for debugging
std::ostream& operator << (std::ostream& out, const Acceleration& a);
std::istream& operator >> (std::istream& in, Acceleration& a);