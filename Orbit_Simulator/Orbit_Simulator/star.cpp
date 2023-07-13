/***********************************************************************
* Source File:
*    Star : Implementation of the Orbital Object class
* Author:
*    Efrain Gomez Fajardo
* Summary:
*    Implementation of Star class. Defining constructors and
*    the drawing method
************************************************************************/
#include "star.h"
#include "uiDraw.h"

/*************************************
* DEFAULT CONSTRUCTOR
* Star will start:
* position (0, 0)
* Random phase
*************************************/
Star::Star()
{
   position = Position();
   phase = random(0, 255);
}

/*************************************
* NON-DEFAULT CONSTRUCTOR
* Create a star taking a position
*************************************/
Star::Star(Position& position)
{
   this->position = position;
   phase = random(0, 255);
}

/*************************************
* COPY CONSTRUCTOR
* Used mainly for the implementation
* of the operator++ overload
*************************************/
Star::Star(const Star& star)
{
   position = star.position;
   phase = star.phase;
}

/*************************************
* POSTIX ADDITION OPERATOR
* For changing the phase easily
* outside the class
*************************************/
Star& Star::operator++(int postfix)
{
   Star starRet(*this);
   phase++;
   return starRet;
}

/*************************************
* STAR : DRAW
* Using the graphics interface, 
* draw the star on the screen
*************************************/
void Star::draw(ogstream& og)
{
   og.drawStar(position, phase);
}
