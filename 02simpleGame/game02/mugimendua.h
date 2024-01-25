#ifndef MUGIMENDUA_H
#define MUGIMENDUA_H

#define NUM_IMAGENES 3
#define NUM_DIRECCIONES 4
#define NUM_IMAGENES_HORIZONTAL 2
#define NUM_IMAGENES_VERTICAL 3

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "helpers.h"

extern const char* imagenes[NUM_DIRECCIONES][NUM_IMAGENES];

void pertsonaiaMugitu(SDL_Window* leihoa, SDL_Surface* superficie, SDL_Rect* pertsonaia, int* bertako_pertsonaia, int* bertako_pertsonaia_i, const Uint8* keyboardState);

#endif