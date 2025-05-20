#ifndef DEMONIO_H
#define DEMONIO_H
#include "villanos.h"

class demonio : public villanos {
    demonio(string nombre,int hp, int atk, int def, VillainType tipo );
    void diff() override;
};
#endif //DEMONIO_H
