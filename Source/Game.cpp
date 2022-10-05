#include "../Headers/TextureMgr.h"
#include "../Headers/Game.h"
#include "../Headers/GameObject.h"
#include "../Headers/TileMap.h"
#include "../Headers/ECS/Components.h"
#include "../Headers/ECS/ECS.h"
#include "../Headers/LS_Vector2D.h"
#include "../Headers/Collision.h"

//GameObject* player;
GameObject* enemy;
Map* map;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;

Manager manager;
auto& player(manager.AddEntity());
auto& wall(manager.AddEntity());
auto& tile0(manager.AddEntity());
auto& tile1(manager.AddEntity());
auto& tile2(manager.AddEntity());

Game::Game()
{

}
Game::~Game()
{

}

void Game::Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem initialized" << std::endl;
		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window)
		{
			std::cout << "Window Created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created" << std::endl;
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	
	//player = new GameObject("Assets/Knight.png", 0, 0);
	//enemy = new GameObject("Assets/Wizard.png", 120, 120);
	map = new Map();

	tile0.AddComponent<TileComponent>(200, 200, 32, 32, 0);
	tile1.AddComponent<TileComponent>(250, 250, 32, 32, 1);
	tile1.AddComponent<ColliderComponent>("dirt");
	tile2.AddComponent<TileComponent>(150, 150, 32, 32, 2);
	tile2.AddComponent<ColliderComponent>("grass");


	player.AddComponent<TransformComponent>(2);
	player.AddComponent<SpriteComponent>("Assets/Knight.png");
	player.AddComponent<KeyboardController>();
	player.AddComponent<ColliderComponent>("player");

	wall.AddComponent<TransformComponent>(300.0f, 300.0f, 20, 300, 1);
	wall.AddComponent<SpriteComponent>("Assets/dirt.png");
	wall.AddComponent<ColliderComponent>("wall");
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	//map->DrawMap();
	//player->Render();
	//enemy->Render();
	manager.Draw();
	SDL_RenderPresent(renderer);
}

void Game::Update()
{
	
	//player->Update();
	//enemy->Update();
	manager.Update();

	/*if (Collision::AABB(player.GetComponent<ColliderComponent>().GetCollider(), wall.GetComponent < ColliderComponent>().GetCollider()))
	{
		player.GetComponent<TransformComponent>().velocity * -1;
		std::cout << "Wall HIT!" << std::endl;
	}*/
	for (auto cc : colliders)
	{
		Collision::AABB(player.GetComponent<ColliderComponent>(), *cc);
	}
	
}

void Game::HandleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
	default:
		break;
	}
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


