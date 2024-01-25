#ifndef BIOMAK_ETA_INTERROGAZIOAK_H
#define BIOMAK_ETA_INTERROGAZIOAK_H

#define NUM_BIOMAK 4

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "helpers.h"
#include "mugimendua.h"
#include "mapa.h"
#include "dialogo.h"
#include "amaiera.h"

extern const char* biomak[NUM_BIOMAK];

void atzekoPlanoaAldatuEtaFletxaAzaldu(const char* imagePath, SDL_Surface* superficie, SDL_Window* leihoa, enum Pantaila* ikusi_pantailan);
void bioma(SDL_Window* leihoa, SDL_Surface* superficie, enum Pantaila* ikusi_pantailan, int bioma, enum Animalia animalia1, enum animalia animalia2);
void ibaia(SDL_Window* leihoa, SDL_Surface* superficie, const Uint8* keyboardState, enum Pantaila* ikusi_pantailan);
void iparPoloa(SDL_Window* leihoa, SDL_Surface* superficie, const Uint8* keyboardState, enum Pantaila* ikusi_pantailan);
void itsasoa(SDL_Window* leihoa, SDL_Surface* superficie, const Uint8* keyboardState, enum Pantaila* ikusi_pantailan);
void basoa(SDL_Window* leihoa, SDL_Surface* superficie, const Uint8* keyboardState, enum Pantaila* ikusi_pantailan);
void interrogazioaAzaldu(SDL_Window* leihoa, enum Animalia animalia);
int interrogazioariKlick(SDL_Window* leihoa, SDL_Event ebentua, enum Animalia animalia);
void animaliaHautatuDa(enum Animalia animalia, SDL_Window* leihoa);
#endif