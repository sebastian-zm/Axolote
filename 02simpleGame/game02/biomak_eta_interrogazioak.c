#include "biomak_eta_interrogazioak.h"

//biomen atzeko planoen irudiak gordetzeko array-a
const char* biomak[NUM_BIOMAK] = {
    "img/ibaia.png",
    "img/iparpoloa.png",
    "img/itsasoa.png",
    "img/basoa.jpg"
};

SDL_Rect getAnimaliarenRect(enum Animalia animalia)
{
    SDL_Rect rect;
    switch (animalia)
    {
    case ANIMALIA_AXOLOTE:
        rect = (SDL_Rect){ 385, 485, 50, 50 };
        break;
    case ANIMALIA_AMAZONIAR_MANATI:
        rect = (SDL_Rect){ 350, 375, 50, 50 };
        break;
    case ANIMALIA_AZERI_ARTIKO:
        rect = (SDL_Rect){ 200, 300, 50, 50 };
        break;
    case ANIMALIA_BALE_URDIN:
        rect = (SDL_Rect){ 400, 250, 50, 50 };
        break;
    case ANIMALIA_BELUGA:
        rect = (SDL_Rect){ 100, 250, 50, 50 };
        break;
    case ANIMALIA_HARTZ_TXURI:
        rect = (SDL_Rect){ 400, 450, 50, 50 };
        break;
    case ANIMALIA_JAGUAR:
        rect = (SDL_Rect){ 400, 500, 50, 50 };
        break;
    default: // ANIMALIA_LEMUR
        rect = (SDL_Rect){ 100, 500, 50, 50 };
        break;
    }
    return rect;
}

void bioma(SDL_Window* lehioa, SDL_Surface* superficie, enum Pantaila* ikusi_pantailan, int bioma, enum Animalia animalia1, enum animalia animalia2)
{
    int kanpo = 0;
    SDL_Event e;
    atzekoPlanoaAldatuEtaFletxaAzaldu(biomak[bioma], superficie, lehioa, ikusi_pantailan);
    interrogazioaAzaldu(lehioa, animalia1);
    interrogazioaAzaldu(lehioa, animalia2);

    while (!kanpo)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            handleQuitEvent(e);
            flechaClickMapa(e, lehioa, superficie, ikusi_pantailan);
            if (interrogazioariKlick(lehioa, e, animalia1))
            {
                atzekoPlanoaAldatuEtaFletxaAzaldu(biomak[bioma], superficie, lehioa, ikusi_pantailan);
                interrogazioaAzaldu(lehioa, animalia1);
                interrogazioaAzaldu(lehioa, animalia2);
            }
            if (interrogazioariKlick(lehioa, e, animalia2))
            {
                atzekoPlanoaAldatuEtaFletxaAzaldu(biomak[bioma], superficie, lehioa, ikusi_pantailan);
                interrogazioaAzaldu(lehioa, animalia1);
                interrogazioaAzaldu(lehioa, animalia2);
            }

        }

        if (SELFIE_eginda(animalia1) && SELFIE_eginda(animalia2))
        {
            kanpo = 1;
        }

        SDL_Delay(16);
    }
}

/* void ibaia:
- ibaiaren eszena kargatzen du: atzeko planoa, interrogazioen erakusketa eta euren gainean klik egiterakoan detekzioa
- ibaian agertuko diren animalia bakoitzarentzako "rect" bat sortzen du, euren interrogazioen x, y, altuera eta zabalera finkatzeko
- behin bi animaliekin selfie-a eginda dagoela, main nagusitik aterako da funtzioa */
void ibaia(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState, enum Pantaila* ikusi_pantailan)
{
    bioma(lehioa, superficie, ikusi_pantailan, 0, ANIMALIA_AXOLOTE, ANIMALIA_AMAZONIAR_MANATI);
}

/* void itsasoa:
- itsasoaren eszena kargatzen du: atzeko planoa, interrogazioen erakusketa eta euren gainean klik egiterakoan detekzioa
- itsasoan agertuko diren animalia bakoitzarentzako "rect" bat sortzen du, euren interrogazioen x, y, altuera eta zabalera finkatzeko
- behin bi animaliekin selfie-a eginda dagoela, main nagusitik aterako da funtzioa */
void itsasoa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState, enum Pantaila* ikusi_pantailan)
{
    bioma(lehioa, superficie, ikusi_pantailan, 2, ANIMALIA_BELUGA, ANIMALIA_BALE_URDIN);
}

