#include "Collision.hpp"
#include "ColliderComponent.hpp"

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

bool Collision::AABB(const ColliderComponent &colliderA, ColliderComponent &colliderB) {
       if (AABB(colliderA.collider, colliderB.collider)) {
              return true;
       } else {
              return false;
       }
}