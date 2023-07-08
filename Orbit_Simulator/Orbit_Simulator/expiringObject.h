/***********************************************************************
 * Header File:
 *   Expiring Object
 * Author:
 *   Marco Varela & Efrain Gomez 
 * Summary:
 *   All the attributes and methods related to the expiring objects
 *   This class inherits from orbitalObject
 ************************************************************************/

#include "orbitalObject.h"
#pragma once


 /************************
 * EXPIRING OBJECT
 *************************/
class ExpiringObject : public OrbitalObject
{
protected:
   double timePassed;
   double timeExpired;

public:
   // Constructors
   ExpiringObject() : timePassed(0.0), timeExpired(0.0) {}
   ExpiringObject(double timeExpired) : timePassed(0.0), timeExpired(timeExpired) {}

   // Time tracking
   void addTime() { timePassed++; }

   bool isTimeOver() { return timePassed >= timeExpired; }

};