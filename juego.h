#ifndef JUEGO_H
#define JUEGO_H

#include "heroes.h"
#include "inventario.h"
#include "mazmorra.h"
#include "tienda.h"
#include <vector>
using namespace std;

class juego {
private:
    vector<heroes*> equipo;
    inventario inventarioGeneral;
    mazmorra* dungeon;
    tienda tiendA;

public:
    juego();
    ~juego();
    void iniciarJuego();
    void seleccionarHeroes();
    void jugarMazmorra();
    void loot();
    void avanzarTurno();
    inventario& getInventario();
    vector<string> ambientes() const;


};

#endif // JUEGO_H
