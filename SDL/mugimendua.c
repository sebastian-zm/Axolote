#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "mugimendua.h"

int kanpo = 0;
SDL_Rect pertsonaia = { 100, 150, 50, 50 };  // Ajusta los valores según sea necesario
int bertako_pertsonaia = 0;
int bertako_pertsonaia_i = 0;
int lehiozabalera, lehioaltuera;


const char* imagenes[NUM_DIRECCIONES][NUM_IMAGENES] = {
    {"C:/Users/leire/Desktop/program/img/gora1.png", "C:/Users/leire/Desktop/program/img/gora2.png", "C:/Users/leire/Desktop/program/img/gora3.png"},
    {"C:/Users/leire/Desktop/program/img/ezker.png", "C:/Users/leire/Desktop/program/img/ezker_h.png"},
    {"C:/Users/leire/Desktop/program/img/aurrera1.png", "C:/Users/leire/Desktop/program/img/aurrera2.png", "C:/Users/leire/Desktop/program/img/aurrera3.png"},
    {"C:/Users/leire/Desktop/program/img/eskubi.png", "C:/Users/leire/Desktop/program/img/eskubi2.png"}
};

void pertsonaiaMugitu(SDL_Window* lehioa, SDL_Surface* superficie, SDL_Rect* pertsonaia, int* bertako_pertsonaia, int* bertako_pertsonaia_i, int* kanpo, int lehiozabalera, int lehioaltuera, const Uint8* keyboardState)
{
    SDL_PumpEvents();  // Actualiza el estado del teclado

    // Reinicia la dirección cada vez que se suelta una tecla
    if (!keyboardState[SDL_SCANCODE_W] && !keyboardState[SDL_SCANCODE_A] &&
        !keyboardState[SDL_SCANCODE_S] && !keyboardState[SDL_SCANCODE_D]) {
        // *bertako_pertsonaia = 0;
        *bertako_pertsonaia_i = 0;
    }

    if (keyboardState[SDL_SCANCODE_W]) {
        if (pertsonaia->y - 5 >= 0) {
            pertsonaia->y -= 5;
            *bertako_pertsonaia = 0;  // Muestra la imagen de la dirección "arriba"
            *bertako_pertsonaia_i = (*bertako_pertsonaia_i + 1) % NUM_IMAGENES_VERTICAL;

        }
    }
    if (keyboardState[SDL_SCANCODE_A]) {
        if (pertsonaia->x - 5 >= 0) {
            pertsonaia->x -= 5;
            *bertako_pertsonaia = 1;  // Muestra la imagen de la dirección "izquierda"
            *bertako_pertsonaia_i = (*bertako_pertsonaia_i + 1) % NUM_IMAGENES_HORIZONTAL;
        }
    }
    if (keyboardState[SDL_SCANCODE_S]) {
        if (pertsonaia->y + 5 <= lehioaltuera - pertsonaia->h) {
            pertsonaia->y += 5;
            *bertako_pertsonaia = 2;  // Muestra la imagen de la dirección "abajo"
            *bertako_pertsonaia_i = (*bertako_pertsonaia_i + 1) % NUM_IMAGENES_VERTICAL;
        }
    }
    if (keyboardState[SDL_SCANCODE_D]) {
        if (pertsonaia->x + 5 <= lehiozabalera - pertsonaia->w) {
            pertsonaia->x += 5;
            *bertako_pertsonaia = 3;  // Muestra la imagen de la dirección "derecha"
            *bertako_pertsonaia_i = (*bertako_pertsonaia_i + 1) % NUM_IMAGENES_HORIZONTAL;
        }
    }
}

void cleanUp(SDL_Surface* pertsonaia_argazkia[NUM_DIRECCIONES][NUM_IMAGENES], SDL_Surface* backgroundSurface) {
    for (int i = 0; i < NUM_DIRECCIONES; ++i) {
        for (int j = 0; j < (i % 2 ? NUM_IMAGENES_HORIZONTAL : NUM_IMAGENES_VERTICAL); ++j) {
            SDL_FreeSurface(pertsonaia_argazkia[i][j]);
        }
    }
    SDL_FreeSurface(backgroundSurface);
}