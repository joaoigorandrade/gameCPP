#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include "Game.hpp"

class TextureManager {
private:
public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void Draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination, SDL_RendererFlip flip);
};