#ifndef ITEMS_H
#define ITEMS_H
#include <bits/stdc++.h>
#include "heroes.h"
using namespace std;

enum class ItemType {ARMA, AMRADURA, POCIONATK, POCIONHP};

class items {
private:
    string nombre;
    string descripcion;
    int duracion;
    ItemType tipo;
public:
    items(string nombre, string descripcion, int duracion, ItemType tipo);
    virtual ~items();

    string getNombre();
    string getDescripcion();
    ItemType getTipo();
    int getDuracion();

    virtual void usar(heroes* h) = 0;
};

#endif //ITEMS_H
