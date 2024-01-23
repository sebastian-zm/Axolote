#ifndef MUGIMENDUA_H
#define MUGIMENDUA_H

#define NUM_IMAGENES 3
#define NUM_DIRECCIONES 4
#define NUM_IMAGENES_HORIZONTAL 2
#define NUM_IMAGENES_VERTICAL 3

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>



extern int kanpo;
extern SDL_Rect pertsonaia;
extern int bertako_pertsonaia;
extern int bertako_pertsonaia_i;
extern int lehiozabalera;
extern int lehioaltuera;
extern const char* imagenes[NUM_DIRECCIONES][NUM_IMAGENES];

void cleanUp(SDL_Surface* pertsonaia_argazkia[NUM_DIRECCIONES][NUM_IMAGENES], SDL_Surface* backgroundSurface);
void pertsonaiaMugitu(SDL_Window* lehioa, SDL_Surface* superficie, SDL_Rect* pertsonaia, int* bertako_pertsonaia, int* bertako_pertsonaia_i, int* kanpo, int lehiozabalera, int lehioaltuera, const Uint8* keyboardState);

#endif