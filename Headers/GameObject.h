#pragma once

#include "Game.h"

class GameObject
{
public:
	GameObject(const char* inTexture, int inXPos, int inYPos);
	~GameObject();

	void Update();
	void Render();

private:
	int xPos;
	int yPos;

	SDL_Texture* objTexture;
	SDL_Rect sourceRect, destRect;
};

