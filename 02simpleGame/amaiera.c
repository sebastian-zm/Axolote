#include "amaiera.h"

//selfie guztiak eginda dauden konprobatzen du eta horren arabera "erreportajeaAzaldu" funtzioari deitzen dio
void amaieraBilatu(SDL_Window* leihoa)
{
    int i = 0;

    while ((i < ANIMALIA_KOPURUA) && (SELFIE_eginda(i) != 0))
    {
        i++;
    }
    if (i == ANIMALIA_KOPURUA)
    {
        erreportajeaAzaldu(leihoa);
    }
}

//Erreportajea pantailan azaltzen duen funtzioa
void erreportajeaAzaldu(SDL_Window* leihoa)
{
    SDL_Surface* superficie = SDL_GetWindowSurface(leihoa);
    SDL_Surface* backgroundSurface = irudiaKargatuGainazalera("img/erreportaia.png");

    if (!backgroundSurface)
    {
        printf("Ezin da RGB azala sortu: %s\n", SDL_GetError());
        SDL_FreeSurface(backgroundSurface);
        return;
    }

    SDL_BlitScaled(backgroundSurface, NULL, superficie, NULL);
    SDL_FreeSurface(backgroundSurface);
    SDL_FreeSurface(superficie);
    SDL_UpdateWindowSurface(leihoa);
    SDL_Delay(3000);
    SDL_DestroyWindow(leihoa);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    exit(EXIT_SUCCESS);
}