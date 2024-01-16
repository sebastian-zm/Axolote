// funtzioak.h
#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

#define NUM_BIOMAK 4

#include <SDL.h>
#include "mugimendua.h"
#include "scene2.h"

extern const char* biomak[NUM_BIOMAK];

void atzekoPlanoaAldatu(const char* imagePath, SDL_Surface* superficie, SDL_Window* lehioa);
void ibaia(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState);
void iparPoloa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState);
void itsasoa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState);
void basoa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState);
void interrogazioakAzaldu(SDL_Window* lehioa, int x1, int y1, int x2, int y2);
void interrogazioeiKlick(SDL_Window* lehioa, SDL_Rect rectInterrogazioa1, SDL_Rect rectInterrogazioa2);

#endif