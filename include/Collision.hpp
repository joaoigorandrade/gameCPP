#pragma once 
#include <SDL2/SDL.h>

class ColliderComponent;

class Collision {
public:
	static bool AABB(const SDL_Rect& rectanguleA, const SDL_Rect& rectanguleB);
	static bool AABB(const ColliderComponent &colliderA, ColliderComponent &colliderB);
};