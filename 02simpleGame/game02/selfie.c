#include <SDL.h> // Proporciona funcionalidades básicas de SDL.
#include <SDL_image.h> // Extensión de SDL para cargar imágenes en varios formatos.
#include <stdio.h> // Entrada y salida estándar.
#include <stdbool.h> // Encabezado que proporciona el tipo de datos bool y los valores true y false.
#include "selfie.h"
#include "helpers.h"

SDL_Texture* SELFIE_goikoTexturak[ANIMALIA_KOPURUA];
enum Animalia SELFIE_goikoAnimaliak[ANIMALIA_KOPURUA];
int SELFIE_goikoTexturakKopurua = 0;

SDL_Texture* SELFIE_irudiaKargatu(enum Animalia animalia, SDL_Renderer* renderer)
{
    SDL_Texture* irudia;
    switch (animalia)
    {
    case ANIMALIA_AXOLOTE:
        irudia = irudiaKargatuTexturara(renderer, SELFIE_AXOLOTE_IRUDIA);
        break;
    case ANIMALIA_AMAZONIAR_MANATI:

        irudia = irudiaKargatuTexturara(renderer, SELFIE_AMAZONIAR_MANATI_IRUDIA);
        break;
    case ANIMALIA_BELUGA:
        irudia = irudiaKargatuTexturara(renderer, SELFIE_BELUGA_IRUDIA);
        break;
    case ANIMALIA_BALE_URDIN:
        irudia = irudiaKargatuTexturara(renderer, SELFIE_BALE_URDIN_IRUDIA);
        break;
    case ANIMALIA_HARTZ_TXURI:
        irudia = irudiaKargatuTexturara(renderer, SELFIE_HARTZ_TXURI_IRUDIA);
        break;
    case ANIMALIA_LEMUR:
        irudia = irudiaKargatuTexturara(renderer, SELFIE_LEMUR_IRUDIA);
        break;
    case ANIMALIA_AZERI_ARTIKO:
        irudia = irudiaKargatuTexturara(renderer, SELFIE_AZERI_ARTIKO_IRUDIA);
        break;
    case ANIMALIA_JAGUAR:
        irudia = irudiaKargatuTexturara(renderer, SELFIE_JAGUAR_IRUDIA);
        break;
    default:
        ERRORIF(1, "Animalia ezezaguna. =(");
    }

    return irudia;
}


void SELFIE_goikoSelfieakMarraztu(SDL_Renderer* renderer)
{
    int i;
    SDL_Rect rect;
    int zabalera = WINDOW_WIDTH / 8;
    int altuera = zabalera;

    for (i = 0; i < SELFIE_goikoTexturakKopurua; ++i)
    {
        rect = (SDL_Rect) {i * zabalera, 0, zabalera, altuera};

        SDL_RenderCopy(renderer, SELFIE_goikoTexturak[i], NULL, &rect);
    }
}


int SELFIE_eginda(enum Animalia animalia)
{
    int i = 0;
    int badago = 0;
    while (i < SELFIE_goikoTexturakKopurua && !badago)
    {
        if (SELFIE_goikoAnimaliak[i] == animalia)
        {
            badago = 1;
        }
        ++i;
    }
    return badago;
}


void SELFIE_main(SDL_Renderer* renderer, enum Animalia animalia)
{
    SDL_Texture* texture = SELFIE_irudiaKargatu(animalia, renderer);
    fadeIn(renderer, texture, SELFIE_TIEMPO_MUESTRA);
    SDL_Delay(SELFIE_TIEMPO_MUESTRA);
    if (!SELFIE_eginda(animalia))
    {
        SELFIE_goikoTexturak[SELFIE_goikoTexturakKopurua] = texture;
        SELFIE_goikoAnimaliak[SELFIE_goikoTexturakKopurua] = animalia;
        ++SELFIE_goikoTexturakKopurua;
    }
    handleQuit();
}
