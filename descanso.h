#ifndef DESCANSO_H
#define DESCANSO_H

#include "heroes.h"
#include "inventario.h"
#include "tienda.h"
#include <vector>
using namespace std;

class AreaDescanso {
public:
    static void mostrarOpciones(vector<heroes*>& equipo, inventario& inv, tienda& t);

    static void curarEquipo(vector<heroes*>& equipo);
};

#endif // DESCANSO_H
