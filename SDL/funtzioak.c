#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "funtzioak.h"

const char* biomak[NUM_BIOMAK] = {
    {"C:/Users/leire/Desktop/program/img/ibaia.png"},
    {"C:/Users/leire/Desktop/program/img/iparpoloa.png"},
    {"C:/Users/leire/Desktop/program/img/itsasoa.png"},
    {"C:/Users/leire/Desktop/program/img/basoa.jpg"}
};

void atzekoPlanoaAldatu(const char* imagePath, SDL_Surface* superficie, SDL_Window* lehioa)
{
    int lehiozabalera, lehioaltuera;
    SDL_GetWindowSize(lehioa, &lehiozabalera, &lehioaltuera);

    SDL_Surface* backgroundSurface = IMG_Load(imagePath);
    if (!backgroundSurface)
    {
        printf("Ezin da atzeko argazkia kargatu (%s): %s\n", imagePath, IMG_GetError());
        return;
    }

    SDL_Surface* scaledBackgroundSurface = SDL_CreateRGBSurface(0, lehiozabalera, lehioaltuera, 32, 0, 0, 0, 0);
    if (!scaledBackgroundSurface)
    {
        printf("Ezin da RGB azala sortu: %s\n", SDL_GetError());
        SDL_FreeSurface(backgroundSurface);
        return;
    }

    SDL_FillRect(scaledBackgroundSurface, NULL, SDL_MapRGBA(scaledBackgroundSurface->format, 0, 0, 0, 0));
    SDL_BlitScaled(backgroundSurface, NULL, scaledBackgroundSurface, NULL);
    SDL_FreeSurface(backgroundSurface);
    SDL_BlitSurface(scaledBackgroundSurface, NULL, superficie, NULL);
    SDL_UpdateWindowSurface(lehioa);
    SDL_FreeSurface(scaledBackgroundSurface);
}

void interrogazioakAzaldu(SDL_Window* lehioa, int x1, int y1, int x2, int y2)
{
    SDL_Surface* superficie = SDL_GetWindowSurface(lehioa);

    SDL_Surface* interrogazioa = IMG_Load("C:/Users/leire/Desktop/program/img/animali.png");

    if (!interrogazioa)
    {
        printf("Ezin da argazkia kargatu : % s\n", IMG_GetError());
        return;
    }

    SDL_Rect rectInterrogazioa1 = { x1, y1, 5, 5 };
    SDL_Rect rectInterrogazioa2 = { x2, y2, 5, 5 };

    SDL_BlitSurface(interrogazioa, NULL, superficie, &rectInterrogazioa1);
    SDL_BlitSurface(interrogazioa, NULL, superficie, &rectInterrogazioa2);


    SDL_UpdateWindowSurface(lehioa);

    SDL_FreeSurface(interrogazioa);

    interrogazioeiKlick(lehioa, rectInterrogazioa1, rectInterrogazioa2);
}

void interrogazioeiKlick(SDL_Window* lehioa, SDL_Rect rectInterrogazioa1, SDL_Rect rectInterrogazioa2)
{
    SDL_Event event;
    int running = 1;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = 0;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                if (SDL_PointInRect(&(SDL_Point) { mouseX, mouseY }, & rectInterrogazioa1))
                {
                    printf("¡Clic en la interrogación 1!\n");
                }
                else if (SDL_PointInRect(&(SDL_Point) { mouseX, mouseY }, & rectInterrogazioa2))
                {
                    printf("¡Clic en la interrogación 2!\n");
                }
            }
        }
    }
}

void ibaia(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState)
{
    int kanpo = 0;
    SDL_Event e;
    atzekoPlanoaAldatu(biomak[0], superficie, lehioa);

    while (!kanpo)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                kanpo = 1;
            }
        }

        interrogazioakAzaldu(lehioa, 325, 450, 350, 350);
        //axolotea x=325 y=450
        //manati amazonikoa x=350 y=350

        SDL_Delay(16);
    }
}

void iparPoloa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState)
{
    int kanpo = 0;
    SDL_Event e;
    atzekoPlanoaAldatu(biomak[1], superficie, lehioa);

    while (!kanpo)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                kanpo = 1;
            }
        }

        interrogazioakAzaldu(lehioa, 400, 450, 200, 300);
        //hartz txuria x=400 y=450
        //azari artikoa x=200 y=300

        SDL_Delay(16);
    }
}

void itsasoa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState)
{
    int kanpo = 0;
    SDL_Event e;
    atzekoPlanoaAldatu(biomak[2], superficie, lehioa);

    while (!kanpo)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                kanpo = 1;
            }
        }

        interrogazioakAzaldu(lehioa, 100, 150, 400, 150);
        //beluga x=100 y=150
        //bale urdina x=400 y=150

        SDL_Delay(16);
    }
}

void basoa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState)
{
    int kanpo = 0;
    SDL_Event e;
    atzekoPlanoaAldatu(biomak[3], superficie, lehioa);

    while (!kanpo)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                kanpo = 1;
            }
        }

        interrogazioakAzaldu(lehioa, 100, 500, 400, 500);
        //lemurra x=100 y=500
        //jaguarra x=400 y=500

        SDL_Delay(16);
    }
}