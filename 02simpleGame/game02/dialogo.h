#ifndef DIALOGO_H
#define DIALOGO_H

#include "dialogoak_kargatu.h"
#include "dialogo_grafiko.h"
#include "helpers.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL.h>

#define DIALOGO_MAX_STR_LEN 255
#define DIALOGO_MAX_AUKERAK 4

struct Dialogo
{
	char izena[DIALOGO_MAX_STR_LEN + 1];
	char dialogoa[DIALOGO_MAX_STR_LEN + 1];
	struct Dialogo* aukerak[DIALOGO_MAX_AUKERAK];
	int aukerakKop;
};

struct Dialogo* DIALOGO_sortu(char izena[], char dialogoa[], struct Dialogo* aukerak[], int aukerakKop);
void DIALOGO_ezabatu(struct Dialogo* dialogo);
void DIALOGO_aurrera(struct Dialogo** dialogo, int aukera);
void DIALOGO_gauzatu(struct Dialogo* dialogo, enum Animalia animalia, SDL_Renderer* renderer);
void DIALOGO_main(enum Animalia animalia, SDL_Renderer* renderer);
struct Dialogo* DIALOGO_inizializatu(enum Animalia animalia);

#endif

