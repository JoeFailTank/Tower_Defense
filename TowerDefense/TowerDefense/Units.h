#pragma once
#include "Map.h"

class UnitBase
{
	friend class Terrain;
public:
	virtual int Walk ();
	virtual bool CollisionDetect (int nx, int ny);
protected:
	int health;
	int wlkspd;
	int damage;
	int atkspd;
	int X;
	int Y;
};

class Pathing
{
public:
	Pathing (int nx, int ny, int ncount);
	~Pathing ();
private:
	int x;
	int y;
	int count;
};

class FGenUnit : public UnitBase
{
public:
	FGenUnit (int nWlkspd, int nDamage, int nAtkspd);
	~FGenUnit ();

private:

};