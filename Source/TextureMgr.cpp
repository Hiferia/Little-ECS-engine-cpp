#include "../Headers/TextureMgr.h"

SDL_Texture* TextureMgr::LoadTexture(const char* fileName)
{
	// WE CAN DO IT WITH BOTH SURFACE OR NOT

	//SDL_Surface* tempSurface = IMG_Load("Assets/Knight.png");
	//playerTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	//SDL_FreeSurface(tempSurface);

	SDL_Texture* texture = IMG_LoadTexture(Game::renderer, fileName);
	return texture;
 }

void TextureMgr::Draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, texture, &source, &dest);
}
