#ifndef MAZMORRA_H
#define MAZMORRA_H
using namespace std;

class mazmorra {
    private:
    int salaActual;
    int totalSalas = 10;

public:
    mazmorra();
    void avanzarSala();
    int getSalaActual() const;
    bool esFinal() const;

};



#endif //MAZMORRA_H
