#include "init_screen.h"

void Hasieratu(SDL_Window** lehioa, SDL_Surface** superficie) {
    SDL_Init(SDL_INIT_VIDEO);
    // hasieratu bideo sisema
    *lehioa = SDL_CreateWindow("Hasierako pantaila", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
    // lehioa sortu, 600*600 eta puntero aldagaia definitu
    if (*lehioa == NULL) {
        printf("Lehioa gaizki sortu da: %s\n", SDL_GetError());
        exit(1);
    }
    *superficie = SDL_GetWindowSurface(*lehioa);

    // Gero erabili dezakegu SDL_GetRenderer erabilita.
    SDL_Renderer* renderer = SDL_CreateRenderer(*lehioa, -1, 0);
    if (!renderer)
    {
        fprintf(stderr, "Renderer ez da inizializatu! SDL_Error: %s\n", TTF_GetError());
        exit(1);
    }

    // Testua margotzeko liburutegia inizializatu
    if (TTF_Init() < 0)
    {
        fprintf(stderr, "SDL_tff ez da inizializatu! SDL_Error: %s\n", TTF_GetError());
        exit(1);
    }
}