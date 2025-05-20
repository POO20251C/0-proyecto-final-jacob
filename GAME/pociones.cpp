#include "pociones.h"
#include <iostream>
using namespace std;

// Constructor
posciones::posciones(string nombre, string descripcion, int efecto, int duracion, ItemType tipo)
    : items(nombre, descripcion, duracion, tipo), efecto(efecto) {}

// Método usar (aplica efecto según el tipo de poción)
void posciones::usar(heroes* h) {
    switch (getTipo()) {
        case ItemType::POCIONHP:
            h->curarse(efecto);
        cout << h->getNombre() << " usó una poción de HP y recuperó " << efecto << " puntos de vida." << endl;
        break;

        case ItemType::POCIONATK:
            // Aumenta el ataque temporalmente (por simplicidad, se puede hacer permanente si no hay sistema de turnos)
                cout << h->getNombre() << " usó una poción de ataque. (Aumento temporal de " << efecto << " ATK no implementado aún)" << endl;
        break;

        default:
            cout << "Este ítem no es una poción válida para usar." << endl;
        break;
    }
}

// Getter del efecto
int posciones::getEfecto() const {
    return efecto;
}
