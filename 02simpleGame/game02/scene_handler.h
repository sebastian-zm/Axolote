#ifndef SCENE_HANDLER_H
#define SCENE_HANDLER_H
#define NUM_FOTOGRAMAK 6
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "scene2.h"
#include "biomak_eta_interrogazioak.h"

enum Pantaila {
    PANTAILA1,
    JOKUPANTAILA,
    HELPANTAILA,
    EXITPANTAILA
};

void clickeventua(SDL_Event* eventoa, enum Pantaila* ikusi_pantailan);
void pantaila1(SDL_Window* lehioa, SDL_Surface* superficie);
void PantailaBerria(SDL_Window* lehioa, SDL_Surface* superficie, enum Pantaila* ikusi_pantaila);
void helpantaila(SDL_Window* lehioa, SDL_Surface* superficie, enum Pantaila* ikusi_pantaila);
void PantailaAldaketa(SDL_Window* lehioa, SDL_Surface* superficie);
void garbitu(SDL_Window* lehioa);

#endif