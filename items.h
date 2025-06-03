#ifndef ITEMS_H
#define ITEMS_H
#include <bits/stdc++.h>
#include "heroes.h"
using namespace std;
class heroes;

enum class ItemType {ARMA, ARMADURA, POCIONATK, POCIONHP};

class items {
protected:
    string nombre;
    string descripcion;
    int duracion;
    ItemType tipo;
    int precio;

public:
    items(const string& nombre, const string& descripcion, int duracion, ItemType tipo, int precio);
    virtual ~items();
    virtual items* clonar() const = 0;

    virtual void usar(heroes* h) = 0;
    int getPrecio() const;

    string getNombre() const;
    string getDescripcion() const;
    ItemType getTipo() const;
    int getDuracion() const;


    void reducirDuracion();

};

#endif //ITEMS_H
