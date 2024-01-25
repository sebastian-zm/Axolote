#include "dialogo.h"

//Dialogoa sortzeko balio duen funtzioa
struct Dialogo* DIALOGO_sortu(char izena[], char dialogoa[], struct Dialogo* aukerak[], int aukerakKop)
{
	// struct Dialogo bat malloc gabe sortuko banu, funtzioa amaitzerakoan suntsitua izango litzateke.
	struct Dialogo* dialogo = malloc(sizeof(*dialogo));
	ERRORIF(!dialogo, "Memoria gabe geratu gara. =(");

	size_t izenaLen = strlen(izena), dialogoaLen = strlen(dialogoa);

	ERRORIF(aukerakKop > DIALOGO_MAX_AUKERAK, "aukerakKop handiegia pasatu da DIALOGO_sortu funtziora.");
	ERRORIF(izenaLen > DIALOGO_MAX_STR_LEN, "DIALOGO_sortu funtziora pasatu den izena luzeegia da.");
	ERRORIF(dialogoaLen > DIALOGO_MAX_STR_LEN, "DIALOGO_sortu funtziora pasatu den dialogoa luzeegia da.");

	dialogo->aukerakKop = aukerakKop;

	memcpy(dialogo->aukerak, aukerak, aukerakKop * sizeof(dialogo));
	memcpy(dialogo->izena, izena, izenaLen + 1);
	memcpy(dialogo->dialogoa, dialogoa, dialogoaLen + 1);

	return dialogo;
}

//Egindako dialogo batek memoria ez okupatzeko balio duen funtzioa
void DIALOGO_ezabatu(struct Dialogo* dialogo)
{
	int aukera;
	for (aukera = 0; aukera < dialogo->aukerakKop; ++aukera)
	{
		DIALOGO_ezabatu(dialogo->aukerak[aukera]);
	}
	free(dialogo);
}

//Dialogoan hurrengoko aukerara pasatzeko balio duen funtzioa
void DIALOGO_aurrera(struct Dialogo** dialogo, int aukera)
{
	ERRORIF(aukera >= (*dialogo)->aukerakKop, "DIALOGO_aurrera funtziora pasatu den aukera handiegia da.");

	*dialogo = (*dialogo)->aukerak[aukera];
}

//DIalogoaren ziklo nagusia
void DIALOGO_gauzatu(struct Dialogo* dialogo, enum Animalia animalia, SDL_Renderer* renderer)
{
	int aukera;

	while (dialogo->aukerakKop)
	{
		aukera = DIALOGO_erakutsi(dialogo, animalia, renderer);
		DIALOGO_aurrera(&dialogo, aukera);
	}
}

//Dialogoa erakutsi eta bere logika azaltzen duen funtzioa
void DIALOGO_main(enum Animalia animalia, SDL_Renderer* renderer)
{
	struct Dialogo* dialogo = DIALOGO_inizializatu(animalia);

	DIALOGO_gauzatu(dialogo, animalia, renderer);

	DIALOGO_ezabatu(dialogo);

	SELFIE_main(renderer, animalia);
}

//Dialogoa hasieratzen duen funtzioa
struct Dialogo* DIALOGO_inizializatu(enum Animalia animalia)
{
	struct Dialogo* dialogo = 0;
	switch (animalia)
	{
	case ANIMALIA_AXOLOTE:
		DIALOGO_inizializatuAxolote(&dialogo);
		break;
	case ANIMALIA_AMAZONIAR_MANATI:
		DIALOGO_inizializatuAmazoniarManati(&dialogo);
		break;
	case ANIMALIA_BELUGA:
		DIALOGO_inizializatuBeluga(&dialogo);
		break;
	case ANIMALIA_BALE_URDIN:
		DIALOGO_inizializatuBaleUrdin(&dialogo);
		break;
	case ANIMALIA_HARTZ_TXURI:
		DIALOGO_inizializatuHartzTxuri(&dialogo);
		break;
	case ANIMALIA_LEMUR:
		DIALOGO_inizializatuLemur(&dialogo);
		break;
	case ANIMALIA_AZERI_ARTIKO:
		DIALOGO_inizializatuAzeriArtiko(&dialogo);
		break;
	case ANIMALIA_JAGUAR:
		DIALOGO_inizializatuJaguar(&dialogo);
		break;
	}

	return dialogo;
}
