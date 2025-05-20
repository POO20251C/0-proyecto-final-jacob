#include "armadura.h"
#include <iostream>
using namespace std;

// Constructor
armadura::armadura(string nombre, string descripcion, int duracion, int resistencia)
    : items(nombre, descripcion, duracion, ItemType::AMRADURA), resistencia(resistencia) {}

// Método usar - equipar armadura al héroe
void armadura::usar(heroes* h) {
    h->equiparArmadura(this);
    cout << h->getNombre() << " ha equipado la armadura " << getNombre()
         << "\" con +" << resistencia << " DEF." << endl;
}

// Getter
int armadura::getResistencia() const {
    return resistencia;
}
