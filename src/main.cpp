#include "main.hpp"

#include <iostream>
#include <random>
#include <functional>

#include "SDL.h"

SDL_Window * window;
SDL_Renderer * renderer;

std::default_random_engine randGenerator;
std::uniform_int_distribution<int> colorDistribution(0, 255);
auto colorGen = std::bind(colorDistribution, randGenerator);

int main(int args, char** argv) {
	if(SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init error: " << SDL_GetError() << std::endl;
		return 1;
	}

	window = SDL_CreateWindow("It works!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	for(int i = 0; i < 0xf; i++)
		render();

	SDL_Quit();

	return 0;
}

void render() {
	SDL_SetRenderDrawColor(renderer, colorGen(), colorGen(), colorGen(), 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
    SDL_Delay(400);
}
