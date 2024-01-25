#include "init_screen.h"

//leihoa eta render-a hasieratzeko balio duen funtzioa
void Hasieratu(SDL_Window** leihoa, SDL_Surface** superficie)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Error al inicializar SDL: %s\n", SDL_GetError());
        return;
    }
    // hasieratu bideo sisema

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        printf("Error al inicializar SDL_image: %s\n", IMG_GetError());
        SDL_Quit();
        return;
    }
    //hasieratu png sistema

    *leihoa = SDL_CreateWindow("ANIMAL EXTINCTION", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    // leihoa sortu, 600*600 eta puntero aldagaia definitu
    if (*leihoa == NULL)
    {
        printf("leihoa gaizki sortu da: %s\n", SDL_GetError());
        exit(1);
    }
    *superficie = SDL_GetWindowSurface(*leihoa);

    // Gero erabili dezakegu SDL_GetRenderer erabilita.
    SDL_Renderer* renderer = SDL_CreateRenderer(*leihoa, -1, 0);
    if(!renderer)
    {
        fprintf(stderr, "Renderer ez da inizializatu! SDL_Error: %s\n", TTF_GetError());
        exit(1);
    }

    // Testua margotzeko liburutegia inizializatu
    if(TTF_Init() < 0)
    {
        fprintf(stderr, "SDL_tff ez da inizializatu! SDL_Error: %s\n", TTF_GetError());
        exit(1);
    }
}