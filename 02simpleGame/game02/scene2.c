#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "scene2.h"

SDL_Surface* initScene(SDL_Window* lehioa, int* lehiozabalera, int* lehioaltuera) {

    SDL_GetWindowSize(lehioa, lehiozabalera, lehioaltuera);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Error al inicializar SDL: %s\n", SDL_GetError());
        return;
    }

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        printf("Error al inicializar SDL_image: %s\n", IMG_GetError());
        SDL_Quit();
        return;
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {

        printf("Error al inicializar SDL: %s\n", SDL_GetError());
        return;
    }

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        printf("Error al inicializar SDL_image: %s\n", IMG_GetError());
        SDL_Quit();
        return;
    }

    SDL_Surface* backgroundSurface = irudiaKargatuGainazalera("img/mapa.png");
    if (!backgroundSurface) {
        printf("Ezin da atzeko argazkia kargatu: %s\n", IMG_GetError());
        return NULL;
    }

    SDL_Surface* scaledBackgroundSurface = SDL_CreateRGBSurface(0, *lehiozabalera, *lehioaltuera, 32, 0, 0, 0, 0);
    SDL_FillRect(scaledBackgroundSurface, NULL, SDL_MapRGBA(scaledBackgroundSurface->format, 0, 0, 0, 0));
    SDL_BlitScaled(backgroundSurface, NULL, scaledBackgroundSurface, NULL);
    SDL_FreeSurface(backgroundSurface);

    return scaledBackgroundSurface;
}

void MunduAldaketa(SDL_Window* lehioa, SDL_Surface* superficie, SDL_Rect* pertsonaia, int kanpo, const Uint8* keyboardState)
{
    if (pertsonaia->x >= 100 && pertsonaia->x <= 385 && pertsonaia->y >= 0 && pertsonaia->y <= 50)
    {
        iparPoloa(lehioa, superficie, keyboardState);
        kanpo = 1;
    }
    else if (pertsonaia->x >= -1 && pertsonaia->x <= 20 && pertsonaia->y <= 355 && pertsonaia->y >= 150)
    {
        ibaia(lehioa, superficie, keyboardState);
        kanpo = 1;
    }
    else if (pertsonaia->x >= 500 && pertsonaia->x <= 600 && pertsonaia->y >= 155 && pertsonaia->y <= 390)
    {
        itsasoa(lehioa, superficie, keyboardState);
        kanpo = 1;
    }
    else if (pertsonaia->x >= 100 && pertsonaia->x <= 385 && pertsonaia->y >= 400 && pertsonaia->y <= 500)
    {
        basoa(lehioa, superficie, keyboardState);
        kanpo = 1;
    }
}

    void maparenEszena(SDL_Window * lehioa, SDL_Surface * superficie)
    {
        int i, j;
        const Uint8* keyboardState = SDL_GetKeyboardState(NULL);

        SDL_Surface* backgroundSuperficie = initScene(lehioa, &lehiozabalera, &lehioaltuera);

        if (!backgroundSuperficie)
        {
            return;
        }

        SDL_Surface* pertsonaia_argazkia[NUM_DIRECCIONES][NUM_IMAGENES];
        for (i = 0; i < NUM_DIRECCIONES; ++i)
        {
            for (j = 0; j < (i % 2 ? NUM_IMAGENES_HORIZONTAL : NUM_IMAGENES_VERTICAL); ++j)
            {
                printf("Cargando imagen: %s\n", imagenes[i][j]);
                pertsonaia_argazkia[i][j] = irudiaKargatuGainazalera(imagenes[i][j]);
                if (!pertsonaia_argazkia[i][j])
                {
                    printf("Error al cargar la imagen: %s\n", IMG_GetError());
                    cleanUp(pertsonaia_argazkia, backgroundSuperficie);
                    return;
                }
            }
        }

        while (!kanpo)
        {
            pertsonaiaMugitu(lehioa, superficie, &pertsonaia, &bertako_pertsonaia, &bertako_pertsonaia_i, &kanpo, lehiozabalera, lehioaltuera, keyboardState);
            MunduAldaketa(lehioa, superficie, &pertsonaia, kanpo, keyboardState);

            SDL_BlitSurface(backgroundSuperficie, NULL, superficie, NULL);
            SDL_BlitSurface(pertsonaia_argazkia[bertako_pertsonaia][bertako_pertsonaia_i], NULL, superficie, &pertsonaia);

            if (kanpo)
            {
                cleanUp(pertsonaia_argazkia, backgroundSuperficie);
                break;  // Salir del bucle cuando kanpo es igual a 1
            }

            SDL_UpdateWindowSurface(lehioa);
            SDL_Delay(130);
        }
    }