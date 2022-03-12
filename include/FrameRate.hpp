#pragma once
#include <SDL2/SDL.h>

class FrameRate {
private:
public:
	static void limitFrameRate(Uint32 frameStart);
};