#include "armas.h"
#include "heroes.h"
#include <iostream>
using namespace std;

armas::armas(const string& nombre, const string& descripcion, int duracion, int precio, int bonusAtk)
    : items(nombre, descripcion, duracion, ItemType::ARMA, precio), bonusAtk(bonusAtk) {}

void armas::usar(heroes* h) {
    cout << h->getNombre() << " ha equipado un arma con +" << bonusAtk << " ATK.\n";

}

int armas::getbonusAtk() const {
    return bonusAtk;
}

items* armas::clonar() const {
    return new armas(*this);
}
