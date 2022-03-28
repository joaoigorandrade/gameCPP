#pragma once 

#include "TransformComponent.hpp"
#include "TextureManager.hpp"
#include <iostream>
#include "SDL2/SDL.h"

class SpriteComponent: public Component {
private:
	TransformComponent *transform;
	SDL_Texture *texture;
	SDL_Rect sourceRectangule, destinationRectangule;

	bool animated = false;
	int frames = 0;
	int speed = 100;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path) {
		setTexture(path);
	}

	SpriteComponent(const char* path, int nFrames, int nSpeed) {
		animated = true;
		frames = nFrames;
		speed = nSpeed;
		setTexture(path);
	}

	~SpriteComponent() {
		SDL_DestroyTexture(texture);
	}

	void setTexture(const char* path) {
		texture = TextureManager::LoadTexture(path);
	}

	void init() override {
		transform = &entity->getComponent<TransformComponent>();
		sourceRectangule.x = sourceRectangule.y = 0;
		sourceRectangule.w = transform->width;
		sourceRectangule.h = transform->height;
	}

	void update() override {
		if(animated) {
			sourceRectangule.x = sourceRectangule.w * static_cast<int>((SDL_GetTicks()/speed)%frames);
		}
		destinationRectangule.x = (int)transform->position.x;
		destinationRectangule.y = (int)transform->position.y;
		destinationRectangule.w = transform->width * transform->scale;
		destinationRectangule.h = transform->height * transform->scale;
	}

	void draw() override {
		TextureManager::Draw(texture, sourceRectangule, destinationRectangule);
	}
};