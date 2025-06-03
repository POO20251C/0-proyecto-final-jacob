#include "pociones.h"
#include "heroes.h"

using namespace std;

pociones::pociones(const string& nombre, const string& descripcion, int efecto, int duracion, ItemType tipo, int precio)
    : items(nombre, descripcion, duracion, tipo, precio), efecto(efecto) {}


void pociones::usar(heroes* h) {
    if (getTipo() == ItemType::POCIONHP) {
        h->curarse(efecto);
    } else if (getTipo() == ItemType::POCIONATK) {
        h->aplicarBuffATK(efecto, getDuracion());
    }
    reducirDuracion();
}

int pociones::getEfecto() const {
    return efecto;
}

items* pociones::clonar() const {
    return new pociones(*this);
}


