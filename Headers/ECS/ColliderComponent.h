#pragma once

#include <string>
#include "SDL.h"
#include "Components.h"

class ColliderComponent : public Component
{
	SDL_Rect collider;
	std::string tag;

	TransformComponent* transform;

public:
	SDL_Rect GetCollider()
	{
		return collider;
	}
	std::string GetTag()
	{
		return tag;
	}
	ColliderComponent(std::string inTag)
	{
		tag = inTag;
	}

	void Init() override
	{
		if (!entity->HasComponent<TransformComponent>())
		{
			entity->AddComponent<TransformComponent>();
		}
		transform = &entity->GetComponent<TransformComponent>();

		Game::colliders.push_back(this);


		// if the game will have some mechanics that will modify the transform at run time, we should move this in the update() or create a method.
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}

	void Update() override
	{
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}
};