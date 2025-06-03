#include "personajes.h"
#include <iostream>
using namespace std;

personajes::personajes(const string& nombre, int hp, int atk, int def, int spd, int lck)
    : nombre(nombre), hp(hp), atk(atk), def(def), spd(spd), lck(lck) {}

void personajes::setNombre() {
    cout << "Ingrese el nuevo nombre: ";
    cin >> nombre;
}

string personajes::getNombre() const {
    return nombre;
}

int personajes::getHP() const {
    return hp;
}

int personajes::getAtk() const {
    return atk;
}

int personajes::getDef() const {
    return def;
}

int personajes::getSpd() const {
    return spd;
}

int personajes::getLck() const {
    return lck;
}

void personajes::recibirDaño(int cantidad) {
    hp -= cantidad;
    if (hp < 0) hp = 0;

}

void personajes::curarse(int cantidad) {
    hp += cantidad;
    if (hp > 100) hp = 100;
    cout << nombre << " se curó " << cantidad << " puntos. HP actual: " << hp << "\n";
}

void personajes::resetHP() {
    cout << "[resetHP] No hay valor de HP máximo definido.\n";
}

void personajes::mostrarStat() const {
    cout << "--- Estadísticas de " << nombre << " ---\n";
    cout << "HP:  " << hp << "\n";
    cout << "ATK: " << atk << "\n";
    cout << "DEF: " << def << "\n";
    cout << "SPD: " << spd << "\n";
    cout << "LCK: " << lck << "\n";
}



