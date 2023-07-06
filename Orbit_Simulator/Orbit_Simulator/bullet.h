/***********************************************************************
* Header File:
*    Bullet
* Author:
*    Marco Varela
* Summary:
*    The atttributes and methods related to bullet.
************************************************************************/

#include "orbitalObject.h"
#pragma once


/************************
* BULLET : ORBITAL OBJECT
*************************/
class Bullet : public OrbitalObject
{
   friend class TestPart;
public:
   Bullet() : OrbitalObject() {}
   Bullet(const Position& position, const Velocity& velocity, const Angle& angle) : OrbitalObject(position, velocity, angle) {}
   virtual Position getPosition() const { return position; }
   virtual Velocity getVelocity() const { return velocity; }
   virtual Angle    getAngle()    const { return angle; }
   void draw(ogstream& og) 
   {
      og.drawProjectile(position);
   }
};


/*****************************
*  Dummy Bullet from Bullet
******************************/
class DummyBullet : public Bullet
{
public:
   DummyBullet() : Bullet() {}
   Position getPosition() const { assert(false); return Position(); }
   Velocity getVelocity() const { assert(false); return Velocity(); }
   Angle    getAngle()    const { assert(false); return Angle(); }
};

/*****************************
*  Stub : StubBullet5050
******************************/
class StubBullet5050 : public DummyBullet
{
   friend TestHandleCollision;
private:
   void set() { position = Position(50.0, 50.0); }
public:
   StubBullet5050() : DummyBullet() { set(); }
};


/*****************************
*  Stub : StubBullet50150
******************************/
class StubBullet50150 : public DummyBullet
{
   friend TestHandleCollision;
private:
   void set() { position = Position(50.0, 150.0); }
public:
   StubBullet50150() : DummyBullet() { set(); }
};


/*****************************
*  Stub : StubBullet15050
******************************/
class StubBullet15050 : public DummyBullet
{
   friend TestHandleCollision;
private:
   void set() { position = Position(150.0, 50.0); }
public:
   StubBullet15050() : DummyBullet() { set(); }
};
 

/*****************************
*  Stub : StubBullet150150
******************************/
class StubBullet150150 : public DummyBullet
{
   friend TestHandleCollision; 
private:
   void set() { position = Position(150.0, 150.0); }
public:
   StubBullet150150() : DummyBullet() { set(); }
};
