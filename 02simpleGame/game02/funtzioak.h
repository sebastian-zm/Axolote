// funtzioak.h
#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

#define NUM_BIOMAK 4

#include <SDL.h>
#include "mugimendua.h"
#include "scene2.h"
#include "dialogo.h"

extern const char* biomak[NUM_BIOMAK];

void atzekoPlanoaAldatu(const char* imagePath, SDL_Surface* superficie, SDL_Window* lehioa);
void ibaia(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState);
void itsasoa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState);
void basoa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState);
void iparPoloa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState);
void interrogazioakAzaldu(SDL_Window* lehioa, SDL_Rect rectInterrogazioa1, SDL_Rect rectInterrogazioa2);
void interrogazioeiKlick(SDL_Window* lehioa, SDL_Rect rectInterrogazioa1, SDL_Rect rectInterrogazioa2);
void eliminatuInterrogazioa(SDL_Window* lehioa, SDL_Rect rectInterrogazioa);
void axoloteHautatuDa(SDL_Window* lehioa);
void belugaHautatuDa(SDL_Window* lehioa);
void baleUrdinaHautatuDa(SDL_Window* lehioa);
void manatiaHautatuDa(SDL_Window* lehioa);
void lemurraHautatuDa(SDL_Window* lehioa);
void jaguarraHautatuDa(SDL_Window* lehioa);
void hartzTxuriaHautatuDa(SDL_Window* lehioa);
void azeriArtikoaHautatuDa(SDL_Window* lehioa);
void animaliaHautatuDa(enum Animalia animalia, SDL_Window* lehioa);


#endif