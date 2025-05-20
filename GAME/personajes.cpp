#include "personajes.h"

// Constructor
personajes::personajes(string nombre, int hp, int atk, int def, int spd, int lck)
    : nombre(nombre), hp(hp), atk(atk), def(def), spd(spd), lck(lck) {}

// Setter (aunque no tiene parámetro, normalmente se esperaría uno)
void personajes::setNombre() {
    cout << "Nuevo nombre: ";
    cin >> nombre;
}

// Getters
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

// Recibir daño (considera defensa)
void personajes::recibirDaño(int cantidad) {
    int daño = cantidad - def;
    if (daño < 0) daño = 0;
    hp -= daño;
    if (hp < 0) hp = 0;
    cout << nombre << " recibió " << daño << " de daño. HP actual: " << hp << endl;
}

// Curarse
void personajes::curarse(int cantidad) {
    hp += cantidad;
    cout << nombre << " se curó " << cantidad << ". HP actual: " << hp << endl;
}

// Reiniciar HP (por defecto a 100, puedes ajustar si deseas mantener hp base original)
void personajes::resetHP() {
    hp = 100;
    cout << nombre << " ha recuperado su HP al máximo (100)." << endl;
}

// Mostrar estadísticas del personaje
void personajes::mostrarStat() const {
    cout << "==== " << nombre << " ====" << endl;
    cout << "HP: " << hp << endl;
    cout << "ATK: " << atk << endl;
    cout << "DEF: " << def << endl;
    cout << "SPD: " << spd << endl;
    cout << "LCK: " << lck << endl;
    cout << "===================" << endl;
}


