#include "../Headers/Game.h"
#undef main

std::unique_ptr<Game> myGame;

int main(int argc, int* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	myGame = std::make_unique<Game>();
	
	myGame->Init("2DGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	
	while (myGame->Running())
	{
		frameStart = SDL_GetTicks();

		myGame->HandleEvents();
		myGame->Update();
		myGame->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	
	myGame->Clean();
	
	return 0;
}