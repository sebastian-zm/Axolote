#ifndef DIALOGO_GRAFIKO_H
#define DIALOGO_GRAFIKO_H

#include "dialogo.h"
#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#define DIALOGO_GRAFIKO_AXOLOTE_IRUDIA_AHO_ITXIA "img/axolote1.png"
#define DIALOGO_GRAFIKO_AXOLOTE_IRUDIA_AHO_IREKIA "img/axolote2.png"
#define DIALOGO_GRAFIKO_AMAZONIAR_MANATI_IRUDIA_AHO_ITXIA "img/manati1.png"
#define DIALOGO_GRAFIKO_AMAZONIAR_MANATI_IRUDIA_AHO_IREKIA "img/manati2.png"
#define DIALOGO_GRAFIKO_BELUGA_IRUDIA_AHO_ITXIA "img/beluga1.png"
#define DIALOGO_GRAFIKO_BELUGA_IRUDIA_AHO_IREKIA "img/beluga2.png"
#define DIALOGO_GRAFIKO_BALE_URDIN_IRUDIA_AHO_ITXIA "img/balea1.png"
#define DIALOGO_GRAFIKO_BALE_URDIN_IRUDIA_AHO_IREKIA "img/balea2.png"
#define DIALOGO_GRAFIKO_HARTZ_TXURI_IRUDIA_AHO_ITXIA "img/hartz1.png"
#define DIALOGO_GRAFIKO_HARTZ_TXURI_IRUDIA_AHO_IREKIA "img/hartz2.png"
#define DIALOGO_GRAFIKO_LEMUR_IRUDIA_AHO_ITXIA "img/lemur1.png"
#define DIALOGO_GRAFIKO_LEMUR_IRUDIA_AHO_IREKIA "img/lemur2.png"
#define DIALOGO_GRAFIKO_AZERI_ARTIKO_IRUDIA_AHO_ITXIA "img/azeri1.png"
#define DIALOGO_GRAFIKO_AZERI_ARTIKO_IRUDIA_AHO_IREKIA "img/azeri2.png"
#define DIALOGO_GRAFIKO_JAGUAR_IRUDIA_AHO_ITXIA "img/jaguar1.png"
#define DIALOGO_GRAFIKO_JAGUAR_IRUDIA_AHO_IREKIA "img/jaguar2.png"

#define DIALOGO_GRAFIKO_FONT "font/PublicPixel.ttf"
#define DIALOGO_GRAFIKO_FONT_SIZE 10
#define DIALOGO_GRAFIKO_FONT_COLOR ((SDL_Color) {255, 255, 255, 255})
#define DIALOGO_GRAFIKO_LETRA_DENBORA 35

int DIALOGO_erakutsi(struct Dialogo* dialogo, enum Animalia animalia, SDL_Renderer* renderer);
void DIALOGO_GRAFIKO_animaliaIrudiaKargatu(enum Animalia animalia, SDL_Texture** ahoIrekia, SDL_Texture** ahoItxia, SDL_Renderer* renderer);
void DIALOGO_GRAFIKO_animaliaMargotu(SDL_Renderer* renderer, SDL_Texture* texture);
void DIALOGO_GRAFIKO_dialogoaIdatzi(SDL_Renderer* renderer, int x, int y, int w, TTF_Font* font, char string[]);
void DIALOGO_GRAFIKO_animaliarenDialogoaIdatzi(SDL_Renderer* renderer, TTF_Font* font, char string[]);
void DIALOGO_GRAFIKO_aukerakIdatzi(SDL_Renderer* renderer, TTF_Font* font, char string[]);
void DIALOGO_GRAFIKO_dialogoErakutsi(struct Dialogo* dialogo, SDL_Texture* ahoIrekia, SDL_Texture* ahoItxia, SDL_Renderer* renderer, TTF_Font* font);
void DIALOGO_GRAFIKO_aukerakErakutsi(struct Dialogo* dialogo, SDL_Texture* ahoItxia, SDL_Renderer* renderer, TTF_Font* font);
int DIALOGO_GRAFIKO_itxaronZenbaki(int aukerak);


#endif
