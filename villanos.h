#ifndef VILLANOS_H
#define VILLANOS_H
#include "personajes.h"
using namespace std;

enum class VillainType{DEMONIO, MINIBOSS,BOSS};

class villanos : public personajes{
    private:
        VillainType tipo;
    public:
        villanos(const string& nombre,int hp, int atk, int def,int spd, int lck, VillainType tipo );
        virtual ~villanos() = default;

        void atacar(personajes* obj);
        VillainType getTipo() const;
};

#endif //VILLANOS_H
