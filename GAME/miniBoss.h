#ifndef MINIBOSS_H
#define MINIBOSS_H
#include "villanos.h"

class miniBoss: public villanos {
    public:
    miniBoss(string nombre,int hp, int atk, int def, VillainType tipo );
    void diff() override;
};



#endif //MINIBOSS_H
