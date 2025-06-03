#include "heroes.h"
#include "items.h"
#include <iostream>
using namespace std;

heroes::heroes(const string& nombre, int hp, int atk, int def, int spd, int lck, int dinero)
    : personajes(nombre, hp, atk, def, spd, lck), dinero(dinero) {}



void heroes::equiparArma(items* arma) {
    this->arma = arma;
    cout << getNombre() << " ha equipado un arma." << endl;
    arma->usar(this);
}

void heroes::equiparArmadura(items* armadura) {
    this->armadura = armadura;
    cout << getNombre() << " ha equipado una armadura." << endl;
    armadura->usar(this);
}

void heroes::equiparPociones(items* pociones) {
    this->pociones = pociones;
    cout << getNombre() << " ha guardado una poción." << endl;
}

void heroes::usarPocion() {
    if (pociones != nullptr) {
        pociones->usar(this);
        delete pociones;
        pociones = nullptr;
    } else {
        cout << getNombre() << " no tiene ninguna poción equipada.\n";
    }
}

void heroes::recibirDaño(int cantidad) {
    personajes::recibirDaño(cantidad);
}

void heroes::mostrarInventario() const {
    cout << "Inventario de " << getNombre() << ":\n";
    for (size_t i = 0; i < inventario.size(); ++i) {
        cout << i + 1 << ". " << inventario[i]->getNombre() << endl;
    }
}

int heroes::getDinero() const {
    return dinero;
}

int heroes::ganarDinero(int cantidad) {
    dinero += cantidad;
    return dinero;
}

void heroes::atacar(personajes* enemigo) {
    int dano = getAtk() - enemigo->getDef();
    if (dano < 0) dano = 0;
    enemigo->recibirDaño(dano);
    cout << getNombre() << " ataca causando " << dano << " de daño.\n";
}

bool heroes::alive() {
    return getHP() > 0;
}

vector<heroes*> heroes::opcHeroes() {
    vector<heroes*> opciones;
    opciones.push_back(new heroes("Guerrero", 100, 20, 15, 5, 3, 0));
    opciones.push_back(new heroes("Mago", 100, 25, 10, 6, 5, 0));
    opciones.push_back(new heroes("Arquero", 100, 18, 12, 7, 4, 0));
    opciones.push_back(new heroes("Paladin", 100, 17, 18, 6, 4, 0));
    opciones.push_back(new heroes("Asesino", 100, 22, 8, 7, 3, 0));
    opciones.push_back(new heroes("Monje", 100, 19, 14, 4, 4, 0));
    return opciones;
}

void heroes::avanzarTurno() const {
    cout << getNombre() << " ha avanzado un turno.\n";
}

void heroes::aplicarBuffATK(int cantidad, int duracion) {
    buffATK = cantidad;
    buffATKduracion = duracion;
    cout << getNombre() << " ha ganado +" << cantidad << " ATK por " << duracion << " turnos.\n";
}

void heroes::gastarDinero(int cantidad) {
    dinero -= cantidad;
    if (dinero < 0) dinero = 0;
}

void heroes::agregarAlInventario(items* nuevo) {
    inventario.push_back(nuevo);
}

void heroes::usarItemInventario(int index) {
    if (index >= 0 && index < (int)inventario.size()) {
        inventario[index]->usar(this);
        if (inventario[index]->getDuracion() <= 0) {
            delete inventario[index];
            inventario.erase(inventario.begin() + index);
        }
    } else {
        cout << "Índice inválido.\n";
    }
}

