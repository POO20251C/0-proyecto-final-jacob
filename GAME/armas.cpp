#include "armas.h"
#include <iostream>
using namespace std;

// Constructor
armas::armas(string nombre, string descripcion, int duracion, int bonusAtk)
    : items(nombre, descripcion, duracion, ItemType::ARMA), bonusAtk(bonusAtk) {}


void armas::usar(heroes* h) {
    h->equiparArma(this);
    cout << h->getNombre() << " ha equipado el arma \"" << getNombre()
         << "\" con +" << bonusAtk << " ATK." << endl;
}

// Getter
int armas::getbonusAtk() const {
    return bonusAtk;
}

