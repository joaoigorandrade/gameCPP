#include "Collision.hpp"

 bool Collision::AABB(const SDL_Rect& rectanguleA, const SDL_Rect& rectanguleB) {
 	if (rectanguleA.x + rectanguleA.w >= rectanguleB.x &&
 		rectanguleA.y + rectanguleA.h >= rectanguleB.y &&
 		rectanguleB.x + rectanguleB.w >= rectanguleA.x &&
 		rectanguleB.y + rectanguleB.h >= rectanguleA.y) {
 		return true;
 	} else {
        return false;
    }
 }