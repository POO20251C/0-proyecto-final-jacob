#ifndef JUEGO_H
#define JUEGO_H
#include "heroes.h"
#include "inventario.h"
#include "mazmorra.h"

class juego {
private:
    vector<heroes*> equipo;
    inventario inventarioGeneral;
    mazmorra* dungeon;

public:
    void iniciarJuego();
    void seleccionarHeroes();
    void jugarMazmorra();
    void mostrarMenuPrincipal();
    void guardarScore();

};



#endif //JUEGO_H
