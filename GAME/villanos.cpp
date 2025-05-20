#include "villanos.h"
#include <iostream>
using namespace std;

villanos::villanos(string nombre, int hp, int atk, int def, int spd, int lck, VillainType tipo)
    : personajes(nombre, hp, atk, def, spd, lck), tipo(tipo) {}

void villanos::diff() {
    cout << "Tipo de villano: ";
    switch (tipo) {
        case VillainType::DEMONIO:
            cout << "Demonio" << endl;
        break;
        case VillainType::MINIBOSS:
            cout << "Mini Jefe" << endl;
        break;
        case VillainType::BOSS:
            cout << "Jefe Final" << endl;
        break;
    }
}

VillainType villanos::getTipo() const {
    return tipo;
}
