//**********************************************************************
// * Header File:
// *   testHandleCollision
// * Author:
// *   Marco Varela
// * Summary:
// *   All the unit tests for handleCollision
// ************************************************************************/

#include <cassert>
#include <vector>
#include "gps.h"
#include "bullet.h"
#include "simulator.h"
#pragma once

class TestHandleCollision
{
public:
   void run()
   {
      test_scenario1_same_position();
      test_scenario2_samex_samey();
      test_scenario3_samey_differntx();
      test_scenario4_different_position();
   }
private:

   /*****************************************************
   * TESTING Scenario 1: Same position
   *****************************************************/
   void test_scenario1_same_position()
   {
      // Set up
      StubGps5050 stubGps5050;
      StubBullet5050 stubBullet5050;

      Simulator sim;
      sim.orbitalObjects.push_back(&stubGps5050);
      sim.orbitalObjects.push_back(&stubBullet5050);
      //Exercise
      sim.handleCollision();
      //Verify
      assert(stubGps5050.dead == true);
      assert(stubBullet5050.dead == true);
   }

   /*****************************************************
   * TESTING Scenario 2: Same X, different Y
   *****************************************************/
   void test_scenario2_samex_samey()
   {
      // Set up
      StubGps5050 stubGps5050;
      StubBullet50150 stubBullet50150;
      Simulator sim;
      sim.orbitalObjects.push_back(&stubGps5050);
      sim.orbitalObjects.push_back(&stubBullet50150);

      //Exercise
      sim.handleCollision();

      //Verify
      assert(stubGps5050.dead == false);
      assert(stubBullet50150.dead == false);
   }
   /*****************************************************
   * TESTING Scenario 3: Same Y, different X
   *****************************************************/
   void test_scenario3_samey_differntx()
   {
      // Set up
      StubGps5050 stubGps5050;
      StubBullet15050 stubBullet15050;
      Simulator sim;
      sim.orbitalObjects = { &stubGps5050, &stubBullet15050 };;

      //Exercise
      sim.handleCollision();

      //Verify
      assert(stubGps5050.dead == false);
      assert(stubBullet15050.dead == false);
   }
   /*****************************************************
   * TESTING Scenario 4: Different position
   ****************************************************/
   void test_scenario4_different_position()
   {
      // Set up
      StubGps5050 stubGps5050;
      StubBullet150150 stubBullet150150;
      Simulator sim;
      sim.orbitalObjects = { &stubGps5050, &stubBullet150150 };

      //Exercise
      sim.handleCollision();

      //Verify
      assert(stubGps5050.dead == false);
      assert(stubBullet150150.dead == false);
   }

};