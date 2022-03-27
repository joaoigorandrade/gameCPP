#include "Map.hpp"
#include "Game.hpp"
#include <fstream>
#include <iostream>

Map::Map() {
}

Map::~Map() {
}

void Map::LoadMap(std::string path, int sizeX, int sizeY) {
	char tile;
	std::fstream mapFile;
	mapFile.open(path);
	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			mapFile.get(tile);
			Game::addTile(atoi(&tile), x * 16, y * 16);
			mapFile.ignore();
		}
		mapFile.ignore();
	}
	mapFile.close();
}