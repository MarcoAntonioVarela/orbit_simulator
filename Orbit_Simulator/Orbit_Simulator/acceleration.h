/***********************************************************************
* Header File:
*    Acceleration : Implementation of the Acceleration class
* Author:
*    Efrain Gomez Fajardo
* Summary:
*    Change in Velocity in every frame
************************************************************************/
#pragma once


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
      double getDDX() const { return ddx; }
      double getDDY() const { return ddy; }
      void update(const Angle& angle, double acceleration);
};