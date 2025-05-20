#ifndef ARMADURA_H
#define ARMADURA_H
#include "items.h"
class armadura : public items {
private:
    int resistencia;
public:
    armadura(string nombre, string descripcion, int duracion, int resistencia);
    void usar(heroes* h) override;
    int getResistencia() const;
};

#endif //ARMADURA_H
