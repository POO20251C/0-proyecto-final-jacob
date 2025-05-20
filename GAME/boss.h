#ifndef BOSS_H
#define BOSS_H
#include "villanos.h"

class boss : public villanos {
    public:
    boss(string nombre,int hp, int atk, int def, VillainType tipo );
    void diff() override;
};



#endif //BOSS_H