/* void basoa:
- basoaren eszena kargatzen du: atzeko planoa, interrogazioen erakusketa eta euren gainean klik egiterakoan detekzioa
- basoan agertuko diren animali bakoitzarentzako "rect" bat sortu da, euren interrogazioen x, y, altuera eta zabalera finkatzeko
- behin bi animaliekin selfie-a eginda dagoela, main nagusitik aterako da funtzioa */
void basoa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState, enum Pantaila* ikusi_pantailan)
{
    bioma(lehioa, superficie, ikusi_pantailan, 3, ANIMALIA_LEMUR, ANIMALIA_JAGUAR);
}

/* void iparPoloa:
- ipar poloaren eszena kargatzen du: atzeko planoa, interrogazioen erakusketa eta euren gainean klik egiterakoan detekzioa
- ipar poloan agertuko diren animali bakoitzarentzako "rect" bat sortu da, euren interrogazioen x, y, altuera eta zabalera finkatzeko
- behin bi animaliekin selfie-a eginda dagoela, main nagusitik aterako da funtzioa */
void iparPoloa(SDL_Window* lehioa, SDL_Surface* superficie, const Uint8* keyboardState, enum Pantaila* ikusi_pantailan)
{
    bioma(lehioa, superficie, ikusi_pantailan, 1, ANIMALIA_HARTZ_TXURI, ANIMALIA_AZERI_ARTIKO);
}

//lehioaren atzeko planoan agertuko den irudia aldatzeko balio duen funtzioa + fletxaren argazkia kargatzeko eta azaltzeko
void atzekoPlanoaAldatuEtaFletxaAzaldu(char* imagePath, SDL_Surface* superficie, SDL_Window* lehioa, enum Pantaila* ikusi_pantailan)
{
    int lehiozabalera, lehioaltuera, flechaDestX = 400, flechaDestY = 500;
    SDL_GetWindowSize(lehioa, &lehiozabalera, &lehioaltuera);

    SDL_Surface* backgroundSurface = irudiaKargatuGainazalera(imagePath);

    SDL_Surface* scaledBackgroundSurface = SDL_CreateRGBSurface(0, lehiozabalera, lehioaltuera, 32, 0, 0, 0, 0);
    if (!scaledBackgroundSurface)
    {
        printf("Ezin da RGB azala sortu: %s\n", SDL_GetError());
        SDL_FreeSurface(backgroundSurface);
        return;
    }

    SDL_Surface* flechaSuperficie = flechaArgazkia(lehioa);
    SDL_FillRect(scaledBackgroundSurface, NULL, SDL_MapRGBA(scaledBackgroundSurface->format, 0, 0, 0, 0));
    SDL_BlitScaled(backgroundSurface, NULL, scaledBackgroundSurface, NULL);
    SDL_FreeSurface(backgroundSurface);
    SDL_BlitSurface(scaledBackgroundSurface, NULL, superficie, NULL);
    pantailaEguneratuEstalkiekinGainazala(lehioa, superficie);
    SDL_FreeSurface(scaledBackgroundSurface);
    SDL_BlitScaled(flechaSuperficie, NULL, superficie, &(rectFlecha));
    SDL_FreeSurface(flechaSuperficie);
}

//jasotako bi "rect" ezberdinen arabera pantailan bi galdera ikur erakusteko balio duen funtzioa
void interrogazioaAzaldu(SDL_Window* lehioa, enum Animalia animalia)
{
    if (!SELFIE_eginda(animalia))
    {
        SDL_Surface* superficie = SDL_GetWindowSurface(lehioa);

        SDL_Surface* interrogazioa = irudiaKargatuGainazalera("img/animali.png");

        SDL_Rect rect = getAnimaliarenRect(animalia);

        SDL_BlitSurface(interrogazioa, NULL, superficie, &rect);

        pantailaEguneratuEstalkiekinGainazala(lehioa, superficie);

        SDL_FreeSurface(interrogazioa);
    }
}

int interrogazioariKlick(SDL_Window* lehioa, SDL_Event ebentua, enum Animalia animalia)
{
    SDL_Rect rect;
    int eginda = 0;
    int mouseX, mouseY;

    if (ebentua.type == SDL_MOUSEBUTTONDOWN)
    {
        rect = getAnimaliarenRect(animalia);
        SDL_GetMouseState(&mouseX, &mouseY);
        if (SDL_PointInRect(&(SDL_Point) { mouseX, mouseY }, & rect))
        {
            if (!SELFIE_eginda(animalia))
            {
                animaliaHautatuDa(animalia, lehioa);
                eginda = 1;
            }
        }
    }
    return eginda;
}

//jasotako animaliaren arabera beharrezkoa den dialogoa hasieratzeko balio duen funtzioa
void animaliaHautatuDa(enum Animalia animalia, SDL_Window* lehioa)
{
    DIALOGO_main(animalia, SDL_GetRenderer(lehioa));
}

