#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "Components.hpp"
#include "Vector2D.hpp"
#include "KeyBoardController.hpp"
#include "Collision.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>

Map* map;
Manager manager;

SDL_Event Game::event;
SDL_Renderer* Game::renderer = nullptr;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int xPosition, int yPosition, int width, int height, bool fullScreen) {
	int flags = 0;

	if (fullScreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialised ..." << std::endl;
		window = SDL_CreateWindow(title, xPosition, yPosition, width, height, flags);
		if (window) {
			std::cout << "Window created" << std::endl;
		}

		Game::renderer = SDL_CreateRenderer(window, -1, 0);
		if (Game::renderer) {
			SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}

		isRunning = true;
	}
	map = new Map();

	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("res/gfx/MainCharacter.png");
	player.addComponent<KeyBoardController>();
	player.addComponent<ColliderComponent>("player");
	
	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.addComponent<SpriteComponent>("res/gfx/dirty.png");
	wall.addComponent<ColliderComponent>("wall");
}

void Game::handleEvents() {
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
		isRunning = false;
		break;
		default:
		break;
	}
}

void Game::update() {
	manager.refresh();
	manager.update();
	if (Collision::AABB(player.getComponent<ColliderComponent>().collider,
		wall.getComponent<ColliderComponent>().collider)) {
	}
}

void Game::render() {
	SDL_RenderClear(Game::renderer);
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(Game::renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Game::renderer);
	SDL_Quit();
	std::cout << "Game is closed" << std::endl;
}

bool Game::running() {
	return isRunning;
}