#ifndef HEROES_H
#define HEROES_H
#include "personajes.h"

class items;

class heroes : public personajes {
private:
    int dinero;
    vector<items*> inventario;
    items* arma = nullptr;
    items* armadura = nullptr;
    items* pociones = nullptr;

    int buffATK = 0;
    int buffATKduracion = 0;

public:
    heroes(const string& nombre,int hp,int atk, int def,int spd, int lck,int dinero);

    void equiparArma(items* arma);
    void equiparArmadura(items* armadura);
    void equiparPociones(items* pociones);

    void usarPocion();
    void recibirDaño(int cantidad) override;

    void mostrarInventario() const;

    int getDinero() const;
    int ganarDinero(int cantidad);

    void atacar(personajes* enemigo);
    bool alive();
    static vector<heroes*>opcHeroes();

    void aplicarBuffATK(int cantidad, int duracion);
    void avanzarTurno() const ;
    void gastarDinero(int cantidad);
    void agregarAlInventario(items* nuevo);
    void usarItemInventario(int index);  // en heroes.h



};

#endif //HEROES_H
