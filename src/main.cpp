#include <SDL2/SDL.h>
#include <iostream>

#include <Game.hpp>
#include <FrameRate.hpp>

void limitFrameRate(Uint32 frameStart); 

int main(int argc, char* args[]) {

	Game *game = new Game();
	Uint32 frameStart;

	game->init("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	while (game -> running()) {
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		FrameRate::limitFrameRate(frameStart);
	}

	game->clean();
	return 0;
}


