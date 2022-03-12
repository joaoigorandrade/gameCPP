#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "EntityComponentSystem.hpp"
#include "Components.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>

GameObject *player;
GameObject *player2;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());


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
		player = new GameObject("res/gfx/MainCharacter.png", 0, 0);
		player2 = new GameObject("res/gfx/MainCharacter.png", 60, 60);
		map = new Map();
		newPlayer.addComponent<PositionComponent>();
		newPlayer.getComponent<PositionComponent>().setPosition(500,500);
	} else {
		isRunning = false;
	}
}

void Game::handleEvents() {
	SDL_Event event;
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
	player->update();
	player2->update();
	manager.update();
	std::cout << newPlayer.getComponent<PositionComponent>().x() << "," << newPlayer.getComponent<PositionComponent>().y() << std::endl;
}

void Game::render() {
	SDL_RenderClear(Game::renderer);
	map->DrawMap();
	player->render();
	player2->render();
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