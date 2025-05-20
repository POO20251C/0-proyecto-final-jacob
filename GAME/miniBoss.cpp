#include "miniBoss.h"
#include <iostream>
using namespace std;

// Constructor
miniBoss::miniBoss(string nombre, int hp, int atk, int def, VillainType tipo)
    : villanos(nombre, hp, atk, def, 4, 2, tipo) {
    // Velocidad y suerte fijadas. Puedes ajustarlas o convertirlas en parámetros si lo prefieres
}

// Implementación personalizada del método diff()
void miniBoss::diff() {
    cout << "⚔️ MINI JEFE: " << getNombre() << " entra en combate. ¡Cuidado con sus habilidades especiales!" << endl;
}
