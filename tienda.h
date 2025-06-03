#ifndef TIENDA_H
#define TIENDA_H

#include "armas.h"
#include "armadura.h"
#include "pociones.h"
#include "heroes.h"
#include "inventario.h" // Necesario para usar tipo inventario
#include <vector>
using namespace std;

class tienda {
private:
    vector<armas*> armasDisponibles;
    vector<armadura*> armadurasDisponibles;
    vector<pociones*> pocionesDisponibles;

public:
    tienda();


    void mostrarProductos(vector<heroes*>& equipo, inventario& inv);
    void comprarArma(heroes* h, int indice);
    void comprarArmadura(heroes* h, int indice);
    void comprarPocion(heroes* h, int indice);
    ;

    const vector<armas*>& getArmas() const;
    const vector<armadura*>& getArmaduras() const;
    const vector<pociones*>& getPociones() const;
};

#endif // TIENDA_H
