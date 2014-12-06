#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::vector;
using std::getline;
using std::runtime_error;

class TerrainPos;
class Terrain
{
public:
	Terrain ();
	~Terrain ();
private:
	TerrainPos *MapGrid [100][100];
	TerrainPos *Spawn;
	TerrainPos *Finish;
};

class TerrainPos
{
public:
	TerrainPos ();
	~TerrainPos ();
	void SetFree (bool IsFree);
	void SetPath (bool IsPath);
private:
	bool Free;
	bool Path;
	int X;
	int Y;
};

class Scenery
{
	friend class Terrain;
public:
	virtual bool Collision ();

};