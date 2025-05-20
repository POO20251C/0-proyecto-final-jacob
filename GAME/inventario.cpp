#include "inventario.h"
#include <iostream>
using namespace std;

// Constructor
inventario::inventario(vector<items*> items, int capmax)
    : items(items), capmax(capmax) {}

// Agrega un ítem si hay espacio
void inventario::agregarItem(items* item) {
    if ((int)items.size() >= capmax) {
        cout << "El inventario está lleno. No se puede agregar " << item->getNombre() << "." << endl;
        return;
    }
    items.push_back(item);
    cout << "Item agregado: " << item->getNombre() << endl;
}

// Elimina un ítem por índice
void inventario::eliminarItem(int index) {
    if (index < 0 || index >= (int)items.size()) {
        cout << "Índice inválido. No se puede eliminar." << endl;
        return;
    }
    cout << "Eliminando item: " << items[index]->getNombre() << endl;
    items.erase(items.begin() + index);
}

// Muestra todos los ítems
void inventario::mostrarInventario() const {
    cout << "\nInventario (" << items.size() << "/" << capmax << "):" << endl;
    if (items.empty()) {
        cout << "- Vacío -" << endl;
        return;
    }
    for (size_t i = 0; i < items.size(); ++i) {
        cout << i << ". " << items[i]->getNombre() << " - " << items[i]->getDescripcion() << endl;
    }
}

// Retorna cantidad de ítems
int inventario::getCantidad() const {
    return items.size();
}

// Retorna un ítem por índice
items* inventario::getItem(int index) const {
    if (index < 0 || index >= (int)items.size()) return nullptr;
    return items[index];
}
