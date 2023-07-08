/***********************************************************************
* Source File:
*    Bullet
* Author:
*    Efrain Gomez Fajardo
* Summary:
*    The atttributes and methods related to Bullet.
************************************************************************/
#include "bullet.h"
#include "dreamChaser.h"

Bullet::Bullet(const Position& position, const Velocity& velocity, const Angle& angle, double timePassed)
{
   this->position = position;
   this->velocity = velocity;
   this->angle = angle;
   this->timePassed = timePassed;
}