#pragma once

#include "SDL.h"
#include <stdio.h>
#include <iostream>
#include <memory>
#include "SDL_image.h"
#include <vector>

class ColliderComponent;

class Game
{
public:
	Game();
	~Game();
	
	void Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	void Render();
	void Update();
	void HandleEvents();
	void Clean();
	
	bool Running()
	{
		return isRunning;
	}
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static std::vector<ColliderComponent*> colliders;
private:
	int count = 0;
	bool isRunning;
	SDL_Window* window;
};
