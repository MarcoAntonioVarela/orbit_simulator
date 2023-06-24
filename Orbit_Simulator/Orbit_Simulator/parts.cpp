/***********************************************************************
* Source File:
*    Parts : Implementation of the different Part classes
* Author:
*    Efrain Gomez Fajardo
* Summary:
*    Each Part is a different class, using the copy constructor to
*    help inherite the GPS's last position, velocity, and angle.
************************************************************************/

#include "parts.h"

/*****************
* Copy constructor
******************/
PartGpsRight::PartGpsRight(const GPS& rhs)
{
   position.setMeters(rhs.getPosition().getMetersX() + 10, rhs.getPosition().getMetersY() + 10);
   velocity = rhs.getVelocity();
   angle = rhs.getAngle();
}

/*****************
* Copy constructor
******************/
PartGpsLeft::PartGpsLeft(const GPS& rhs)
{
   position.setMeters(rhs.getPosition().getMetersX() - 10, rhs.getPosition().getMetersY() - 10);
   velocity = rhs.getVelocity();
   angle = rhs.getAngle();
}

/*****************
* Copy constructor
******************/
PartGpsCenter::PartGpsCenter(const GPS& rhs)
{
   position.setMeters(rhs.getPosition().getMetersX(), rhs.getPosition().getMetersY());
   velocity = rhs.getVelocity();
   angle = rhs.getAngle();
}
