#pragma once
#include <iostream>
#include "Game.hpp"

class GameObject {
public:
	GameObject(const char* textureSheet, int x, int y);
	~GameObject();

	void update();
	void render();

private:
	int xPosition;
	int yPosition;

	SDL_Texture* objectTexture;
	SDL_Rect sourceRectangule, destinationRectangule;
	SDL_Renderer* renderer;
};