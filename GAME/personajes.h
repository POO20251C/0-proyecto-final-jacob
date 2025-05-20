#ifndef PERSONAJES_H
#define PERSONAJES_H
#include <bits/stdc++.h>

#include "villanos.h"
using namespace std;
class personajes {
    private:
        string nombre;
        int hp;
        int atk;
        int def;
        int spd;
        int lck;

    public:
        personajes(string nombre, int hp, int atk, int def,int spd, int lck);
        void setNombre();
        string getNombre() const;
        int getHP() const;
        int getAtk() const;
        int getDef() const;
        int getSpd() const;
        int getLck() const;


        void recibirDaño(int cantidad);
        void curarse(int cantidad);
        void resetHP();
        void mostrarStat() const;
};

#endif //PERSONAJES_H
