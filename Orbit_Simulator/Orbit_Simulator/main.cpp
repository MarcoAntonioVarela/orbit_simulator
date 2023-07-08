/***********************************************************************
 * Source File:
 *   Simulator
 * Author:
 *   Marco Varela and Efrain Gomez
 * Summary:
 *   Here goes the main function.
 ************************************************************************/

#include <iostream>     // for DEBUGGING
#include "test.h"       // for TEST RUNNER
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW* 
#include "simulator.h"  // For SIMULATOR


 // Constants
const double EARTH_ROTATION_SPEED = 3100.0;      // geo speed
const double FRAME_RATE = 30.0;                  // frame rate
const double SECONDS_PER_DAY = 86400.0;          // seconds in a day
const double TIME_DILATION = 1440.0;             // time dilation

 /*************************************
  * All the interesting work happens here, when
  * I get called back from OpenGL to draw a frame.
  * When I am finished drawing, then the graphics
  * engine will wait until the proper amount of
  * time has passed and put the drawing on the screen.
  **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Simulator* pSimulator = (Simulator*)p;

   // initializing ogstream
   Position pt;
   ogstream gout(pt);

   // this updates the Dream Chaser
   pSimulator->input(pUI);

   // changing everything that is on the screen
   pSimulator->update();

   // draw orbital objects
   pSimulator->draw(gout);

}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   //testRunner();
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Orbital Simulator",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Simulator sim(ptUpperRight);

   // set everything into action
   ui.run(callBack, &sim);

   return 0;
}
