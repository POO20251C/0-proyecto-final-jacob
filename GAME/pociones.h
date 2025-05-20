#ifndef POSCIONES_H
#define POSCIONES_H
#include "items.h"

class posciones : public items {
private:
    int efecto;
public:
    posciones(string nombre, string descripcion,int efecto, int duracion, ItemType tipo);
    void usar(heroes* h) override;
    int getEfecto() const;
};

#endif //POSCIONES_H
