#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "funtzioak.h"
#include "helpers.h"

const char* biomak[NUM_BIOMAK] = {
    "img/ibaia.png",
    "img/iparpoloa.png",
    "img/itsasoa.png",
    "img/basoa.jpg"
};

void ibaia(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState)
{
    int kanpo = 0;
    SDL_Event e;
    atzekoPlanoaAldatu(biomak[0], superficie, lehioa);
    SDL_Rect rectAxolote = { 385, 485, 50, 50 }; //beluga
    SDL_Rect rectManati = { 350, 375, 50, 50 }; //bale urdina

    if (!SELFIE_eginda(ANIMALIA_AXOLOTE) && !SELFIE_eginda(ANIMALIA_AMAZONIAR_MANATI))
    {
        interrogazioakAzaldu(lehioa, rectAxolote, rectManati);
    }
    while (!kanpo)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                kanpo = 1;
            }
        }

        interrogazioeiKlick(lehioa, rectAxolote, rectManati);

        if (SELFIE_eginda(ANIMALIA_AXOLOTE) && SELFIE_eginda(ANIMALIA_AMAZONIAR_MANATI))
        {
            kanpo == 1;
        }

        SDL_Delay(16);
    }
}

void itsasoa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState)
{
    int kanpo = 0;
    SDL_Event e;
    atzekoPlanoaAldatu(biomak[2], superficie, lehioa);
    SDL_Rect rectBeluga = { 100, 250, 50, 50 }; //beluga
    SDL_Rect rectBaleUrdina = { 400, 250, 50, 50 }; //bale urdina

    if(!SELFIE_eginda(ANIMALIA_BELUGA) && !SELFIE_eginda(ANIMALIA_BALE_URDIN))
    {
    interrogazioakAzaldu(lehioa, rectBeluga, rectBaleUrdina);
    }
    while (!kanpo)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                kanpo = 1;
            }
        }

        interrogazioeiKlick(lehioa, rectBeluga, rectBaleUrdina);

        if (SELFIE_eginda(ANIMALIA_BELUGA) && SELFIE_eginda(ANIMALIA_BALE_URDIN))
        {
            kanpo == 1;
        }

        SDL_Delay(16);
    }
}

void basoa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState)
{
    int kanpo = 0;
    SDL_Event e;
    atzekoPlanoaAldatu(biomak[3], superficie, lehioa);

    SDL_Rect rectLemurra = { 100, 500, 50, 50 }; //lemurra
    SDL_Rect rectJaguarra = { 400, 500, 50, 50 }; //jaguarra
    interrogazioakAzaldu(lehioa, rectLemurra, rectJaguarra);

    while (!kanpo)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                kanpo = 1;
            }
        }

        interrogazioeiKlick(lehioa, rectLemurra, rectJaguarra);

        if (SELFIE_eginda(ANIMALIA_LEMUR) && SELFIE_eginda(ANIMALIA_JAGUAR))
        {
            kanpo == 1;
        }

        SDL_Delay(16);
    }
}

void iparPoloa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState)
{
    int kanpo = 0;
    SDL_Event e;
    atzekoPlanoaAldatu(biomak[1], superficie, lehioa);

    SDL_Rect rectHartzTxuria = { 400, 450, 50, 50 }; //hartz txuria
    SDL_Rect rectAzeriArtikoa = { 200, 300, 50, 50 }; //azeri artikoa
    interrogazioakAzaldu(lehioa, rectHartzTxuria, rectAzeriArtikoa);

    while (!kanpo)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                kanpo = 1;
            }
        }

        interrogazioeiKlick(lehioa, rectHartzTxuria, rectAzeriArtikoa);

        if (SELFIE_eginda(ANIMALIA_HARTZ_TXURI) && SELFIE_eginda(ANIMALIA_AZERI_ARTIKO))
        {
            kanpo == 1;
        }

        SDL_Delay(16);
    }
}


