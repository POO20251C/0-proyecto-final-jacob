#ifndef HEROES_H
#define HEROES_H
#include "items.h"
#include "personajes.h"

class heroes : public personajes {
    private:
    int dinero;
    vector<items*> inventario;
    items* arma = nullptr;
    items* armadura = nullptr;
    items* pociones = nullptr;
    public:
    heroes(string nombre,int hp,int atk, int def,int spd, int lck,int dinero);
    void equiparArma(items* arma);
    void equiparArmadura(items* armadura);
    void equiparPociones(items* pociones);

    void usarPocion();
    virtual void recibirDaño(int cantidad) override;

    void mostrarInventario() const;

    int getDinero() const;
    int ganarDinero();
};

#endif //HEROES_H
