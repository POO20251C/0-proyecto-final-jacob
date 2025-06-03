#ifndef MENU_H
#define MENU_H

#include "juego.h"

using namespace std;

class menu {
private:
    juego juegoPrincipal;

public:
    menu();
    void mostrarMenu();
    void iniciarNuevoJuego();

};

#endif // MENU_H
