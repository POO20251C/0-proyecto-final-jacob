#include "villanos.h"
#include <iostream>
using namespace std;

villanos::villanos(const string& nombre, int hp, int atk, int def, int spd, int lck, VillainType tipo)
    : personajes(nombre, hp, atk, def, spd, 0), tipo(tipo) {}

void villanos::atacar(personajes* obj) {
    int dano = getAtk() - obj->getDef();
    if (dano < 0) dano = 0;
    obj->recibirDaño(dano);
    cout << getNombre() << " ataca causando " << dano << " de daño.\n";
}

VillainType villanos::getTipo() const {
    return tipo;
}
