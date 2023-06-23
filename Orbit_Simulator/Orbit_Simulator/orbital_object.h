#pragma once
class OrbitalObject {
public:
   bool isDead = false;
};

class StubGps5050 : public OrbitalObject {};
class StubBullet5050 : public OrbitalObject {};
class StubBullet50150 : public OrbitalObject {};
class StubBullet15050 : public OrbitalObject {};
class StubBullet150150 : public OrbitalObject {};



