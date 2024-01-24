#include "scene_handler.h"


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
                *ikusi_pantailan = HELPANTAILA;
            }
            else if (xposizioa >= 225 && xposizioa <= 406 && yposizioa >= 414 && yposizioa <= 491) {
                *ikusi_pantailan = EXITPANTAILA;
            }
        }
    }
}
void pantaila1(SDL_Window* lehioa, SDL_Surface* superficie) {

    SDL_Surface* background = IMG_Load("img/hasiera.png");
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
void PantailaBerria(SDL_Window* lehioa, SDL_Surface* superficie, enum Pantaila* ikusi_pantaila)
{
    SDL_FillRect(superficie, NULL, 0x000000);

    if (*ikusi_pantaila == PANTAILA1) {
        pantaila1(lehioa, superficie);
    }
    else if (*ikusi_pantaila == JOKUPANTAILA) {

        // Llamada a la función scene2() que está en scene2.c
        maparenEszena(lehioa, superficie, ikusi_pantaila);


    }
    else if (*ikusi_pantaila == HELPANTAILA)
    {
        helpantaila(lehioa, superficie, ikusi_pantaila);

    }
    else if (*ikusi_pantaila == EXITPANTAILA) {
        SDL_DestroyWindow(lehioa);
        SDL_Quit();

    }
}
void helpantaila(SDL_Window* lehioa, SDL_Surface* superficie, enum Pantaila* ikusi_pantaila)
{
    SDL_Surface* backgroundSurface = IMG_Load("img/help.png");

    if (!backgroundSurface) {
        printf("Ezin da atzeko argazkia kargatu (%s): %s\n", "help.png", IMG_GetError());
        return;
    }
    SDL_Surface* flechaSuperficie = flechaArgazkia(lehioa);

    SDL_BlitSurface(backgroundSurface, NULL, superficie, NULL);

    flechaClick(lehioa, superficie, rectFlecha.x, rectFlecha.y, ikusi_pantaila);
    SDL_BlitScaled(flechaSuperficie, NULL, superficie, &(rectFlecha));

    SDL_FreeSurface(backgroundSurface);
    SDL_FreeSurface(flechaSuperficie);

}
void PantailaAldaketa(SDL_Window* lehioa, SDL_Surface* superficie)
{
    int kanpo = 0;
    SDL_Event eventoa;
    enum Pantaila ikusi_pantaila = PANTAILA1;

    while (!kanpo) {
        while (SDL_PollEvent(&eventoa) != 0) {
            if (eventoa.type == SDL_QUIT) {
                kanpo = 1;
            }
            else {
                clickeventua(&eventoa, &ikusi_pantaila);
            }
        }

        PantailaBerria(lehioa, superficie, &ikusi_pantaila);

        SDL_UpdateWindowSurface(lehioa);
    }
    garbitu(lehioa);
}
void garbitu(SDL_Window* lehioa) {
    SDL_DestroyWindow(lehioa);
    SDL_Quit();
}
