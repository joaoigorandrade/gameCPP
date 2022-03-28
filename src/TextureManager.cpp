#include "TextureManager.hpp"
#include "Game.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* texture) {

	SDL_Surface* templateSurface = IMG_Load(texture);
	SDL_Texture* renderedTexture = SDL_CreateTextureFromSurface(Game::renderer, templateSurface);
	SDL_FreeSurface(templateSurface);

	return renderedTexture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination, SDL_RendererFlip flip) {
	SDL_RenderCopyEx(Game::renderer, texture, &source, &destination, NULL, NULL, flip);
}