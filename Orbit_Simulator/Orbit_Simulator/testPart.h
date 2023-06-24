/***********************************************************************
* Heaader File:
*    testPart : Unit test for the Part class
* Author:
*    Efrain Gomez Fajardo
* Summary:
*    Testing the Part class
************************************************************************/
#pragma once
#include <cassert>
#include "gps.h"
#include "parts.h"

/*******************************
* TEST Position
* A friend class for Part which contains the Part unit tests
********************************/
class TestPart
{
   public:
      void run()
      {
         test_constructor_gpscenter();
         test_constructor_gpsleft();
         test_constructor_gpsright();
      }
   private:
      // Center GPS will stay in the same position as the
      // full GPS before collision occurred.
      void test_constructor_gpscenter()
      {  // setup
         GPS gps;
         gps.position.x    = 50.0;
         gps.position.y    = 50.0;
         gps.velocity.dx   = 100.0;
         gps.velocity.dy   = 100.0;
         gps.angle.aRadians = 3.1415;
         // exercise
         PartGpsCenter part(gps);
         // verify 
         assert(part.position.x   == 50.0);
         assert(part.position.y   == 50.0);
         assert(part.velocity.dx  == 100.0);
         assert(part.velocity.dy  == 100.0);
         assert(part.angle.aRadians == 3.1415);
      }  // teardown

      // Left GPS will be created in a {-10, -10}
      // position relative to the center
      void test_constructor_gpsleft()
      {  // setup
         GPS gps;
         gps.position.x    =   50.0;
         gps.position.y    =   50.0;
         gps.velocity.dx   =  100.0;
         gps.velocity.dy   =  100.0;
         gps.angle.aRadians = 3.1415;
         // exercise
         PartGpsLeft part(gps);
         // verify 
         assert(part.position.x   == 40.0);
         assert(part.position.y   == 40.0);
         assert(part.velocity.dx  == 100.0);
         assert(part.velocity.dy  == 100.0);
         assert(part.angle.aRadians == 3.1415);
      }  // teardown

      // Right GPS will be created in a {+10, +10}
      // position relative to the center
      void test_constructor_gpsright()
      {  // setup
         GPS gps;
         gps.position.x    = 50.0;
         gps.position.y    = 50.0;
         gps.velocity.dx   = 100.0;
         gps.velocity.dy   = 100.0;
         gps.angle.aRadians = 3.1415;
         // exercise
         PartGpsRight part(gps);
         // verify 
         assert(part.position.x   == 60.0);
         assert(part.position.y   == 60.0);
         assert(part.velocity.dx  == 100.0);
         assert(part.velocity.dy  == 100.0);
         assert(part.angle.aRadians == 3.1415);
      }  // teardown 

};