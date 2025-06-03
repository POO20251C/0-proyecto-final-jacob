#ifndef ARMAS_H
#define ARMAS_H
#include "items.h"
class armas : public items {
private:
    int bonusAtk;
public:
    armas(const string& nombre, const string& descripcion, int duracion, int precio, int bonusAtk);
    void usar(heroes* h) override;
    int getbonusAtk() const;
    items* clonar() const override;

};

#endif //ARMAS_H
