// init_screen.c
#include "scene_handler.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include "scene2.h"

void Hasieratu(SDL_Window** lehioa, SDL_Surface** superficie) {
    SDL_Init(SDL_INIT_VIDEO);
    // hasieratu bideo sisema
    *lehioa = SDL_CreateWindow("Hasierako pantaila", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
    // lehioa sortu, 600*600
    // definir el puntero aldagaia 
    if (*lehioa == NULL) {
        printf("Lehioa gaizki sortu da: %s\n", SDL_GetError());
        exit(1);
    }
    // lehioa gaizki sortzen bada, errorea printeatu

    *superficie = SDL_GetWindowSurface(*lehioa);
    // superficiea sortzen beti lehioa

    if (TTF_Init() < 0)
    {
        fprintf(stderr, "SDL_tff ez da inizializatu! SDL_Error: %s\n", TTF_GetError());
        exit(1);
    }
}