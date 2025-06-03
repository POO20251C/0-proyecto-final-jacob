#include "tienda.h"
#include <iostream>
using namespace std;

tienda::tienda() {
    // Agregar armas
    armasDisponibles.push_back(new armas("Espada de Bronce", "Arma básica", 3, 10, 5));
    armasDisponibles.push_back(new armas("Espada de Acero", "Más poderosa", 5, 20, 10));

    // Agregar armaduras
    armadurasDisponibles.push_back(new armadura("Armadura de Cuero", "Ligera", 3, 5, 3));
    armadurasDisponibles.push_back(new armadura("Armadura de Hierro", "Resistente", 13, 0, 7));

    // Agregar pociones
    pocionesDisponibles.push_back(new pociones("Poción de Vida", "Cura 30 HP", 30, 1, ItemType::POCIONHP, 50));
    pocionesDisponibles.push_back(new pociones("Poción de Furia", "+5 ATK por 3 turnos", 5, 3, ItemType::POCIONATK, 70));
}
void tienda::mostrarProductos(vector<heroes*>& equipo, inventario& inv) {
    int opcion;
    do {
        cout << "\n--- Tienda ---\n";
        cout << "Armas disponibles:\n";
        for (size_t i = 0; i < armasDisponibles.size(); ++i) {
            cout << i + 1 << ") " << armasDisponibles[i]->getNombre() << " - " << armasDisponibles[i]->getPrecio() << " monedas\n";
        }
        cout << "Armaduras disponibles:\n";
        for (size_t i = 0; i < armadurasDisponibles.size(); ++i) {
            cout << i + 1 + armasDisponibles.size() << ") " << armadurasDisponibles[i]->getNombre() << " - " << armadurasDisponibles[i]->getPrecio() << " monedas\n";
        }
        cout << "Pociones disponibles:\n";
        for (size_t i = 0; i < pocionesDisponibles.size(); ++i) {
            cout << i + 1 + armasDisponibles.size() + armadurasDisponibles.size() << ") " << pocionesDisponibles[i]->getNombre() << " - " << pocionesDisponibles[i]->getPrecio() << " monedas\n";
        }

        cout << "0) Salir de la tienda\n";
        cout << "Seleccione un ítem para comprar: ";
        cin >> opcion;

        if (opcion == 0) break;

        int totalItems = armasDisponibles.size() + armadurasDisponibles.size() + pocionesDisponibles.size();

        if (opcion < 1 || opcion > totalItems) {
            cout << "Opción inválida.\n";
            continue;
        }

        items* seleccionado = nullptr;

        if (opcion <= (int)armasDisponibles.size()) {
            seleccionado = armasDisponibles[opcion - 1];
        } else if (opcion <= (int)(armasDisponibles.size() + armadurasDisponibles.size())) {
            int idx = opcion - armasDisponibles.size() - 1;
            seleccionado = armadurasDisponibles[idx];
        } else {
            int idx = opcion - armasDisponibles.size() - armadurasDisponibles.size() - 1;
            seleccionado = pocionesDisponibles[idx];
        }

        // Elegir héroe que va a pagar
        cout << "\n¿Con qué héroe deseas pagar?\n";
        for (size_t i = 0; i < equipo.size(); ++i) {
            cout << i + 1 << ") " << equipo[i]->getNombre() << " - Dinero: " << equipo[i]->getDinero() << "\n";
        }
        int heroeIndex;
        cin >> heroeIndex;

        if (heroeIndex < 1 || heroeIndex > (int)equipo.size()) {
            cout << "Índice de héroe inválido.\n";
            continue;
        }

        heroes* comprador = equipo[heroeIndex - 1];

        if (comprador->getDinero() >= seleccionado->getPrecio()) {
            comprador->gastarDinero(seleccionado->getPrecio());
            inv.agregarItem(seleccionado->clonar());
            cout << comprador->getNombre() << " ha comprado " << seleccionado->getNombre() << " exitosamente.\n";
        } else {
            cout << comprador->getNombre() << " no tiene suficiente dinero.\n";
        }

    } while (true);
}

void tienda::comprarArma(heroes* h, int indice) {
    if (indice >= 0 && indice < (int)armasDisponibles.size()) {
        h->equiparArma(armasDisponibles[indice]);
    }
}

void tienda::comprarArmadura(heroes* h, int indice) {
    if (indice >= 0 && indice < (int)armadurasDisponibles.size()) {
        h->equiparArmadura(armadurasDisponibles[indice]);
    }
}

void tienda::comprarPocion(heroes* h, int indice) {
    if (indice >= 0 && indice < (int)pocionesDisponibles.size()) {
        h->equiparPociones(pocionesDisponibles[indice]);
    }
}

const vector<armas*>& tienda::getArmas() const {
    return armasDisponibles;
}

const vector<armadura*>& tienda::getArmaduras() const {
    return armadurasDisponibles;
}

const vector<pociones*>& tienda::getPociones() const {
    return pocionesDisponibles;
}

