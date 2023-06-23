/***********************************************************************
 * Header File:
 *   testHandleCollision
 * Author:
 *   Marco Varela
 * Summary:
 *   All the unit tests for handleCollision
 ************************************************************************/

#include <cassert>
#include <vector>
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
      std::vector<OrbitalObject*> orbitalObjects = { &stubGps5050, &stubBullet5050 };

      //Exercise
      sim.handleCollision()

      //Verify
      assert(stubGps5050.isDead == true);
      assert(stubBullet5050.isDead == true);
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
      std::vector<OrbitalObject*> orbitalObjects = { &stubGps5050, &stubBullet50150 };

      //Exercise
      sim.handleCollision()

      //Verify
      assert(stubGps5050.isDead == false);
      assert(stubBullet50150.isDead == false);
   }
   /*****************************************************
   * TESTING Scenario 3: Same Y, different X
   *****************************************************/
   void test_scenario3_samey_differntx()
   {
      // Set up
      StubGps5050 stubGps5050;
      StubBullet5050 stubBullet15050;
      Simulator sim;
      std::vector<OrbitalObject*> orbitalObjects = { &stubGps5050, &stubBullet15050 };

      //Exercise
      sim.handleCollision()

         //Verify
      assert(stubGps5050.isDead == false);
      assert(stubBullet15050.isDead == false);
   }
   /*****************************************************
   * TESTING Scenario 4: Different position
   *****************************************************/
   void test_scenario4_different_position()
   {
      // Set up
      StubGps5050 stubGps5050;
      StubBullet5050 stubBullet150150;
      Simulator sim;
      std::vector<OrbitalObject*> orbitalObjects = { &stubGps5050, &stubBullet150150 };

      //Exercise
      sim.handleCollision()

         //Verify
      assert(stubGps5050.isDead == false);
      assert(stubBullet150150.isDead == false);
   }

};