/***********************************************************************
* Header File:
*    Star: Definition of the Star class
* Author:
*    Efrain Gomez Fajardo
* Summary:
*    Stars are drawn in the background, making the scenary
*    more beautiful.
************************************************************************/
#pragma once
#include "position.h"

class ogstream;
/*********************
* STAR
**********************/
class Star
{
public:
   // Constructors
   Star();
   Star(Position& position);
   Star(const Star& star);
   Star& operator++ (int postfix);

   // Since its only function is to draw
   // this is all we need
   void draw(ogstream& og);
private:
   Position position;
   unsigned char phase;
};