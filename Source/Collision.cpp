#include "../Headers/Collision.h"
#include "../Headers/ECS/ColliderComponent.h"
bool Collision::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB)
{
	if (
		rectA.x + rectA.w >= rectB.x &&
		rectB.x + rectB.w >= rectA.x &&
		rectA.y + rectA.h >= rectB.y &&
		rectB.y + rectB.h >= rectA.y
		)
	{
		return true;
	}
	return false;
}

bool Collision::AABB(ColliderComponent& colliderA, ColliderComponent& colliderB)
{
	if (AABB(colliderA.GetCollider(), colliderB.GetCollider()))
	{
		std::cout << colliderA.GetTag() << " hit: " << colliderB.GetTag() << std::endl;
		return true;
	}

	return false;
}
