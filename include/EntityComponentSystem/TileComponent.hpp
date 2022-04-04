#pragma once 

#include "EntityComponentSystem.hpp"
#pragma once

#include "EntityComponentSystem.hpp"
#include <SDL2/SDL.h>
#include <iostream>

class TileComponent: public Component {
public: 
	SDL_Texture* texture;
	SDL_Rect sourceRectangule, destinationRectangule;
	Vector2D position;

	TileComponent() = default;
	~TileComponent() { SDL_DestroyTexture(texture); }
	TileComponent(int sourceX, int sourceY, int xPosition, int yPosition, const char* path) {
		texture = TextureManager::LoadTexture(path);
		position.x = xPosition;
		position.y = yPosition;
		sourceRectangule.x = sourceX;
		sourceRectangule.y = sourceY;
		sourceRectangule.w = sourceRectangule.h = 32;
		
		destinationRectangule.x = xPosition;
		destinationRectangule.y = yPosition;
		destinationRectangule.w = destinationRectangule.h = 64;

	}

	void update() override {
		destinationRectangule.x = position.x - Game::camera.x;
		destinationRectangule.y = position.y - Game::camera.y;

	}

	void draw() override {
		TextureManager::Draw(texture, sourceRectangule, destinationRectangule, SDL_FLIP_NONE);
	}
};