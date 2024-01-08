#include "scene_handler.h"
#include <SDL_image.h>
#include <stdio.h>
#include "scene2.h"



void clickeventua(SDL_Event* eventoa, enum Pantaila* ikusi_pantailan) {
    if (eventoa->type == SDL_MOUSEBUTTONDOWN) {
        int xposizioa, yposizioa;
        SDL_GetMouseState(&xposizioa, &yposizioa);
        // erabiltzailearen posizioa zehaztu 

        if (*ikusi_pantailan == PANTAILA1) {
            if (xposizioa >= 225 && xposizioa <= 406 && yposizioa >= 223 && yposizioa <= 300) {
                *ikusi_pantailan = JOKUPANTAILA;
            }
            else if (xposizioa >= 225 && xposizioa <= 406 && yposizioa >= 318 && yposizioa <= 398) {
                *ikusi_pantailan = SCENE3;
            }
            else if (xposizioa >= 225 && xposizioa <= 406 && yposizioa >= 414 && yposizioa <= 491) {
                *ikusi_pantailan = SCENE4;
            }
        }
    }
}

void PantailaBerria(SDL_Window* lehioa, SDL_Surface* superficie, enum Pantaila ikusi_pantaila) {
    SDL_FillRect(superficie, NULL, 0x000000);

    if (ikusi_pantaila == PANTAILA1) {
        SDL_Surface* background = IMG_Load("C:/Users/Oihane/OneDrive/Escritorio/pixil-frame-0.png");
        if (background == NULL) {
            printf("Ezin da backgrounda ikusi: %s\n", IMG_GetError());
            exit(1);
        }

        int lehioZabalera, lehioAtuera;
        SDL_GetWindowSize(lehioa, &lehioZabalera, &lehioAtuera);

        SDL_Rect lehioberria = { 0, 0, lehioZabalera, lehioAtuera };
        SDL_BlitScaled(background, NULL, superficie, &lehioberria);

        SDL_FreeSurface(background); // garbitzeko memoria
    }
    else if (ikusi_pantaila == JOKUPANTAILA) {
        // Llamada a la función scene2() que está en scene2.c
        scene2(lehioa, superficie);
    }
    else if (ikusi_pantaila == SCENE3) {
        SDL_FillRect(superficie, NULL, 0xFF00FF);  // Fondo magenta
    }
    else if (ikusi_pantaila == SCENE4) {
        SDL_FillRect(superficie, NULL, 0x0000FF);  // Fondo azul
    }
}

void PantailaAldaketa(SDL_Window* lehioa, SDL_Surface* superficie) {
    int quit = 0;
    SDL_Event eventoa;
    enum Pantaila ikusi_pantaila = PANTAILA1;

    while (!quit) {
        while (SDL_PollEvent(&eventoa) != 0) {
            if (eventoa.type == SDL_QUIT) {
                quit = 1;
            }
            else {
                clickeventua(&eventoa, &ikusi_pantaila);
            }
        }

        PantailaBerria(lehioa, superficie, ikusi_pantaila);

        SDL_UpdateWindowSurface(lehioa);
    }
    garbitu(lehioa);
}

void garbitu(SDL_Window* lehioa) {
    SDL_DestroyWindow(lehioa);
    SDL_Quit();
}
