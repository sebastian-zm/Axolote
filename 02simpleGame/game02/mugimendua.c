#include "mugimendua.h"

//pertsonaiaren norabide ezberdinen argazkiak gorde
const char* imagenes[NUM_DIRECCIONES][NUM_IMAGENES] = {
    {"img/gora1.png", "img/gora2.png", "img/gora3.png"},
    {"img/ezker.png", "img/ezker_h.png"},
    {"img/aurrera1.png", "img/aurrera2.png", "img/aurrera3.png"},
    {"img/eskubi.png", "img/eskubi2.png"}
};

//A W S D teklen bidez pertsonaiari mugimendua eman
void pertsonaiaMugitu(SDL_Window* leihoa, SDL_Surface* superficie, SDL_Rect* pertsonaia, int* bertako_pertsonaia, int* bertako_pertsonaia_i, const Uint8* keyboardState)
{
    SDL_PumpEvents();

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
        if (pertsonaia->y + 5 <= WINDOW_HEIGHT - pertsonaia->h) {
            pertsonaia->y += 5;
            *bertako_pertsonaia = 2;  // Muestra la imagen de la dirección "abajo"
            *bertako_pertsonaia_i = (*bertako_pertsonaia_i + 1) % NUM_IMAGENES_VERTICAL;
        }
    }
    if (keyboardState[SDL_SCANCODE_D]) {
        if (pertsonaia->x + 5 <= WINDOW_WIDTH - pertsonaia->w) {
            pertsonaia->x += 5;
            *bertako_pertsonaia = 3;  // Muestra la imagen de la dirección "derecha"
            *bertako_pertsonaia_i = (*bertako_pertsonaia_i + 1) % NUM_IMAGENES_HORIZONTAL;
        }
    }
}