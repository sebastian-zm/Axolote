#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "dialogo.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600


int main(int argc, char * str[]) {

	int animaliak[] = {0, 1};
	int animaliakN = 2;
	int i;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Initialize SDL_ttf
    if (TTF_Init() < 0)
    {
        fprintf(stderr, "SDL_ttf could not initialize! SDL_Error: %s\n", TTF_GetError());
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
    {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        fprintf(stderr, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }


    for (i = 2; i < 8; ++i)
    {
        DIALOGO_main(i, renderer);
    }

    return 0;
}

