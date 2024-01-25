#include "hasierako_orrialdea.h"


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
void pantaila1(SDL_Window* leihoa, SDL_Surface* superficie) {

    SDL_Surface* background = IMG_Load("img/hasiera.png");
    if (background == NULL) {
        printf("Ezin da backgrounda ikusi: %s\n", IMG_GetError());
        exit(1);
    }

    SDL_Rect lehioberria = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    SDL_BlitScaled(background, NULL, superficie, &lehioberria);




    SDL_FreeSurface(background); // garbitzeko memoria
}

void PantailaBerria(SDL_Window* leihoa, SDL_Surface* superficie, enum Pantaila* ikusi_pantaila)
{
    SDL_FillRect(superficie, NULL, 0x000000);

    if (*ikusi_pantaila == PANTAILA1) {
        pantaila1(leihoa, superficie);
    }
    else if (*ikusi_pantaila == JOKUPANTAILA)
    {
        maparenEszena(leihoa, superficie, ikusi_pantaila);
    }
    else if (*ikusi_pantaila == HELPANTAILA)
    {
        helpantaila(leihoa, superficie, ikusi_pantaila);
    }
    else if (*ikusi_pantaila == EXITPANTAILA)
    {
        SDL_DestroyWindow(leihoa);
        SDL_Quit();
        exit(EXIT_SUCCESS);

    }
}
void helpantaila(SDL_Window* leihoa, SDL_Surface* superficie, enum Pantaila* ikusi_pantaila)
{
    SDL_Surface* backgroundSurface = IMG_Load("img/help.png");

    if (!backgroundSurface) {
        printf("Ezin da atzeko argazkia kargatu (%s): %s\n", "help.png", IMG_GetError());
        return;
    }
    SDL_Surface* flechaSuperficie = flechaArgazkia(leihoa);

    SDL_BlitSurface(backgroundSurface, NULL, superficie, NULL);

    flechaClick(leihoa, superficie, rectFlecha, ikusi_pantaila);
    SDL_BlitScaled(flechaSuperficie, NULL, superficie, &(rectFlecha));

    SDL_FreeSurface(backgroundSurface);
    SDL_FreeSurface(flechaSuperficie);

}

void PantailaAldaketa(SDL_Window* leihoa, SDL_Surface* superficie)
{
    int kanpo = 0;
    SDL_Event eventoa;
    enum Pantaila ikusi_pantaila = PANTAILA1;

    while (!kanpo)
    {
        while (SDL_PollEvent(&eventoa) != 0)
        {
            handleQuitEvent(eventoa);
            clickeventua(&eventoa, &ikusi_pantaila);
        }

        PantailaBerria(leihoa, superficie, &ikusi_pantaila);

        SDL_UpdateWindowSurface(leihoa);
    }

    garbitu(leihoa);
}
void garbitu(SDL_Window* leihoa)
{
    SDL_DestroyWindow(leihoa);
    SDL_Quit();
}
