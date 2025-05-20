#include "mazmorra.h"
#include <iostream>
using namespace std;

// Constructor: inicia en la primera sala
mazmorra::mazmorra() : salaActual(1) {}

// Avanza a la siguiente sala (si no está en la última)
void mazmorra::avanzarSala() {
    if (!esFinal()) {
        salaActual++;
        cout << "Has avanzado a la sala " << salaActual << "." << endl;
    } else {
        cout << "¡Ya estás en la sala final!" << endl;
    }
}

// Obtener sala actual
int mazmorra::getSalaActual() const {
    return salaActual;
}

// Verifica si se llegó al final de la mazmorra
bool mazmorra::esFinal() const {
    return salaActual >= totalSalas;
}
