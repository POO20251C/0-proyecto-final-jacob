#include "items.h"

// Constructor
items::items(string nombre, string descripcion, int duracion, ItemType tipo)
    : nombre(nombre), descripcion(descripcion), duracion(duracion), tipo(tipo) {}

// Destructor virtual (importante para polimorfismo)
items::~items() {}

// Getters
string items::getNombre() {
    return nombre;
}

string items::getDescripcion() {
    return descripcion;
}

ItemType items::getTipo() {
    return tipo;
}

int items::getDuracion() {
    return duracion;
}


