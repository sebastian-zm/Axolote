#include "dialogo_grafiko.h"

int DIALOGO_erakutsi(struct Dialogo* dialogo, enum Animalia animalia, SDL_Renderer* renderer)
{
    int aukera;
    SDL_Texture* ahoIrekia;
    SDL_Texture* ahoItxia;
    TTF_Font* font;

    DIALOGO_GRAFIKO_animaliaIrudiaKargatu(animalia, &ahoIrekia, &ahoItxia, renderer);
    font = letraTipoKargatu(DIALOGO_GRAFIKO_FONT_SIZE, DIALOGO_GRAFIKO_FONT);

    DIALOGO_GRAFIKO_dialogoErakutsi(dialogo, ahoIrekia, ahoItxia, renderer, font);
    SDL_DestroyTexture(ahoIrekia);
    DIALOGO_GRAFIKO_aukerakErakutsi(dialogo, ahoItxia, renderer, font);
    SDL_DestroyTexture(ahoItxia);
    DIALOGO_GRAFIKO_dialogoaIdatzi(renderer, 40, 540, 500, font, "Sakatu zenbaki bat zure dialogoa hautatzeko.");
    pantailaEguneratuEstalkiekin(renderer);
    aukera = DIALOGO_GRAFIKO_itxaronZenbaki(dialogo->aukerakKop) - 1;
    return aukera;
}

void DIALOGO_GRAFIKO_animaliaIrudiaKargatu(enum Animalia animalia, SDL_Texture** ahoIrekia, SDL_Texture** ahoItxia, SDL_Renderer* renderer)
{
    switch (animalia)
    {
    case ANIMALIA_AXOLOTE:
        *ahoIrekia = irudiaKargatuTexturara(renderer, DIALOGO_GRAFIKO_AXOLOTE_IRUDIA_AHO_IREKIA);
        *ahoItxia = irudiaKargatuTexturara(renderer, DIALOGO_GRAFIKO_AXOLOTE_IRUDIA_AHO_ITXIA);
        break;
    case ANIMALIA_AMAZONIAR_MANATI:
        *ahoIrekia = irudiaKargatuTexturara(renderer, DIALOGO_GRAFIKO_AMAZONIAR_MANATI_IRUDIA_AHO_IREKIA);
        *ahoItxia = irudiaKargatuTexturara(renderer, DIALOGO_GRAFIKO_AMAZONIAR_MANATI_IRUDIA_AHO_ITXIA);
        break;
    case ANIMALIA_BELUGA:
        *ahoIrekia = irudiaKargatuTexturara(renderer, DIALOGO_GRAFIKO_BELUGA_IRUDIA_AHO_IREKIA);
        *ahoItxia = irudiaKargatuTexturara(renderer, DIALOGO_GRAFIKO_BELUGA_IRUDIA_AHO_ITXIA);
        break;
    case ANIMALIA_BALE_URDIN:
        *ahoIrekia = irudiaKargatuTexturara(renderer, DIALOGO_GRAFIKO_BALE_URDIN_IRUDIA_AHO_IREKIA);
        *ahoItxia = irudiaKargatuTexturara(renderer, DIALOGO_GRAFIKO_BALE_URDIN_IRUDIA_AHO_ITXIA);
        break;
    case ANIMALIA_HARTZ_TXURI:
        *ahoIrekia = irudiaKargatuTexturara(renderer, DIALOGO_GRAFIKO_HARTZ_TXURI_IRUDIA_AHO_IREKIA);
        *ahoItxia = irudiaKargatuTexturara(renderer, DIALOGO_GRAFIKO_HARTZ_TXURI_IRUDIA_AHO_ITXIA);
        break;
    case ANIMALIA_LEMUR:
        *ahoIrekia = irudiaKargatuTexturara(renderer, DIALOGO_GRAFIKO_LEMUR_IRUDIA_AHO_IREKIA);
        *ahoItxia = irudiaKargatuTexturara(renderer, DIALOGO_GRAFIKO_LEMUR_IRUDIA_AHO_ITXIA);
        break;
    case ANIMALIA_AZERI_ARTIKO:
        *ahoIrekia = irudiaKargatuTexturara(renderer, DIALOGO_GRAFIKO_AZERI_ARTIKO_IRUDIA_AHO_IREKIA);
        *ahoItxia = irudiaKargatuTexturara(renderer, DIALOGO_GRAFIKO_AZERI_ARTIKO_IRUDIA_AHO_ITXIA);
        break;
    case ANIMALIA_JAGUAR:
        *ahoIrekia = irudiaKargatuTexturara(renderer, DIALOGO_GRAFIKO_JAGUAR_IRUDIA_AHO_IREKIA);
        *ahoItxia = irudiaKargatuTexturara(renderer, DIALOGO_GRAFIKO_JAGUAR_IRUDIA_AHO_ITXIA);
        break;
    default:
        ERRORIF(1, "Animalia ezezaguna. =(");
    }
}

