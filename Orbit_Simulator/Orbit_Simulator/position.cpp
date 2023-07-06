/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include <cassert>


Position::Position(double x, double y) : x(0.0), y(0.0)
{
   setMetersX(x);
   setMetersY(y);
}

/******************************************
 * POINT : ASSIGNMENT
 * Assign a point
 *****************************************/
Position& Position::operator = (const Position& pt)
{
   x = pt.x;
   y = pt.y;
   return *this;
}

/******************************************
 * POINT : COMPARISON
 * Compare two points
 *****************************************/
bool Position::operator== (const Position& pt)
{
   return (x == pt.x) && (y == pt.y);
}

/******************************************
 * POINT : UPDATE
 * Changing the point components
 *****************************************/
void Position::update(const Velocity& velocity, const Acceleration& acceleration)
{
   x = x + (velocity.getDX() * SECONDS_PER_FRAME) + 0.5 * acceleration.getDDX() * (SECONDS_PER_FRAME * SECONDS_PER_FRAME);
   y = y + (velocity.getDY() * SECONDS_PER_FRAME) + 0.5 * acceleration.getDDY() * (SECONDS_PER_FRAME * SECONDS_PER_FRAME);
}

/******************************************
 * POSITION insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream& operator << (std::ostream& out, const Position& pt)
{
   out << "(" << pt.getMetersX() << "m , " << pt.getMetersY() << "m)";
   return out;
}
   
/*******************************************
* POSITION extraction
*       Prompt for coordinates
******************************************/
std::istream& operator >> (std::istream& in, Position& pt)
{
   double x;
   double y;
   in >> x >> y;

   pt.setMetersX(x);
   pt.setMetersY(y);

   return in;
}
