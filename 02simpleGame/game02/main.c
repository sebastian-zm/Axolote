#include "init_screen.h"
#include "hasierako_orrialdea.h"
#include "mugimendua.h"

#define UNUSED(x) {(void) x;} //makroa warning batzuk saihesteko

int main(int argc, char** argv)
{
    UNUSED(argc);
    UNUSED(argv);
    SDL_Window* leihoa = NULL;
    SDL_Surface* superficie = NULL;

    Hasieratu(&leihoa, &superficie);
    // & --> memoria aldatzeko (puntero bat bidaltzeko)
    PantailaAldaketa(leihoa, superficie);

    return 0;
}
