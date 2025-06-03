#ifndef POSCIONES_H
#define POSCIONES_H
#include "items.h"

class pociones : public items {
private:
    int efecto;
public:
    pociones(const string& nombre, const string& descripcion, int efecto, int duracion, ItemType tipo, int precio);

    void usar(heroes* h) override;
    int getEfecto() const;
    items* clonar() const override;

};

#endif //POSCIONES_H
