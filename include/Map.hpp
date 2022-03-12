#pragma once
#include "Game.hpp"

class Map {
private:
	SDL_Rect source, destination;

	SDL_Texture* dirty;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];
public:
	Map();
	~Map();
	void LoadMap(int arr[20][25]);
	void DrawMap();
};