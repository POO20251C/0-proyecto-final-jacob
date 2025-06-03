#ifndef ARMADURA_H
#define ARMADURA_H
#include "items.h"
class armadura : public items {
private:
    int resistencia;
public:
    armadura(const string& nombre, const string& descripcion, int duracion,int precio, int resistencia);
    void usar(heroes* h) override;
    int getResistencia() const;
    items* clonar() const override;

};

#endif //ARMADURA_H
