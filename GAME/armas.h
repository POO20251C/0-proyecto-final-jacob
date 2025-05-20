#ifndef ARMAS_H
#define ARMAS_H
#include "items.h"
class armas : public items {
private:
    int bonusAtk;
public:
    armas(string nombre, string descripcion, int duracion, int bonusAtk);
    void usar(heroes* h) override;
    int getbonusAtk() const;
};

#endif //ARMAS_H
