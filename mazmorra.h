#ifndef MAZMORRA_H
#define MAZMORRA_H

#include "villanos.h"
#include <vector>
using namespace std;

class mazmorra {
private:
    int salaActual;
    int totalSalas;
    vector<villanos*> enemigos;

public:
    mazmorra();
    void avanzarSala();
    int getSalaActual() const;
    bool esFinal() const;

    villanos* enemigoActual() const;
    void generarMazmorra();
};

#endif // MAZMORRA_H
