#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <bits/stdc++.h>
#include "items.h"
using namespace std;

class inventario {
private:
    vector<items*> content;
    int capmax = 50;
public:
    inventario(const vector<items*>& content, int capmax)
;
    void agregarItem(items* item);
    void eliminarItem(int index);
    void mostrarInventario() const;
    int getCantidad() const;
    items* getItem(int index) const;


};



#endif //INVENTARIO_H
