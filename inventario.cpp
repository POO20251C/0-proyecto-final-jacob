#include "inventario.h"
#include <iostream>
using namespace std;

inventario::inventario(const vector<items*>& content, int capmax): content(content), capmax(capmax) {}



void inventario::agregarItem(items* item) {
    content.push_back(item);
}

void inventario::eliminarItem(int index) {
    if (index >= 0 && index < (int)content.size()) {
        delete content[index];
        content.erase(content.begin() + index);
    }
}

void inventario::mostrarInventario() const {
    cout << "\n--- Inventario ---\n";
    for (size_t i = 0; i < content.size(); ++i) {
        cout << i + 1 << ". " << content[i]->getNombre()
             << " - " << content[i]->getDescripcion() << endl;
    }
}

int inventario::getCantidad() const {
    return content.size();
}

items* inventario::getItem(int index) const {
    if (index >= 0 && index < (int)content.size()) {
        return content[index];
    }
    return nullptr;
}


