#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include <iostream>

class Game {
private:
	bool isRunning;
	SDL_Window *window;
	int counter = 0;
public:
	Game();
	~Game();
	void init(const char* title, int xPosition, int yPosition, int width, int height, bool fullScreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();
	static SDL_Event event;
	static SDL_Renderer *renderer;
};