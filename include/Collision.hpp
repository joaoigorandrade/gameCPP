#pragma once 
#include <SDL2/SDL.h>

class Collision {
public:
	static bool AABB(const SDL_Rect& rectanguleA, const SDL_Rect& rectanguleB);
};