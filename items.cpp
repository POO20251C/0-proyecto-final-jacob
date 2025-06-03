#include "tienda.h"
#include <iostream>
using namespace std;

#include "items.h"

items::items(const std::string& nombre, const std::string& descripcion, int precio, ItemType tipo, int duracion)
    : nombre(nombre), descripcion(descripcion), precio(precio), tipo(tipo), duracion(duracion) {}

items::~items() = default;

std::string items::getNombre() const {
    return nombre;
}

std::string items::getDescripcion() const {
    return descripcion;
}

int items::getPrecio() const {
    return precio;
}

ItemType items::getTipo() const {
    return tipo;
}

int items::getDuracion() const {
    return duracion;
}

void items::reducirDuracion() {
    if (duracion > 0) duracion--;
}

