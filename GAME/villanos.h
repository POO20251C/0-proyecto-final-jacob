#ifndef VILLANOS_H
#define VILLANOS_H
#include <bits/stdc++.h>
#include "personajes.h"
using namespace std;

enum class VillainType{DEMONIO, MINIBOSS,BOSS};

class villanos : public personajes{
    private:
    VillainType tipo;
    public:
    villanos(string nombre,int hp, int atk, int def,int spd, int lck, VillainType tipo );
    virtual void diff();
    VillainType getTipo() const;
};

#endif //VILLANOS_H
