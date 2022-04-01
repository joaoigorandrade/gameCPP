#include "Map.hpp"
#include "Game.hpp"
#include <fstream>
#include <iostream>

Map::Map() {
}

Map::~Map() {
}



void Map::LoadMap(std::string path, int sizeX, int sizeY) {
	char c;
	std::fstream mapFile;
	mapFile.open(path);
	int sourceX, sourceY;
	for (int y = 0; y < sizeY; y++) {

		for (int x = 0; x < sizeX; x++) {
			mapFile.get(c);
			sourceY = atoi(&c) * 32;
			mapFile.get(c);
			sourceX = atoi(&c) * 32;
			std::cout << sourceX / 32 << ", " << sourceY / 32 << " ," << x * 32 << " ," << y * 32 << std::endl;
			Game::addTile(sourceX, sourceY, x * 32, y * 32);
			mapFile.ignore();
		}
	}
	mapFile.close();
}