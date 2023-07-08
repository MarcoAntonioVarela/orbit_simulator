/***********************************************************************
* Source File:
*   Simulator
* Author:
*   Marco Varela and Efrain Gomez Fajardo
* Summary:
*   Implementation for the Simulator class
************************************************************************/
#include "simulator.h"
#include "uiInteract.h"
#include "gps.h"
#include "sputnik.h"
#include "hubble.h"
#include "dragon.h"
#include "starlink.h"
#include "dreamChaser.h"
using namespace std;


// Temporarly here. Where should it go?
double angleEarth = 0.0;

// Constants, also temporary
const double FRAME_RATE = 30.0;              // frame rate
const double SECONDS_PER_DAY = 86400.0;      // seconds in a day
const double TIME_DILATION = 1440.0;         // time dilation

/***********************************************************************
* HANDLE COLLISION
* When two objects's radius are in contact with each other, a collision
* happens. This method sets that object to be killed, so later it can be
* removed from the list.
************************************************************************/


void Simulator::handleCollision()
{
   for (auto it = orbitalObjects.begin(); it != orbitalObjects.end(); /*Not incremeanting here*/)
   {
      // Check collision between 
      if (computeDistance((*it)->getPosition(), (next(*it))->getPosition()) <= 0.0)
      {
         (*it)->kill();
         (next(*it))->kill();
      }
      else
         ++it;
   }
}

/***********************************************************************
* DESTROY
* When an object is marked as dead, it will be removed from the list
************************************************************************/
void Simulator::destroy()
{
   for (auto it = orbitalObjects.begin(); it != orbitalObjects.end(); /*Not incremeanting here*/)
      if ((*it)->isDead())
      {
         delete *it;
         it = orbitalObjects.erase(it);
      }
      else
         it++;
}

/***********************************************************************
* ADD
* Helper method to easy add element to the list of objects.
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
   og.drawEarth(Position(), angleEarth);
   dreamChaser->draw(og);

   for (auto object : orbitalObjects)
      object->draw(og);
}

/***********************************************************************
* UPDATE
* This function is called on callback. its purpose is to update everything
* that is happening on the simulation
************************************************************************/
void Simulator::update(const Interface*& pUI)
{
   // Updating earth's rotation
   angleEarth -= (((2 * PI) / FRAME_RATE) * (TIME_DILATION / SECONDS_PER_DAY));

   // All the current objects in the simulation
   for (auto object : orbitalObjects)
      object->update();

   // Check if an object needs to be destroyed
   handleCollision();
   destroy();

   // Creating bullets as necessary
   
   // Moving the Dream Chaser
   dreamChaser->move(pUI);
}

/***********************************************************************
* RESET
* This function is called by the non-default constructor. It sets the
* simulator to the first stage where everything should be.
************************************************************************/
void Simulator::reset()
{
   // Initialize the Dream Chaser
   dreamChaser = new DreamChaser(Position(-36515095.13, 21085000.0/*Upper left of the screen*/), Velocity(0.0, -2000.0), Angle());

   //// Creating all the GPS
   GPS* gps1 = new GPS(Position(0.0, 26560000.0),             Velocity(-3880.0, 0.0),       Angle());
   GPS* gps2 = new GPS(Position(23001634.72, 13280000.0),     Velocity(-1940.0, 3360.18),   Angle());
   GPS* gps3 = new GPS(Position(23001634.72, -13280000.0),    Velocity(1940.0,  3360.18),   Angle());
   GPS* gps4 = new GPS(Position(0.0, -26560000.0),            Velocity(3880.0, 0.0),        Angle());
   GPS* gps5 = new GPS(Position(-23001634.72, -13280000.0),   Velocity(1940.0, -3360.18),   Angle());
   GPS* gps6 = new GPS(Position(-23001634.72, 13280000.0),    Velocity(-1940.0, -3360.18),  Angle());

   // Creating Sputnik
   Sputnik* sputnik = new Sputnik(Position(-36515095.13, 21082000.0), Velocity(2050.0, 2684.68), Angle());

   // Creating Hubble
   Hubble* hubble = new Hubble(Position(0.0, -42164000.0), Velocity(3100.0, 0.0), Angle());

   // Creating Crew Dragon
   Dragon* dragon = new Dragon(Position(0.0, 8000000.0), Velocity(-7900.0, 0.0), Angle());

   // Creating Starlink
   Starlink* starlink = new Starlink(Position(0.0, -13020000.0), Velocity(5800.0, 0.0), Angle());

   //// Adding them to the list
   orbitalObjects.push_back(gps1);
   orbitalObjects.push_back(gps2);
   orbitalObjects.push_back(gps3);
   orbitalObjects.push_back(gps4);
   orbitalObjects.push_back(gps5);
   orbitalObjects.push_back(gps6);
   orbitalObjects.push_back(sputnik);
   orbitalObjects.push_back(hubble);
   orbitalObjects.push_back(dragon);
   orbitalObjects.push_back(starlink);

   // Testing with the gps from Lab 07
   #ifdef DEBUG
   GPS* test = new GPS(Position(0.0, 42164000.0), Velocity(-3100.0, 0.0), Angle());
   orbitalObjects.push_back(test);
   #endif
}
