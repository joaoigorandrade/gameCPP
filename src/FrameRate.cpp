#include "FrameRate.hpp"

void FrameRate::limitFrameRate(Uint32 frameStart) {
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	int frameTime = SDL_GetTicks() - frameStart;
	if (frameDelay > frameTime) {
		SDL_Delay(frameDelay - frameTime);
	}
}