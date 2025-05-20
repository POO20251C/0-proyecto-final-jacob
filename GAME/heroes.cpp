#include "heroes.h"
#include <iostream>
using namespace std;

// Constructor
heroes::heroes(string nombre, int hp, int atk, int def, int spd, int lck, int dinero)
    : personajes(nombre, hp, atk, def, spd, lck), dinero(dinero) {}

// Equipar objetos
void heroes::equiparArma(items* arma) {
    this->arma = arma;
    cout << getNombre() << " ha equipado el arma: " << arma->getNombre() << endl;
}

void heroes::equiparArmadura(items* armadura) {
    this->armadura = armadura;
    cout << getNombre() << " ha equipado la armadura: " << armadura->getNombre() << endl;
}

void heroes::equiparPociones(items* pociones) {
    this->pociones = pociones;
    cout << getNombre() << " ha añadido pociones: " << pociones->getNombre() << endl;
}

// Usar poción
void heroes::usarPocion() {
    if (pociones) {
        curarse(20); // Valor arbitrario, puedes ajustar según `impact` o `modificadores`
        cout << getNombre() << " usó una poción." << endl;
        // Si es solo una poción desechable, puedes poner: pociones = nullptr;
    } else {
        cout << "No tienes pociones para usar." << endl;
    }
}

// Recibir daño (override)
void heroes::recibirDaño(int cantidad) {
    int reduccion = 0;
    if (armadura) {
        // Ejemplo: usar primer valor de impact para defensa extra
        reduccion = armadura->getTipo() == "armadura" ? 5 : 0;
    }
    int daño = cantidad - getDef() - reduccion;
    if (daño < 0) daño = 0;
    personajes::recibirDaño(daño);  // Usar función de la clase base
}

// Mostrar inventario
void heroes::mostrarInventario() const {
    cout << "Inventario de " << getNombre() << ":" << endl;
    for (size_t i = 0; i < inventario.size(); ++i) {
        cout << "- " << inventario[i]->getNombre() << endl;
    }
    if (inventario.empty()) {
        cout << "Inventario vacío." << endl;
    }
}

// Dinero
int heroes::getDinero() const {
    return dinero;
}

int heroes::ganarDinero() {
    int ganancia = rand() % 101 + 50; // entre 50 y 150
    dinero += ganancia;
    cout << getNombre() << " ganó " << ganancia << " de dinero." << endl;
    return ganancia;
}
