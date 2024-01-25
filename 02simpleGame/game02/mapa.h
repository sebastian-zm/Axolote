#ifndef MAPA_H
#define MAPA_H

#include <SDL.h>
#include <SDL_image.h>
#include "biomak_eta_interrogazioak.h"
#include "mugimendua.h"
#include "hasierako_orrialdea.h"
#include "helpers.h"

extern SDL_Rect rectFlecha;

SDL_Surface* initScene(SDL_Window* leihoa);
void MunduAldaketa(SDL_Window* leihoa, SDL_Surface* superficie, SDL_Rect* pertsonaia, const Uint8* keyboardState, enum Pantaila* ikusi_pantaila);
void maparenEszena(SDL_Window* leihoa, SDL_Surface* superficie, enum Pantaila* ikusi_pantailan);
SDL_Surface* flechaArgazkia(SDL_Window* leihoa);
void flechaClickMapa(SDL_Event event, SDL_Window* leihoa, SDL_Surface* superficie, enum Pantaila* ikusi_pantaila);
void flechaClick(SDL_Window* leihoa, SDL_Surface* superficie, SDL_Rect rectFlecha, enum Pantaila* ikusi_pantailan);
#endif