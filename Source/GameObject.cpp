#include "../Headers/GameObject.h"
#include "../Headers/TextureMgr.h"


GameObject::GameObject(const char* inTexture, int inXPos, int inYPos)
{
	objTexture = TextureMgr::LoadTexture(inTexture);


	xPos = inXPos;
	yPos = inYPos;

	sourceRect.h = 32;
	sourceRect.w = 32;
	sourceRect.x = 0;
	sourceRect.y = 0;

	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = sourceRect.w * 2;
	destRect.h = sourceRect.h * 2;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &sourceRect, &destRect);
}
