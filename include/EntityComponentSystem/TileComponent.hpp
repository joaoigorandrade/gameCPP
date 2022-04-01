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

	TileComponent() = default;
	~TileComponent() { SDL_DestroyTexture(texture); }
	TileComponent(int sourceX, int sourceY, int xPosition, int yPosition, const char* path) {
		texture = TextureManager::LoadTexture(path);
		sourceRectangule.x = sourceX;
		sourceRectangule.y = sourceY;
		sourceRectangule.w = sourceRectangule.h = 32;
		
		destinationRectangule.x = xPosition;
		destinationRectangule.y = yPosition;
		destinationRectangule.w = destinationRectangule.h = 64;

	}

	void draw() override {
		TextureManager::Draw(texture, sourceRectangule, destinationRectangule, SDL_FLIP_NONE);
	}
};