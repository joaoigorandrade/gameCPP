#include "GameObject.hpp"
#include "TextureManager.hpp"
#include "Game.hpp"

GameObject::GameObject(const char* textureSheet, int x, int y) {
	objectTexture = TextureManager::LoadTexture(textureSheet);
	xPosition = x;
	yPosition = y;
}

void GameObject::update() {
	xPosition++;
	yPosition++;
	
	sourceRectangule.h = 64;
	sourceRectangule.w = 64;
	sourceRectangule.x = 0;
	sourceRectangule.y = 0;

	destinationRectangule.x = xPosition;
	destinationRectangule.y = yPosition;
	destinationRectangule.w = sourceRectangule.w;
	destinationRectangule.h = sourceRectangule.h;
}

void GameObject::render() {
	SDL_RenderCopy(Game::renderer, objectTexture, &sourceRectangule, &destinationRectangule);
}