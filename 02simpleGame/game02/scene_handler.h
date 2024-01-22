// scene_handler.h
#ifndef SCENE_HANDLER_H
#define SCENE_HANDLER_H
#define NUM_FOTOGRAMAK 6
#include <SDL.h>
#include "funtzioak.h"

enum Pantaila {
    PANTAILA1,
    JOKUPANTAILA,
    SCENE3,
    SCENE4
};

void PantailaAldaketa(SDL_Window* lehioa, SDL_Surface* superficie);
void garbitu(SDL_Window* lehioa);
void PantailaBerria(SDL_Window* lehioa, SDL_Surface* superficie, enum Pantaila ikusi_pantaila);
void clickeventua(SDL_Event* eventoa, enum Pantaila* ikusi_pantailan);

#endif