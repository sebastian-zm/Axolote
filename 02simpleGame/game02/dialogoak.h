#ifndef DIALOGOAK_H
#define DIALOGOAK_H

#include <stdio.h>

#define DIALOGOAK_AXOLOTE_PATH "dialogo/axolote.txt"
#define DIALOGOAK_AMAZONIAR_MANATI_PATH "dialogo/manati.txt"
#define DIALOGOAK_BELUGA_PATH "dialogo/beluga.txt"
#define DIALOGOAK_BALE_URDIN_PATH "dialogo/balea.txt"
#define DIALOGOAK_HARTZ_TXURI_PATH "dialogo/hartz.txt"
#define DIALOGOAK_LEMUR_PATH "dialogo/lemur.txt"
#define DIALOGOAK_AZERI_ARTIKO_PATH "dialogo/azeri.txt"
#define DIALOGOAK_JAGUAR_PATH "dialogo/jaguar.txt"

#define DIALOGOAK_LINEA_ARRAYRA(ary,fitxategi) ERRORIF(!fgets(ary, sizeof(ary), fitxategi), "Errorea Fitxategian.")

int DIALOGOAK_karaktereaHartu(char* karakterea, FILE* fitxategia);
int DIALOGOAK_lehenKaraktereaHartu(char* karakterea, FILE* fitxategia);
int DIALOGOAK_stringIrakurri(char string[], int n, FILE* fitxategia);
int DIALOGOAK_inizializatuFitxategitik(struct Dialogo** dialogo, FILE* fitxategia);
int DIALOGOAK_inizializatuPathBatetik(struct Dialogo** dialogo, char* path);

void DIALOGO_inizializatuAxolote(struct Dialogo** dialogo);
void DIALOGO_inizializatuAmazoniarManati(struct Dialogo** dialogo);
void DIALOGO_inizializatuBeluga(struct Dialogo** dialogo);
void DIALOGO_inizializatuBaleUrdin(struct Dialogo** dialogo);
void DIALOGO_inizializatuHartzTxuri(struct Dialogo** dialogo);
void DIALOGO_inizializatuLemur(struct Dialogo** dialogo);
void DIALOGO_inizializatuAzeriArtiko(struct Dialogo** dialogo);
void DIALOGO_inizializatuJaguar(struct Dialogo** dialogo);

#endif // !DIALOGOAK_H

