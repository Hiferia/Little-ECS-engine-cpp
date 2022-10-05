#pragma once

#include "Components.h"
#include "SDL.h"
#include "../TextureMgr.h"


class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect sourceRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		SetTexture(path);
	}
	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}
	void SetTexture(const char* path)
	{
		texture = TextureMgr::LoadTexture(path);
	}
	void Init() override
	{
		transform = &entity->GetComponent<TransformComponent>();

		sourceRect.x = 0;
		sourceRect.y = 0;
		sourceRect.w = transform->width;
		sourceRect.h = transform->height;
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}
	void Update() override
	{
		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}
	void Draw() override
	{
		TextureMgr::Draw(texture, sourceRect, destRect);
	}
};