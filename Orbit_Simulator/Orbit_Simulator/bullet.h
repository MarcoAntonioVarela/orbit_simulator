/***********************************************************************
* Header File:
*    Bullet
* Author:
*    Marco Varela
* Summary:
*    The atttributes and methods related to bullet.
************************************************************************/

#include "orbitalObject.h"
#include "position.h"
#include "velocity.h"
#include "angle.h"
#pragma once


/************************
* BULLET : ORBITAL OBJECT
*************************/
class Bullet : protected OrbitalObject
{
   friend class TestPart;
public:
   Position getPosition() const { return position; }
   Velocity getVelocity() const { return velocity; }
   Angle getAngle()       const { return angle; }
};


/*****************************
*  Dummy Bullet from Bullet
******************************/

class DummyBullet : protected Bullet
{
public:
   bool getPosition() const { return false; }
   bool getVelocity() const { return false; }
   bool getAngle()    const { return false; }
};

/*****************************
*  Stub : StubBullet5050
******************************/
class StubBullet5050 : protected DummyBullet
{
   friend TestHandleCollision;
protected:
   Position position = Position(50.0, 50.0);
};


/*****************************
*  Stub : StubBullet50150
******************************/
class StubBullet50150 : protected DummyBullet
{
   friend TestHandleCollision;
protected:
   Position position = Position(50.0, 150.0);
};


/*****************************
*  Stub : StubBullet15050
******************************/
class StubBullet15050 : protected DummyBullet
{
   friend TestHandleCollision;
protected:
   Position position = Position(150.0, 50.0);
};


/*****************************
*  Stub : StubBullet5050
******************************/
class StubBullet150150 : protected DummyBullet
{
   friend TestHandleCollision; 
protected:
   Position position = Position(150.0, 150.0);
};




