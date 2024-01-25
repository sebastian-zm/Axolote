#ifndef SELFIE_H
#define SELFIE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "selfie.h"
#include "helpers.h"

#define SELFIE_TIEMPO_MUESTRA 2000

#define SELFIE_AXOLOTE_IRUDIA "img/axoloteselfie.png"
#define SELFIE_AMAZONIAR_MANATI_IRUDIA "img/manatiselfie.png"
#define SELFIE_BELUGA_IRUDIA "img/belugaselfie.png"
#define SELFIE_BALE_URDIN_IRUDIA "img/baleaselfie.png"
#define SELFIE_HARTZ_TXURI_IRUDIA "img/hartzaselfie.png"
#define SELFIE_LEMUR_IRUDIA "img/lemurselfie.png"
#define SELFIE_AZERI_ARTIKO_IRUDIA "img/azeriselfie.png"
#define SELFIE_JAGUAR_IRUDIA "img/jaguarselfie.png"

SDL_Texture* SELFIE_irudiaKargatu(enum Animalia animalia, SDL_Renderer* renderer);
void SELFIE_goikoSelfieakMarraztu(SDL_Renderer* renderer);
int SELFIE_eginda(enum Animalia animalia);
void SELFIE_main(SDL_Renderer* renderer, enum Animalia animalia);

#endif


