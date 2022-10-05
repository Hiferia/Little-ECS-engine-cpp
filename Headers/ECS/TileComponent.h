#pragma once

#include "ECS.h"
#include "TransformComponent.h"
#include "SDL.h"

class TileComponent : public Component
{
public:
	TransformComponent* transform;
	SpriteComponent* sprite;

	SDL_Rect tileRect;
	int tileID;
	const char* path;

	TileComponent() = default;
	TileComponent(int inX, int inY, int inW, int inH, int inID)
	{
		tileRect.x = inX;
		tileRect.y = inY;
		tileRect.w = inW;
		tileRect.h = inH;
		tileID = inID;

		switch (tileID)
		{
		case 0:
			path = "Assets/water.png";
			break;
		case 1:
			path = "Assets/dirt.png";
			break;
		case 2:
			path = "Assets/grass.png";
			break;
		default:
			break;
		}
	}
	void Init() override
	{
		entity->AddComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, tileRect.w, tileRect.h, 1);
		transform = &entity->GetComponent<TransformComponent>();

		entity->AddComponent<SpriteComponent>(path);
		sprite = &entity->GetComponent<SpriteComponent>();
	}
};