#pragma once 

#include "EntityComponentSystem.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include <SDL2/SDL.h>
#include <iostream>

class TileComponent: public Component {
public: 
	TransformComponent* transform;
	SpriteComponent* sprite;

	SDL_Rect tileRectangule;
	int tileID;
	const char* path;

	TileComponent() = default;

	TileComponent(int x, int y, int w, int h, int id) {
		tileRectangule.x = x;
		tileRectangule.y = y;
		tileRectangule.w = w;
		tileRectangule.h = h;
		tileID = id;
		
		switch (tileID) {
			case 0:
			path = "res/gfx/dirty.png";
			break;
			case 1:
			path = "res/gfx/water.png";
			break;
			case 2:
			path = "res/gfx/grass.png";
			break;
			default:
			break;
		}
	}

	void init() override {
		entity->addComponent<TransformComponent>((float)tileRectangule.x, (float)tileRectangule.y, tileRectangule.w, tileRectangule.h, 1);
		transform = &entity->getComponent<TransformComponent>();

		entity->addComponent<SpriteComponent>(path);
		sprite = &entity->getComponent<SpriteComponent>();
	}

};