void atzekoPlanoaAldatu(const char* imagePath, SDL_Surface* superficie, SDL_Window* lehioa)
{
    int lehiozabalera, lehioaltuera;
    SDL_GetWindowSize(lehioa, &lehiozabalera, &lehioaltuera);

    SDL_Surface* backgroundSurface = irudiaKargatuGainazalera(imagePath);

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

void interrogazioakAzaldu(SDL_Window* lehioa, SDL_Rect rectInterrogazioa1, SDL_Rect rectInterrogazioa2)
{
    SDL_Surface* superficie = SDL_GetWindowSurface(lehioa);

    SDL_Surface* interrogazioa = irudiaKargatuGainazalera("img/animali.png");

    SDL_BlitSurface(interrogazioa, NULL, superficie, &rectInterrogazioa1);
    SDL_BlitSurface(interrogazioa, NULL, superficie, &rectInterrogazioa2);


    SDL_UpdateWindowSurface(lehioa);

    SDL_FreeSurface(interrogazioa);
}

void interrogazioeiKlick(SDL_Window* lehioa, SDL_Rect rectInterrogazioa1, SDL_Rect rectInterrogazioa2)
{
    SDL_Event event;
    int atera = 0;

    while(!atera)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                atera = 1;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                if (SDL_PointInRect(&(SDL_Point) { mouseX, mouseY }, & (rectInterrogazioa1)))
                {
                    if (!SELFIE_eginda(ANIMALIA_AXOLOTE))
                    {
                        if (rectInterrogazioa1.x == 385 && rectInterrogazioa1.y == 485)
                        {
                            axoloteHautatuDa(lehioa);
                            eliminatuInterrogazioa(lehioa, rectInterrogazioa1);
                            atera = 1;
                        }
                    }
                    if (!SELFIE_eginda(ANIMALIA_BELUGA))
                    {
                        if (rectInterrogazioa1.x == 100 && rectInterrogazioa1.y == 250)
                        {
                            belugaHautatuDa(lehioa);
                            eliminatuInterrogazioa(lehioa, rectInterrogazioa1);
                            atera = 1;
                        }
                    }
                    if (!SELFIE_eginda(ANIMALIA_LEMUR))
                    {
                        if (rectInterrogazioa1.x == 100 && rectInterrogazioa1.y == 500)
                        {
                            lemurraHautatuDa(lehioa);
                            eliminatuInterrogazioa(lehioa, rectInterrogazioa1);
                            atera = 1;
                        }
                    }
                    if (!SELFIE_eginda(ANIMALIA_HARTZ_TXURI))
                    {
                        if (rectInterrogazioa1.x == 400 && rectInterrogazioa1.y == 450)
                        {
                            hartzTxuriaHautatuDa(lehioa);
                            eliminatuInterrogazioa(lehioa, rectInterrogazioa1);
                            atera = 1;
                        }
                    }
                }
                else if(SDL_PointInRect(&(SDL_Point) { mouseX, mouseY }, & (rectInterrogazioa2)))
                {
                    if (!SELFIE_eginda(ANIMALIA_AMAZONIAR_MANATI))
                    {
                        if (rectInterrogazioa2.x == 350 && rectInterrogazioa2.y == 375)
                        {
                            manatiaHautatuDa(lehioa);
                            eliminatuInterrogazioa(lehioa, rectInterrogazioa2);
                            atera = 1;
                        }
                    }
                    if (!SELFIE_eginda(ANIMALIA_BALE_URDIN))
                    {
                        if (rectInterrogazioa2.x == 400 && rectInterrogazioa2.y == 250)
                        {
                            baleUrdinaHautatuDa(lehioa);
                            eliminatuInterrogazioa(lehioa, rectInterrogazioa2);
                            atera = 1;
                        }
                    }
                    if (!SELFIE_eginda(ANIMALIA_JAGUAR))
                    {
                        if (rectInterrogazioa2.x == 400 && rectInterrogazioa2.y == 500)
                        {
                            jaguarraHautatuDa(lehioa);
                            eliminatuInterrogazioa(lehioa, rectInterrogazioa2);
                            atera = 1;
                        }
                    }
                    if (!SELFIE_eginda(ANIMALIA_AZERI_ARTIKO))
                    {
                        if (rectInterrogazioa2.x == 200 && rectInterrogazioa2.y == 300)
                        {
                            azeriArtikoaHautatuDa(lehioa);
                            eliminatuInterrogazioa(lehioa, rectInterrogazioa2);
                            atera = 1;
                        }
                    }
                }
            }
        }
    }
}

void axoloteHautatuDa(SDL_Window* lehioa)
{
    animaliaHautatuDa(ANIMALIA_AXOLOTE, lehioa);
}

void belugaHautatuDa(SDL_Window* lehioa)
{
    animaliaHautatuDa(ANIMALIA_BELUGA, lehioa);
}

void manatiaHautatuDa(SDL_Window* lehioa)
{
    animaliaHautatuDa(ANIMALIA_AMAZONIAR_MANATI, lehioa);
}

void baleUrdinaHautatuDa(SDL_Window* lehioa)
{
    animaliaHautatuDa(ANIMALIA_BALE_URDIN, lehioa);
}

void lemurraHautatuDa(SDL_Window* lehioa)
{
    animaliaHautatuDa(ANIMALIA_LEMUR, lehioa);
}

void jaguarraHautatuDa(SDL_Window* lehioa)
{
    animaliaHautatuDa(ANIMALIA_JAGUAR, lehioa);
}

void hartzTxuriaHautatuDa(SDL_Window* lehioa)
{
    animaliaHautatuDa(ANIMALIA_HARTZ_TXURI, lehioa);
}

void azeriArtikoaHautatuDa(SDL_Window* lehioa)
{
    animaliaHautatuDa(ANIMALIA_AZERI_ARTIKO, lehioa);
}

void animaliaHautatuDa(enum Animalia animalia, SDL_Window* lehioa)
{
    DIALOGO_main(animalia, SDL_GetRenderer(lehioa));
}

void eliminatuInterrogazioa(SDL_Window* lehioa, SDL_Rect rectInterrogazioa)
{
    SDL_Surface* superficie = SDL_GetWindowSurface(lehioa);

    // Cargar la imagen que se usará para tapar la interrogación
    SDL_Surface* tapaderaSurface = irudiaKargatuGainazalera("img/tick.png");

    // Combinar la tapadera con la superficie principal usando SDL_BlitSurface
    SDL_BlitSurface(tapaderaSurface, NULL, superficie, &rectInterrogazioa);

    SDL_UpdateWindowSurface(lehioa);

    // Pausar para que puedas ver la eliminación (ajusta según sea necesario)
    SDL_Delay(100);

    SDL_FreeSurface(tapaderaSurface);
}
