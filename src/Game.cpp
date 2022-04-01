#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "Components.hpp"
#include "Vector2D.hpp"
#include "Collision.hpp"
#include <SDL2/SDL.h>

Map* map;
Manager manager;

SDL_Event Game::event;
SDL_Renderer* Game::renderer = nullptr;

std::vector <ColliderComponent*> Game::colliders;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());
const char* mapFile = "res/gfx/terrain_ss.png";

enum GroupLabels : std::size_t {
	groupMap,
	groupPlayers,
	groupEnemies,
	groupColliders
};

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

	Map::LoadMap("res/gfx/newMap.map", 25, 20);

	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("res/gfx/animatedEnimie.png", true);
	player.addComponent<KeyBoardController>();
	player.addComponent<ColliderComponent>("player");
	player.addGroup(groupPlayers);
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

	for (auto cc: colliders) {
		Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
	}
}

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));

void Game::render() {
	SDL_RenderClear(Game::renderer);
	for(auto& t : tiles) {
		t->draw();
	}
	for(auto& p : players) {
		p->draw();
	}
	for(auto& e : enemies) {
		e->draw();
	}
	
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

void Game::addTile(int sourceX, int sourceY, int xPosition, int yPosition) {
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(sourceX, sourceY, xPosition, yPosition, mapFile);
	tile.addGroup(groupMap);
}