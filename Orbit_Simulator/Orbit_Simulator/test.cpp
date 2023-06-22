/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Marco Varela and Efrain Gomez
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPart.h"
#include "testHandleCollision.h"


 /*****************************************************************
  * TEST RUNNER
  * Runs all the unit tests
  ****************************************************************/
void testRunner()
{
   TestPart().run();
   TestHandleCollision().run();
   
}
