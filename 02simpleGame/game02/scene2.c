#include "scene2.h"

SDL_Rect rectFlecha = { 500, 500, 50, 50 };

SDL_Surface* initScene(SDL_Window* lehioa, int* lehiozabalera, int* lehioaltuera) {

    SDL_GetWindowSize(lehioa, lehiozabalera, lehioaltuera);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Error al inicializar SDL: %s\n", SDL_GetError());
        return NULL;
    }

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        printf("Error al inicializar SDL_image: %s\n", IMG_GetError());
        SDL_Quit();
        return NULL;
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {

        printf("Error al inicializar SDL: %s\n", SDL_GetError());
        return NULL;
    }

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        printf("Error al inicializar SDL_image: %s\n", IMG_GetError());
        SDL_Quit();
        return NULL;
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

void MunduAldaketa(SDL_Window* lehioa, SDL_Surface* superficie, SDL_Rect* pertsonaia, int kanpo, const Uint8* keyboardState, enum Pantaila* ikusi_pantaila)
{
    if (pertsonaia->x >= 100 && pertsonaia->x <= 385 && pertsonaia->y >= 0 && pertsonaia->y <= 50)
    {
        if (!SELFIE_eginda(ANIMALIA_HARTZ_TXURI) || !SELFIE_eginda(ANIMALIA_AZERI_ARTIKO))
        {
            iparPoloa(lehioa, superficie, keyboardState, ikusi_pantaila);;
        }
        kanpo = 1;

    }
    else if (pertsonaia->x >= -1 && pertsonaia->x <= 20 && pertsonaia->y <= 355 && pertsonaia->y >= 150)
    {
        if (!SELFIE_eginda(ANIMALIA_AXOLOTE) || !SELFIE_eginda(ANIMALIA_AMAZONIAR_MANATI))
        {
            ibaia(lehioa, superficie, keyboardState, ikusi_pantaila);
        }
        kanpo = 1;
    }
    else if (pertsonaia->x >= 500 && pertsonaia->x <= 600 && pertsonaia->y >= 155 && pertsonaia->y <= 390)
    {
        if (!SELFIE_eginda(ANIMALIA_BELUGA) || !SELFIE_eginda(ANIMALIA_BALE_URDIN))
        {
            itsasoa(lehioa, superficie, keyboardState, ikusi_pantaila);
        }
        kanpo = 1;
    }
    else if (pertsonaia->x >= 100 && pertsonaia->x <= 385 && pertsonaia->y >= 400 && pertsonaia->y <= 500)
    {
        if (!SELFIE_eginda(ANIMALIA_JAGUAR) || !SELFIE_eginda(ANIMALIA_LEMUR))
        {
            basoa(lehioa, superficie, keyboardState, ikusi_pantaila);
        }
        kanpo = 1;
    }
}

void maparenEszena(SDL_Window* lehioa, SDL_Surface* superficie, enum Pantaila* ikusi_pantailan)
{
    int i, j;
    int hasierkoXpos_perts = 100;
    int  hasierkoYpos_perts = 150;

    int kanpo = 0;

    SDL_Surface* backgroundSuperficie = initScene(lehioa, &lehiozabalera, &lehioaltuera);
    SDL_Surface* flechaSuperficie = flechaArgazkia(lehioa);

    SDL_Rect pertsonaia = { 250, 250, 50, 50 };  // Ajusta los valores según sea necesario

    SDL_Surface* pertsonaia_argazkia[NUM_DIRECCIONES][NUM_IMAGENES] = { NULL };
    for (i = 0; i < NUM_DIRECCIONES; ++i)
    {
        for (j = 0; j < (i % 2 ? NUM_IMAGENES_HORIZONTAL : NUM_IMAGENES_VERTICAL); ++j)
        {
            pertsonaia_argazkia[i][j] = IMG_Load(imagenes[i][j]);
            if (!pertsonaia_argazkia[i][j])
            {
                fprintf(stderr, "Error al cargar la imagen: %s\n", IMG_GetError());
                cleanUp(pertsonaia_argazkia, backgroundSuperficie);
                return;
            }
        }
    }

    while (*ikusi_pantailan == 1) {

        const Uint8* keyboardState = SDL_GetKeyboardState(NULL);

        if (!backgroundSuperficie)
        {
            return;
        }

        if (!kanpo)
        {
            pertsonaiaMugitu(lehioa, superficie, &pertsonaia, &bertako_pertsonaia, &bertako_pertsonaia_i, &kanpo, lehiozabalera, lehioaltuera, keyboardState);
            flechaClick(lehioa, superficie, rectFlecha.x, rectFlecha.y, ikusi_pantailan);
            MunduAldaketa(lehioa, superficie, &pertsonaia, kanpo, keyboardState, ikusi_pantailan);
            SDL_BlitSurface(backgroundSuperficie, NULL, superficie, NULL);
            SDL_BlitSurface(pertsonaia_argazkia[bertako_pertsonaia][bertako_pertsonaia_i], NULL, superficie, &pertsonaia);
            SDL_BlitScaled(flechaSuperficie, NULL, superficie, &(rectFlecha));

            if (kanpo)
            {
                cleanUp(pertsonaia_argazkia, backgroundSuperficie);
                break;
            }
            pantailaEguneratuEstalkiekinGainazala(lehioa, superficie);
            SDL_Delay(130);
        }
    }
}

SDL_Surface* flechaArgazkia(SDL_Window* lehioa)
{
    SDL_Surface* flecha = IMG_Load("img/flecha.png");
    if (flecha == NULL) {
        printf("Ezin da flecha argazkia kargatu: %s\n", IMG_GetError());
        return NULL;
    }

    return flecha;
}

void flechaClick(SDL_Window* lehioa, SDL_Surface* superficie, int flechaDestX, int flechaDestY, enum Pantaila* ikusi_pantailan)
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
            PantailaAldaketa(lehioa, superficie);

        }
    }
}

void flechaClickMapa(SDL_Event event, SDL_Window* lehioa, SDL_Surface* superficie, enum Pantaila* ikusi_pantaila)
{
    int clicEnFlecha = 0;
    int mouseX;
    int mouseY;
    

    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        SDL_GetMouseState(&mouseX, &mouseY);


        if (SDL_PointInRect(&(SDL_Point) { mouseX, mouseY }, & (rectFlecha)))
        {
            maparenEszena(lehioa, superficie, ikusi_pantaila);
            pantailaEguneratuEstalkiekinGainazala(lehioa, superficie);
        }
    }
}