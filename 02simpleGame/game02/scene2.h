#ifndef SCENE2_H
#define SCENE2_H

#include <SDL.h>
#include <SDL_image.h>
#include "funtzioak.h"
#include "mugimendua.h"

extern SDL_Rect pertsonaia;
extern int bertako_pertsonaia_i;
extern int lehiozabalera;
extern int lehioaltuera;

SDL_Surface* initScene(SDL_Window* lehioa, int* lehiozabalera, int* lehioaltuera);
void maparenEszena(SDL_Window* lehioa, SDL_Surface* superficie);
void MunduAldaketa(SDL_Window* lehioa, SDL_Surface* superficie, SDL_Rect* pertsonaia, int kanpo, const Uint8* keyboardState);
#endif  // SCENE2_H