void DIALOGO_GRAFIKO_animaliaMargotu(SDL_Renderer* renderer, SDL_Texture* texture)
{
    SDL_Rect rect = { 300, 75, 300, 300 };
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void DIALOGO_GRAFIKO_dialogoaIdatzi(SDL_Renderer* renderer, int x, int y, int w, TTF_Font* font, char string[])
{

    SDL_Surface* textSurface = TTF_RenderUTF8_Blended_Wrapped(font, string, DIALOGO_GRAFIKO_FONT_COLOR, w);
    SDL_Rect rect = { x, y, textSurface->w, textSurface->h };


    SDL_Texture* texture;

    ERRORIF(!textSurface, "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());

    texture = texturaGainazaletik(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
}

void DIALOGO_GRAFIKO_animaliarenDialogoaIdatzi(SDL_Renderer* renderer, TTF_Font* font, char string[])
{
    DIALOGO_GRAFIKO_dialogoaIdatzi(renderer, 40, 100, 220, font, string);
}

void DIALOGO_GRAFIKO_aukerakIdatzi(SDL_Renderer* renderer, TTF_Font* font, char string[])
{
    DIALOGO_GRAFIKO_dialogoaIdatzi(renderer, 40, 400, 520, font, string);
}


void DIALOGO_GRAFIKO_dialogoErakutsi(struct Dialogo* dialogo, SDL_Texture* ahoIrekia, SDL_Texture* ahoItxia, SDL_Renderer* renderer, TTF_Font* font)
{
    int i, stringLength;
    char partialString[DIALOGO_MAX_STR_LEN + 1];

    stringLength = strlen(dialogo->dialogoa);
    memset(partialString, 0, sizeof(partialString));

    for (i = 0; i <= stringLength; ++i)
    {
        partialString[i] = dialogo->dialogoa[i];

        pantailaGarbitu(renderer);
        if ((stringLength - i) % 4 < 2) DIALOGO_GRAFIKO_animaliaMargotu(renderer, ahoItxia);
        else DIALOGO_GRAFIKO_animaliaMargotu(renderer, ahoIrekia);
        DIALOGO_GRAFIKO_animaliarenDialogoaIdatzi(renderer, font, partialString);
        pantailaEguneratuEstalkiekin(renderer);
        SDL_Delay(DIALOGO_GRAFIKO_LETRA_DENBORA);
        handleQuit();
    }
}


void DIALOGO_GRAFIKO_aukerakErakutsi(struct Dialogo* dialogo, SDL_Texture* ahoItxia, SDL_Renderer* renderer, TTF_Font* font)
{
    char aukerak[(DIALOGO_MAX_STR_LEN + 4) * DIALOGO_MAX_AUKERAK + 1] = "";
    char partialString[sizeof(aukerak)];
    int i, stringLength = 0;

    font = letraTipoKargatu(DIALOGO_GRAFIKO_FONT_SIZE, DIALOGO_GRAFIKO_FONT);

    for (i = 0; i < dialogo->aukerakKop; ++i)
    {
        stringLength += snprintf(aukerak + stringLength, sizeof(aukerak) - stringLength, "%d. %s\n", i + 1, dialogo->aukerak[i]->izena);
    }

    memset(partialString, 0, sizeof(partialString));

    for (i = 0; i <= stringLength; ++i)
    {
        partialString[i] = aukerak[i];

        pantailaGarbitu(renderer);
        DIALOGO_GRAFIKO_animaliaMargotu(renderer, ahoItxia);
        DIALOGO_GRAFIKO_animaliarenDialogoaIdatzi(renderer, font, dialogo->dialogoa);
        DIALOGO_GRAFIKO_aukerakIdatzi(renderer, font, partialString);
        pantailaEguneratuEstalkiekin(renderer);
        SDL_Delay(DIALOGO_GRAFIKO_LETRA_DENBORA);
        handleQuit();
    }
}

int DIALOGO_GRAFIKO_itxaronZenbaki(int aukerak)
{
    int zenbaki = 0;
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) // Deskartatu aurreko ebentu guztiak, SDL_QUIT ezik.
    {
        if (e.type == SDL_QUIT)
        {
            fprintf(stderr, "Irtetzen SDL_QUIT jaso delako.");
            exit(EXIT_SUCCESS);
        }
    }
    while (!zenbaki)
    {
        if (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                fprintf(stderr, "Irtetzen SDL_QUIT jaso delako.");
                exit(EXIT_SUCCESS);
            }
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_1:
                    if (1 <= aukerak) zenbaki = 1;
                    break;
                case SDLK_2:
                    if (2 <= aukerak) zenbaki = 2;
                    break;
                case SDLK_3:
                    if (3 <= aukerak) zenbaki = 3;
                    break;
                case SDLK_4:
                    if (4 <= aukerak) zenbaki = 4;
                    break;
                case SDLK_5:
                    if (5 <= aukerak) zenbaki = 5;
                    break;
                case SDLK_6:
                    if (6 <= aukerak) zenbaki = 6;
                    break;
                case SDLK_7:
                    if (7 <= aukerak) zenbaki = 7;
                    break;
                case SDLK_8:
                    if (8 <= aukerak) zenbaki = 8;
                    break;
                case SDLK_9:
                    if (9 <= aukerak) zenbaki = 9;
                    break;
                }
            }
        }
        else
        {
            SDL_Delay(10);
        }
    }

    return zenbaki;
}