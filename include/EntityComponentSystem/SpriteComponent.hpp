#pragma once 

#include "TransformComponent.hpp"
#include "SDL2/SDL.h"

class SpriteComponent: public Component {
private:
	TransformComponent *transform;
	SDL_Texture *texture;
	SDL_Rect sourceRectangule, destinationRectangule;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path) {
		setTexture(path);
	}
	~SpriteComponent() {}

	void setTexture(const char* path) {
		texture = TextureManager::LoadTexture(path);
	}

	void init() override {
		transform = &entity->getComponent<TransformComponent>();

		sourceRectangule.x = sourceRectangule.y = 0;
		sourceRectangule.w = sourceRectangule.h = 32;
		destinationRectangule.w = destinationRectangule.h = 64;
	}

	void update() override {
		destinationRectangule.x = (int)transform->position.x;
		destinationRectangule.y = (int)transform->position.y;
	}

	void draw() override {
		TextureManager::Draw(texture, sourceRectangule, destinationRectangule);
	}
};