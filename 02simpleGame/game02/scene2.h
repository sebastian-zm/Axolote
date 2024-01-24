#ifndef SCENE2_H
#define SCENE2_H

#include <SDL.h>
#include <SDL_image.h>
#include "biomak_eta_interrogazioak.h"
#include "mugimendua.h"
#include "scene_handler.h"

extern SDL_Rect pertsonaia;
extern SDL_Rect rectFlecha;
extern int bertako_pertsonaia_i;
extern int lehiozabalera;
extern int lehioaltuera;

SDL_Surface* initScene(SDL_Window* lehioa, int* lehiozabalera, int* lehioaltuera);
void MunduAldaketa(SDL_Window* lehioa, SDL_Surface* superficie, SDL_Rect* pertsonaia, int kanpo, const Uint8* keyboardState, enum Pantaila* ikusi_pantaila);
void maparenEszena(SDL_Window* lehioa, SDL_Surface* superficie, enum Pantaila* ikusi_pantailan);
SDL_Surface* flechaArgazkia(SDL_Window* lehioa);
void flechaClickMapa(SDL_Event event, SDL_Window* lehioa, SDL_Surface* superficie, enum Pantaila* ikusi_pantaila);
void flechaClick(SDL_Window* lehioa, SDL_Surface* superficie, int flechaDestX, int flechaDestY, enum Pantaila* ikusi_pantailan);
#endif