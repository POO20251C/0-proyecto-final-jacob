#include "armadura.h"
#include "heroes.h"
#include <iostream>
using namespace std;

armadura::armadura(const string& nombre, const string& descripcion, int duracion, int precio, int resistencia)
    : items(nombre, descripcion, duracion, ItemType::ARMADURA, precio), resistencia(resistencia) {}

void armadura::usar(heroes* h) {
    cout << h->getNombre() << " ha equipado una armadura con +" << resistencia << " DEF.\n";

}

int armadura::getResistencia() const {
    return resistencia;
}

items* armadura::clonar() const {
    return new armadura(*this);
}

