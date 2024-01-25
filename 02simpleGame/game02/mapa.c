#include "mapa.h"

SDL_Rect rectFlecha = { 500, 500, 50, 50 };

//Mapa agertarazteko 
SDL_Surface* initScene(SDL_Window* leihoa)
{
    SDL_Surface* backgroundSurface = irudiaKargatuGainazalera("img/mapa.png");

    if (!backgroundSurface)
    {
        printf("Ezin da atzeko argazkia kargatu: %s\n", IMG_GetError());
        return NULL;
    }

    SDL_Surface* scaledBackgroundSurface = SDL_CreateRGBSurface(0, WINDOW_WIDTH, WINDOW_HEIGHT, 32, 0, 0, 0, 0);
    SDL_BlitScaled(backgroundSurface, NULL, scaledBackgroundSurface, NULL);
    SDL_FreeSurface(backgroundSurface);

    return scaledBackgroundSurface; //balore hau erabiltzen da, beraz ez da "free" egiten
}

//Biomen marginak kudeatu
void MunduAldaketa(SDL_Window* leihoa, SDL_Surface* superficie, SDL_Rect* pertsonaia, const Uint8* keyboardState, enum Pantaila* ikusi_pantaila)
{
    if (pertsonaia->y >= 0 && pertsonaia->y <= 50)
    {
        if (!SELFIE_eginda(ANIMALIA_HARTZ_TXURI) || !SELFIE_eginda(ANIMALIA_AZERI_ARTIKO))
        {
            iparPoloa(leihoa, superficie, keyboardState, ikusi_pantaila);
        }
    }
    else if (pertsonaia->x >= -1 && pertsonaia->x <= 20 && pertsonaia->y <= 455 && pertsonaia->y >= 50)
    {
        if (!SELFIE_eginda(ANIMALIA_AXOLOTE) || !SELFIE_eginda(ANIMALIA_AMAZONIAR_MANATI))
        {
            ibaia(leihoa, superficie, keyboardState, ikusi_pantaila);
        }
    }
    else if (pertsonaia->x >= 450 && pertsonaia->x <= 600 && pertsonaia->y >= 155 && pertsonaia->y <= 490)
    {
        if (!SELFIE_eginda(ANIMALIA_BELUGA) || !SELFIE_eginda(ANIMALIA_BALE_URDIN))
        {
            itsasoa(leihoa, superficie, keyboardState, ikusi_pantaila);
        }
    }
    else if (pertsonaia->x >= 50 && pertsonaia->x <= 450 && pertsonaia->y >= 450 && pertsonaia->y <= 500)
    {
        if (!SELFIE_eginda(ANIMALIA_JAGUAR) || !SELFIE_eginda(ANIMALIA_LEMUR))
        {
            basoa(leihoa, superficie, keyboardState, ikusi_pantaila);
        }
    }
}

// Pertsonaiaren mugimenduaren argazkiak memoriara kargatu eta fletxa agertarazi
void maparenEszena(SDL_Window* leihoa, SDL_Surface* superficie, enum Pantaila* ikusi_pantailan)
{
    int i, j;
    int bertako_pertsonaia = 0;
    int bertako_pertsonaia_i = 0;
    

    SDL_Surface* backgroundSuperficie = initScene(leihoa); //scaledBackgroundSurface balioa hartzen du
    SDL_Surface* flechaSuperficie = flechaArgazkia(leihoa);

    SDL_Rect pertsonaia = { 250, 250, 50, 50 };

    SDL_Surface* pertsonaia_argazkia[NUM_DIRECCIONES][NUM_IMAGENES] = { NULL };

    for (i = 0; i < NUM_DIRECCIONES; ++i)
    {
        for (j = 0; j < (i % 2 ? NUM_IMAGENES_HORIZONTAL : NUM_IMAGENES_VERTICAL); ++j)
        {
            pertsonaia_argazkia[i][j] = IMG_Load(imagenes[i][j]);
            if (!pertsonaia_argazkia[i][j])
            {
                fprintf(stderr, "Error al cargar la imagen: %s\n", IMG_GetError());
                return;
            }
        }
    }

    while (*ikusi_pantailan == 1)
    {
        const Uint8* keyboardState = SDL_GetKeyboardState(NULL);

        if (!backgroundSuperficie)
        {
            return;
        }

        pertsonaiaMugitu(leihoa, superficie, &pertsonaia, &bertako_pertsonaia, &bertako_pertsonaia_i, keyboardState);//pertsonaiaren mugimenduari deitu
        flechaClick(leihoa, superficie, rectFlecha, ikusi_pantailan); //fletxari klik egin zaion detektatu
        MunduAldaketa(leihoa, superficie, &pertsonaia, keyboardState, ikusi_pantailan);//biomen marginera pertsonaia heldu den detektatu
        SDL_BlitSurface(backgroundSuperficie, NULL, superficie, NULL);
        SDL_BlitSurface(pertsonaia_argazkia[bertako_pertsonaia][bertako_pertsonaia_i], NULL, superficie, &pertsonaia);
        SDL_BlitScaled(flechaSuperficie, NULL, superficie, &(rectFlecha));

        pantailaEguneratuEstalkiekinGainazala(leihoa, superficie);//egindako selfie-en miniatu
        SDL_Delay(130);
    }
    SDL_FreeSurface(backgroundSuperficie);
    SDL_FreeSurface(flechaSuperficie);
}

//fletxaren irudia hasieratzeko
SDL_Surface* flechaArgazkia(SDL_Window* leihoa)
{
    SDL_Surface* flecha = IMG_Load("img/flecha.png");
    if (flecha == NULL)
    {
        printf("Ezin da flecha argazkia kargatu: %s\n", IMG_GetError());
        return NULL;
    }

    return flecha;
}

//fletxari klik egiterakoan detektatu eta hasierako menura bidali
void flechaClick(SDL_Window* leihoa, SDL_Surface* superficie, SDL_Rect rectFlecha, enum Pantaila* ikusi_pantailan)
{
    int clicEnFlecha = 0;
    int mouseX;
    int mouseY;
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        handleQuitEvent(event);
        SDL_GetMouseState(&mouseX, &mouseY);

        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (SDL_PointInRect(&(SDL_Point) { mouseX, mouseY }, & (rectFlecha)))
            {
                clicEnFlecha = 1;
            }
        }
        if (clicEnFlecha == 1)
        {
            PantailaAldaketa(leihoa, superficie);

        }
    }
}

//fletxari klik egiterakoan detektatu eta hasierako mapari bidali
void flechaClickMapa(SDL_Event event, SDL_Window* leihoa, SDL_Surface* superficie, enum Pantaila* ikusi_pantaila)
{
    int clicEnFlecha = 0;
    int mouseX;
    int mouseY;
    

    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        SDL_GetMouseState(&mouseX, &mouseY);


        if (SDL_PointInRect(&(SDL_Point) { mouseX, mouseY }, & (rectFlecha)))
        {
            maparenEszena(leihoa, superficie, ikusi_pantaila);
            pantailaEguneratuEstalkiekinGainazala(leihoa, superficie);
        }
    }
}