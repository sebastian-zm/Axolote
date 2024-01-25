#include "biomak_eta_interrogazioak.h"

//biomen atzeko planoen irudiak gordetzeko array-a
const char* biomak[NUM_BIOMAK] = {
    "img/ibaia.png",
    "img/iparpoloa.png",
    "img/itsasoa.png",
    "img/basoa.jpg"
};

//bidalitako animaliaren arabera bere galdera ikurrak sortuko duen errektanguluaren "rect"-a (x, y, h, w) bueltatzen duen funtzioa
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

//atzeko planoa, fletxa eta interrogazioak azaltzeko beharrezkoak diren funtzioei deitzen die
//bukle baten barruan interrogazioei ala fletxari klik egin zaien begiratzen du
//interrogazio baten klik ematen denean, dialogoaren ondoren berriro marrazten du pantaila (beharrezkoak ez diren interrogazioak ez agertarazteko)
void bioma(SDL_Window* leihoa, SDL_Surface* superficie, enum Pantaila* ikusi_pantailan, int bioma, enum Animalia animalia1, enum animalia animalia2)
{
    int kanpo = 0;
    SDL_Event e;
    atzekoPlanoaAldatuEtaFletxaAzaldu(biomak[bioma], superficie, leihoa, ikusi_pantailan);
    interrogazioaAzaldu(leihoa, animalia1);
    interrogazioaAzaldu(leihoa, animalia2);

    while (!kanpo)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            handleQuitEvent(e);
            flechaClickMapa(e, leihoa, superficie, ikusi_pantailan);
            if (interrogazioariKlick(leihoa, e, animalia1))
            {
                atzekoPlanoaAldatuEtaFletxaAzaldu(biomak[bioma], superficie, leihoa, ikusi_pantailan);
                interrogazioaAzaldu(leihoa, animalia1);
                interrogazioaAzaldu(leihoa, animalia2);
            }
            if (interrogazioariKlick(leihoa, e, animalia2))
            {
                atzekoPlanoaAldatuEtaFletxaAzaldu(biomak[bioma], superficie, leihoa, ikusi_pantailan);
                interrogazioaAzaldu(leihoa, animalia1);
                interrogazioaAzaldu(leihoa, animalia2);
            }

        }

        if (SELFIE_eginda(animalia1) && SELFIE_eginda(animalia2))
        {
            kanpo = 1;
        }

        SDL_Delay(16);
    }
}

//bioma funtzio nagusiari deitzen dio eta biomaren atzeko irudiaren zenbakia (array-aren arabera) eta bi animalien izena pasatzen dio
void ibaia(SDL_Window* leihoa, SDL_Surface* superficie, const Uint8* keyboardState, enum Pantaila* ikusi_pantailan)
{
    bioma(leihoa, superficie, ikusi_pantailan, 0, ANIMALIA_AXOLOTE, ANIMALIA_AMAZONIAR_MANATI);
}

//bioma funtzio nagusiari deitzen dio eta biomaren atzeko irudiaren zenbakia (array-aren arabera) eta bi animalien izena pasatzen dio
void itsasoa(SDL_Window* leihoa, SDL_Surface* superficie, const Uint8* keyboardState, enum Pantaila* ikusi_pantailan)
{
    bioma(leihoa, superficie, ikusi_pantailan, 2, ANIMALIA_BELUGA, ANIMALIA_BALE_URDIN);
}

//bioma funtzio nagusiari deitzen dio eta biomaren atzeko irudiaren zenbakia (array-aren arabera) eta bi animalien izena pasatzen dio
void basoa(SDL_Window* leihoa, SDL_Surface* superficie, const Uint8* keyboardState, enum Pantaila* ikusi_pantailan)
{
    bioma(leihoa, superficie, ikusi_pantailan, 3, ANIMALIA_LEMUR, ANIMALIA_JAGUAR);
}

//bioma funtzio nagusiari deitzen dio eta biomaren atzeko irudiaren zenbakia (array-aren arabera) eta bi animalien izena pasatzen dio
void iparPoloa(SDL_Window* leihoa, SDL_Surface* superficie, const Uint8* keyboardState, enum Pantaila* ikusi_pantailan)
{
    bioma(leihoa, superficie, ikusi_pantailan, 1, ANIMALIA_HARTZ_TXURI, ANIMALIA_AZERI_ARTIKO);
}

//leihoaren atzeko planoan agertuko den irudia aldatzeko balio duen funtzioa + fletxaren argazkia kargatzeko eta azaltzeko
void atzekoPlanoaAldatuEtaFletxaAzaldu(const char* imagePath, SDL_Surface* superficie, SDL_Window* leihoa, enum Pantaila* ikusi_pantailan)
{
    SDL_Surface* backgroundSurface = irudiaKargatuGainazalera(imagePath);

    SDL_Surface* scaledBackgroundSurface = SDL_CreateRGBSurface(0, WINDOW_WIDTH, WINDOW_HEIGHT, 32, 0, 0, 0, 0);
    if (!scaledBackgroundSurface)
    {
        printf("Ezin da RGB azala sortu: %s\n", SDL_GetError());
        SDL_FreeSurface(backgroundSurface);
        return;
    }

    SDL_Surface* flechaSuperficie = flechaArgazkia(leihoa);
    SDL_FillRect(scaledBackgroundSurface, NULL, SDL_MapRGBA(scaledBackgroundSurface->format, 0, 0, 0, 0));
    SDL_BlitScaled(backgroundSurface, NULL, scaledBackgroundSurface, NULL);
    SDL_FreeSurface(backgroundSurface);
    SDL_BlitSurface(scaledBackgroundSurface, NULL, superficie, NULL);
    pantailaEguneratuEstalkiekinGainazala(leihoa, superficie);
    SDL_FreeSurface(scaledBackgroundSurface);
    SDL_BlitScaled(flechaSuperficie, NULL, superficie, &(rectFlecha));
    SDL_FreeSurface(flechaSuperficie);
}

//selfie-ak eginda dauden edo ez arabera interrogazioak azaltzen ditu animaliaren izenaren arabera (euren rect-ak bilatuko ditu)
void interrogazioaAzaldu(SDL_Window* leihoa, enum Animalia animalia)
{
    if (!SELFIE_eginda(animalia))
    {
        SDL_Surface* superficie = SDL_GetWindowSurface(leihoa);

        SDL_Surface* interrogazioa = irudiaKargatuGainazalera("img/animali.png");

        SDL_Rect rect = getAnimaliarenRect(animalia);

        SDL_BlitSurface(interrogazioa, NULL, superficie, &rect);

        pantailaEguneratuEstalkiekinGainazala(leihoa, superficie);

        SDL_FreeSurface(interrogazioa);
    }
}

//interrogazio bati klik egin zaion detektatzeko balio duen funtzioa
int interrogazioariKlick(SDL_Window* leihoa, SDL_Event ebentua, enum Animalia animalia)
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
                animaliaHautatuDa(animalia, leihoa);
                eginda = 1;
            }
        }
    }
    return eginda;
}

//animaliaren izenaren arabera dialogo bat hasieratuko duen funtzioa
void animaliaHautatuDa(enum Animalia animalia, SDL_Window* leihoa)
{
    DIALOGO_main(animalia, SDL_GetRenderer(leihoa));
    amaieraBilatu(leihoa);
}
