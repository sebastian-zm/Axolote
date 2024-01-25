#include "helpers.h"

// SDL_image erabiliz irudi bat kargatzen da textura batera
SDL_Texture* irudiaKargatuTexturara(SDL_Renderer* renderer, char* path)
{
    SDL_Texture* texture;
    SDL_Surface* surface;

    surface = irudiaKargatuGainazalera(path);
    texture = texturaGainazaletik(renderer, surface);

    SDL_FreeSurface(surface);
    return texture;
}

// SDL_image erabiliz irudi bat kargatzen da gainazal batera
SDL_Surface* irudiaKargatuGainazalera(const char* path)
{
    SDL_Surface* surface;

    char* fullPath = pathAbsolutua(path);

    surface = IMG_Load(fullPath);

    ERRORIF(!surface, "Error al cargar la imagen %s. SDL_image Error: %s\n", fullPath, IMG_GetError());

    free(fullPath);

    return surface;
}

//azalera baten bitartez textura bat sortzen du
SDL_Texture* texturaGainazaletik(SDL_Renderer* renderer, SDL_Surface* surface)
{

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    ERRORIF(!surface, "Error al crear la textura desde la superficie. SDL Error: %s\n", SDL_GetError());

    return texture;
}

//letra mota bat kargatzen duen funtzioa (.ttf path bat behar du)
TTF_Font* letraTipoKargatu(int tamaina, char* path)
{
    TTF_Font* font;

    char* fullPath = pathAbsolutua(path);

    font = TTF_OpenFont(fullPath, tamaina);

    ERRORIF(!font, "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());

    free(fullPath);

    return font;
}

// fitxategi baten testua zabaltzen duen funtzioa
FILE* fitxategiaIrakurtzekoIreki(char* path)
{
    char* fullPath = pathAbsolutua(path);

    FILE* fitxategia = fopen(fullPath, "r");

    ERRORIF(!fitxategia, "Ezin izan da fitxategia irakurri. Path: %s", fullPath);

    free(fullPath);

    return fitxategia;
}

//beltzez pantaila marrazten duen funtzioa
void pantailaGarbitu(SDL_Renderer* renderer)
{
    // Marrazteko kolorea beltzera ezarri
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Pantaila marrazteko koloreakin bete
    SDL_RenderClear(renderer);
}

// "Fade" efektu bat ezartzen du denbora batez
void fadeIn(SDL_Renderer* renderer, SDL_Texture* texture, int tiempo)
{
    int startTime = SDL_GetTicks();
    int currentTime = 0;
    int alpha = 0;

    while (currentTime < tiempo)
    {
        currentTime = SDL_GetTicks() - startTime;
        alpha = (currentTime * 255) / tiempo;
        alpha = (alpha > 255) ? 255 : alpha;

        pantailaGarbitu(renderer);
        SDL_SetTextureAlphaMod(texture, alpha);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, alpha);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, texture, NULL, NULL);

        pantailaEguneratuEstalkiekin(renderer);
    }
}

//path relatibo bat path absolutu baten bihurtzeko funtzioa
char* pathAbsolutua(const char* path)
{
    char* base = SDL_GetBasePath();
    int baseLen = strlen(base);
    int pathLen = strlen(path);

    char* fullPath = malloc(baseLen + pathLen + 1);

    ERRORIF(!fullPath, "Memoria gabe geratu gara. =(");

    memcpy(fullPath, base, baseLen);
    memcpy(fullPath + baseLen, path, pathLen + 1);

    return fullPath;
}

//handleQuit barne doan funtzioa
void handleQuitEvent(SDL_Event e)
{
    if (e.type == SDL_QUIT)
    {
        fprintf(stderr, "Irtetzen SDL_QUIT jaso delako.");
        exit(EXIT_SUCCESS);
        fprintf(stderr, "Fatal Error: exit egin oidoren programa jarraitu da.");
    }
}

//X-ari eman ezgero programa amaitzeko balio duen funtzioa
void handleQuit()
{
    SDL_Event e;

    // Deskartatu aurreko ebentu guztiak, SDL_QUIT ezik.
    while (SDL_PollEvent(&e) != 0)
    {
        handleQuitEvent(e);
    }
}

//Selfie-en miniatura goiko partean marrazteko mezua bidaltzen duen funtzioa
void estalkiakMargotu(SDL_Renderer* renderer)
{
    SELFIE_goikoSelfieakMarraztu(renderer);
}

//Render bat erabiliz pantaila selfie-ekin eguneratzeko balio duen funtzioa
void pantailaEguneratuEstalkiekin(SDL_Renderer* renderer)
{
    estalkiakMargotu(renderer);
    SDL_RenderPresent(renderer);
}

//Window eta surface erabiliz pantaila selfie-ekin eguneratzeko balio duen funtzioa
void pantailaEguneratuEstalkiekinGainazala(SDL_Window* window, SDL_Surface* surface)
{
    SDL_Renderer* renderer = SDL_GetRenderer(window);
    SDL_Texture* texture = texturaGainazaletik(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    estalkiakMargotu(renderer);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture);
}
