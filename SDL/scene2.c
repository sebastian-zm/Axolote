// scene2.c
#include "scene_handler.h"
#include <SDL_image.h>
#include <stdio.h>

#define ZNBKI_PERTSONAIAK 2  // Define el número de imágenes de personajes
const char* pertsonaiak_arraia[ZNBKI_PERTSONAIAK] = {
    "C:/Users/Oihane/OneDrive/Escritorio/oinez.png",
    "C:/Users/Oihane/OneDrive/Escritorio/oinezx3.png",  
};

void scene2(SDL_Window* lehioa, SDL_Surface* superficie) {
    int currentCharacterIndex = 0;  // Índice de la imagen de personaje actual

    SDL_FillRect(superficie, NULL, 0x000000);
    // SDL_FillRect --> bete kolore batekin superperficiea, gure kasua, superficie
    // NULL--> toda la superficie

    // Cargar la imagen de fondo
    SDL_Surface* background = IMG_Load("C:/Users/Oihane/OneDrive/Escritorio/fondp.jpg");
    if (!background) {
        printf("Ezin da argazkiak kargau %s\n", IMG_GetError());
        return;
    }

    // Obtener el tamaño de la ventana
    int lehiozabalera, lehioaltuera;
    SDL_GetWindowSize(lehioa, &lehiozabalera, &lehioaltuera);

    // Escalar la imagen de fondo al tamaño de la ventana
    SDL_Surface* backgroundSurface = SDL_CreateRGBSurface(0, lehiozabalera, lehioaltuera, 32, 0, 0, 0, 0);
    SDL_BlitScaled(background, NULL, backgroundSurface, NULL);
    SDL_FreeSurface(background);

    // Cargar la imagen del personaje inicial
    SDL_Surface* pertsonaia_argazkia = IMG_Load(pertsonaiak_arraia[currentCharacterIndex]);
    if (!pertsonaia_argazkia) {
        printf("Ezin da argazkiak kargau: %s\n", IMG_GetError());
        SDL_FreeSurface(backgroundSurface);
        return;
    }

    int pertsonai_xpos = 100;  // Coordenada x deseada
    int pertsonai_ypos = 150;  // Coordenada y deseada
    int pertsonai_zabalera = 50; // Ancho deseado
    int pertsonai_altuera = 50;// Altura deseada

    SDL_Rect pertsonaia = { pertsonai_xpos, pertsonai_ypos, pertsonai_zabalera, pertsonai_altuera };


    SDL_Event e;
    int quit = 0;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT){//x-ri ematen badio quit=1 orduan bukleik jun 
                quit = 1;
            }
            else if (e.type == SDL_KEYDOWN) {// ebentua teklatuana bada.
                switch (e.key.keysym.sym) {
                case SDLK_w:// erabiltzaileak w sakatu badu. 
                    if (pertsonaia.y - 10 >= 0) {
                        pertsonaia.y -= 10;
                    }
                    break;
                case SDLK_a:
                    if (pertsonaia.x - 10 >= 0) {
                        pertsonaia.x -= 10;
                    }
                    break;
                case SDLK_s:
                    if (pertsonaia.y + 10 <= lehioaltuera - pertsonaia.h) {
                        pertsonaia.y += 10;
                    }
                    break;
                case SDLK_d:
                    if (pertsonaia.x + 10 <= lehiozabalera - pertsonaia.w) {
                        pertsonaia.x += 10;
                    }
                    break;
                }

                // Cambiar al siguiente personaje cada vez que se presiona una tecla
                currentCharacterIndex = (currentCharacterIndex + 1) % ZNBKI_PERTSONAIAK;

                // Liberar la imagen de personaje actual y cargar la nueva
                SDL_FreeSurface(pertsonaia_argazkia);
                pertsonaia_argazkia = IMG_Load(pertsonaiak_arraia[currentCharacterIndex]);
                if (!pertsonaia_argazkia) {
                    printf("Error al cargar la nueva imagen del personaje! IMG_Error: %s\n", IMG_GetError());
                    SDL_FreeSurface(backgroundSurface);
                    return;
                }
            }
        }

        SDL_FillRect(superficie, NULL, SDL_MapRGB(superficie->format, 0, 0, 0));
        SDL_BlitSurface(backgroundSurface, NULL, superficie, NULL);

        // Blit la imagen del personaje en la nueva posición
        SDL_BlitScaled(pertsonaia_argazkia, NULL, superficie, &pertsonaia);

        SDL_UpdateWindowSurface(lehioa);
    }

    // Liberar recursos
    SDL_FreeSurface(pertsonaia_argazkia);
    SDL_FreeSurface(backgroundSurface);
}
