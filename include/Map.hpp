#pragma once
#include "Game.hpp"
#include <string>

class Map {
private:

public:
	Map();
	~Map();
	static void LoadMap(std::string path, int sizeX, int sizeY);
};