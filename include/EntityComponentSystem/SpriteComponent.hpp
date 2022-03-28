#pragma once 

#include "TransformComponent.hpp"
#include "TextureManager.hpp"
#include "AnimationComponent.hpp"
#include <map>
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
	int animatedIndex = 0;
	std::map<const char*, Animation> animations;

	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

	SpriteComponent() = default;
	SpriteComponent(const char* path) {
		setTexture(path);
	}

	SpriteComponent(const char* path, bool isAnimated) {
		animated = isAnimated;
		Animation idle = Animation(0, 3, 100);
		Animation walk = Animation(1, 8, 100);

		animations.emplace("Idle", idle);
		animations.emplace("Walk", walk);
		
		Play("Idle");
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

		sourceRectangule.y = animatedIndex * transform->height;

		destinationRectangule.x = (int)transform->position.x;
		destinationRectangule.y = (int)transform->position.y;
		destinationRectangule.w = transform->width * transform->scale;
		destinationRectangule.h = transform->height * transform->scale;
	}

	void draw() override {
		TextureManager::Draw(texture, sourceRectangule, destinationRectangule, spriteFlip);
	}

	void Play(const char* animationName) {
		frames = animations[animationName].frames;
		animatedIndex = animations[animationName].index;
		speed = animations[animationName].speed;
	}
};