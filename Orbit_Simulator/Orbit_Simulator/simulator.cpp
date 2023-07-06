/***********************************************************************
* Source File:
*   Simulator
* Author:
*   Marco Varela and Efrain Gomez Fajardo
* Summary:
*   Implementation for the Simulator class
************************************************************************/
#include "simulator.h"
#include "gps.h"
#include "bullet.h"

/***********************************************************************
* HANDLE COLLISION
* When two objects's radius are in contact with each other, a collision
* happens. This method sets that object to be killed, so later it can be
* removed from the vector.
************************************************************************/
void Simulator::handleCollision()
{
   //for (auto it = orbitalObjects.begin(); it != orbitalObjects.end(); /*Not incremeanting here*/)
   //{
   //   // Implement collision here
   //}
}

/***********************************************************************
* DESTROY
* When an object is marked as dead, it will be removed from the vector
************************************************************************/
void Simulator::destroy()
{
   for (auto it = orbitalObjects.begin(); it != orbitalObjects.end(); /*Not incremeanting here*/)
      if ((*it)->isDead())
      {
         delete* it;
         it = orbitalObjects.erase(it);
      }
      else
         it++;
}

/***********************************************************************
* ADD
* Helper method to easy add element to the vector of objects.
* Every time something needs to be added, it is used here
************************************************************************/
void Simulator::add(OrbitalObject*& object)
{ 
   orbitalObjects.push_back(object);
}

/***********************************************************************
* DRAW
* Everything that must be drawn on the screen is handled here.
* It is constantly being called by callback
************************************************************************/
void Simulator::draw(ogstream& og)
{
   og.drawEarth(Position(), 0.0);

   for (auto object : orbitalObjects)
      object->draw(og);
}

/***********************************************************************
* UPDATE
* This function is called on callback. its purpose is to update everything
* that is happening on the simulation
************************************************************************/
void Simulator::update()
{
   handleCollision();
   destroy();
}

/***********************************************************************
* RESET
* This function is called by the non-default constructor. It sets the
* simulator to the first stage where everything should be.
************************************************************************/
void Simulator::reset()
{
   GPS* gps  = new GPS(Position(0.0, 26560000.0),           Velocity(-3880.0, 0.0),      Angle());
   GPS* gps2 = new GPS(Position(23001634.72, 13280000.0),   Velocity(-1940.0, 3360.18),  Angle());
   GPS* gps3 = new GPS(Position(-23001634.72, -13280000.0), Velocity(1940.0, 3360.18),   Angle());

   orbitalObjects.push_back(gps);
   orbitalObjects.push_back(gps2);
   orbitalObjects.push_back(gps3);
}
