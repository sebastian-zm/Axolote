#include "dialogoak_kargatu.h"

//Hurrengo karakterea lerroaren amaiera den ala ez detektatu eta bueltatzen du
int DIALOGOAK_karaktereaHartu(char* karakterea, FILE* fitxategia)
{
	int ret;

	int c; // EOF can only be detected before fgetc is cast to char.

	c = fgetc(fitxategia);

	*karakterea = c;

	switch (c)
	{
	case '\n':
	case EOF:
		ret = 0;
		break;
	default:
		ret = 1;
		break;
	}
	return ret;
}

//> eta < arteko espazioa sahiesten du lerroaren lehen karakterea lortzeko
int DIALOGOAK_lehenKaraktereaHartu(char* karakterea, FILE* fitxategia)
{
	int c; // EOF can only be detected before fgetc is cast to char.
	do
	{
		c = fgetc(fitxategia);
	} while (c == '\t' || c == '\n' || c == '\r' || c == ' ');

	*karakterea = c;
	return c != EOF;
}

//Lerro amaierararte esaldi bat irakurtzen duen funtzioa
int DIALOGOAK_stringIrakurri(char string[], int n, FILE* fitxategia)
{
	// 1 bueltatzen du string osoa n karakteretan sartu bada.

	int bufferLen;
	char* buffer = malloc((n + 1) * sizeof(*buffer));

	ERRORIF(!buffer, "Memoria gabe geratu gara fitxategia irakurtzeko. =(");

	DIALOGOAK_lehenKaraktereaHartu(buffer, fitxategia);

	int ondo = (int) fgets(buffer + 1, n, fitxategia);

	if (ondo)
	{
		bufferLen = strlen(buffer);
		ondo = buffer[bufferLen - 1] == '\n';
	}

	if (ondo)
	{
		buffer[bufferLen - 1] = 0;
		strcpy(string, buffer); // fgets() makes sure this does not overflow
	}

	return ondo;
}

//Fitxategi batetik dialogoaren edukia kargatzen duen funtzioa
int DIALOGOAK_inizializatuFitxategitik(struct Dialogo** dialogo, FILE* fitxategia)
{
	char izena[DIALOGO_MAX_STR_LEN + 1] = "";
	char dialogoa[DIALOGO_MAX_STR_LEN + 1] = "";
	struct Dialogo* arr[DIALOGO_MAX_AUKERAK] = { NULL };
	int arrLen = 0;
	char oraingoa;
	char oraingoaStr[2] = { 0, 0 };
	int ondo = 1;
	char found[3] = "";

	DIALOGOAK_lehenKaraktereaHartu(&oraingoa, fitxategia);

	do
	{
		oraingoaStr[0] = oraingoa;
		if (oraingoa == '{' && arrLen < sizeof(arr))
		{
			ondo = DIALOGOAK_inizializatuFitxategitik(&arr[arrLen], fitxategia);
			++arrLen;
		}
		else if (oraingoa == '>' && !strchr(found, '>'))
		{
			ondo = DIALOGOAK_stringIrakurri(izena, sizeof(izena), fitxategia);
			strcat(found, oraingoaStr); // safe because of `!strchr(found, '>')` on the if and the max length of 3
		}
		else if (oraingoa == '<' && !strchr(found, '<'))
		{
			ondo = DIALOGOAK_stringIrakurri(dialogoa, sizeof(dialogoa), fitxategia);
			strcat(found, oraingoaStr); // safe because of `!strchr(found, '<')` on the if and the max length of 3
		}
		else
		{
			ondo = 0;
		}

		if (ondo) ondo = DIALOGOAK_lehenKaraktereaHartu(&oraingoa, fitxategia);
	} while (oraingoa != '}' && ondo);

	if (ondo)
	{
		*dialogo = DIALOGO_sortu(izena, dialogoa, arr, arrLen);
	}

	return ondo;
}

//Path batetik dialogoaren edukia kargatzen duen funtzioa
int DIALOGOAK_inizializatuPathBatetik(struct Dialogo** dialogo, char* path)
{
	FILE* fitxategia = fitxategiaIrakurtzekoIreki(path); // Path-aren fitxategia zabaltzen du goiko funtzioari deitzeko
	char first;

	int ondo = DIALOGOAK_lehenKaraktereaHartu(&first, fitxategia);

	ondo = ondo && first == '{';

	ondo = ondo && DIALOGOAK_inizializatuFitxategitik(dialogo, fitxategia);

	fclose(fitxategia);

	return ondo;
}

//Animali bakoitzaren dialogoa hasieratzen dituzten funtzioak:

void DIALOGO_inizializatuAxolote(struct Dialogo** dialogo)
{
	int ondo = DIALOGOAK_inizializatuPathBatetik(dialogo, DIALOGOAK_AXOLOTE_PATH);
	ERRORIF(!ondo, "Ezin izan da fitxategia irakurri. Path: %s", DIALOGOAK_AXOLOTE_PATH);
}

void DIALOGO_inizializatuAmazoniarManati(struct Dialogo** dialogo)
{
	int ondo = DIALOGOAK_inizializatuPathBatetik(dialogo, DIALOGOAK_AMAZONIAR_MANATI_PATH);
	ERRORIF(!ondo, "Ezin izan da fitxategia irakurri. Path: %s", DIALOGOAK_AMAZONIAR_MANATI_PATH);
}


void DIALOGO_inizializatuBeluga(struct Dialogo** dialogo)
{
	int ondo = DIALOGOAK_inizializatuPathBatetik(dialogo, DIALOGOAK_BELUGA_PATH);
	ERRORIF(!ondo, "Ezin izan da fitxategia irakurri. Path: %s", DIALOGOAK_BELUGA_PATH);
}

void DIALOGO_inizializatuBaleUrdin(struct Dialogo** dialogo)
{
	int ondo = DIALOGOAK_inizializatuPathBatetik(dialogo, DIALOGOAK_BALE_URDIN_PATH);
	ERRORIF(!ondo, "Ezin izan da fitxategia irakurri. Path: %s", DIALOGOAK_BALE_URDIN_PATH);
}



void DIALOGO_inizializatuHartzTxuri(struct Dialogo** dialogo)
{
	int ondo = DIALOGOAK_inizializatuPathBatetik(dialogo, DIALOGOAK_HARTZ_TXURI_PATH);
	ERRORIF(!ondo, "Ezin izan da fitxategia irakurri. Path: %s", DIALOGOAK_HARTZ_TXURI_PATH);
}

void DIALOGO_inizializatuLemur(struct Dialogo** dialogo)
{
	int ondo = DIALOGOAK_inizializatuPathBatetik(dialogo, DIALOGOAK_LEMUR_PATH);
	ERRORIF(!ondo, "Ezin izan da fitxategia irakurri. Path: %s", DIALOGOAK_LEMUR_PATH);
}


void DIALOGO_inizializatuAzeriArtiko(struct Dialogo** dialogo)
{
	int ondo = DIALOGOAK_inizializatuPathBatetik(dialogo, DIALOGOAK_AZERI_ARTIKO_PATH);
	ERRORIF(!ondo, "Ezin izan da fitxategia irakurri. Path: %s", DIALOGOAK_AZERI_ARTIKO_PATH);
}


void DIALOGO_inizializatuJaguar(struct Dialogo** dialogo)
{
	int ondo = DIALOGOAK_inizializatuPathBatetik(dialogo, DIALOGOAK_JAGUAR_PATH);
	ERRORIF(!ondo, "Ezin izan da fitxategia irakurri. Path: %s", DIALOGOAK_JAGUAR_PATH);
}