#ifndef BIOMAK_ETA_INTERROGAZIOAK_H
#define BIOMAK_ETA_INTERROGAZIOAK_H

#define NUM_BIOMAK 4

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "helpers.h"
#include "mugimendua.h"
#include "scene2.h"
#include "dialogo.h"

extern const char* biomak[NUM_BIOMAK];

void atzekoPlanoaAldatu(const char* imagePath, SDL_Surface* superficie, SDL_Window* lehioa, enum Pantaila* ikusi_pantailan);
void ibaia(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState, enum Pantaila* ikusi_pantailan);
void iparPoloa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState, enum Pantaila* ikusi_pantailan);
void itsasoa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState, enum Pantaila* ikusi_pantailan);
void basoa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState, enum Pantaila* ikusi_pantailan);
void interrogazioakAzaldu(SDL_Window* lehioa, SDL_Rect rectInterrogazioa1, SDL_Rect rectInterrogazioa2);
void interrogazioeiKlick(SDL_Window* lehioa, SDL_Rect rectInterrogazioa1, SDL_Rect rectInterrogazioa2, SDL_Surface* superficie, int flechaDestX, int flechaDestY, enum Pantaila* ikusi_pantailan);
void eliminatuInterrogazioa(SDL_Window* lehioa, SDL_Rect rectInterrogazioa);
void animaliaHautatuDa(enum Animalia animalia, SDL_Window* lehioa);


#endif