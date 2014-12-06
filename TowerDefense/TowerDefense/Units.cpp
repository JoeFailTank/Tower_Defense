#include "Units.h"

Pathing::Pathing (int nx, int ny, int ncount)
{
	x = nx;
	y = ny;
	count = ncount;
}

Pathing::~Pathing ()
{

}

int UnitBase::Walk ()
{
	vector <Pathing> queue;
	int i = 0;
	queue.push_back (Pathing (X, Y, 0));
	for (i; ;) // Beginning of A* pathfinding algorithm
	{
		if (((X + 1) <= 100))
		{

		}
	}
}

bool UnitBase::CollisionDetect (int nx, int ny)
{
	bool collision = false;

	return collision;
}

FGenUnit::FGenUnit (int nWlkspd, int nDamage, int nAtkspd)
{
	wlkspd = nWlkspd;
	damage = nDamage;
	atkspd = nAtkspd;
}