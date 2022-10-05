#pragma once

#include "Game.h"

class TextureMgr
{
public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void Draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect dest);;
};