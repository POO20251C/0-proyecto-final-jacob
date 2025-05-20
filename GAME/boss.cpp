#include "boss.h"
#include <iostream>
using namespace std;

// Constructor
boss::boss(string nombre, int hp, int atk, int def, VillainType tipo)
    : villanos(nombre, hp, atk, def, 5, 3, tipo) {
    // Se pueden ajustar valores fijos como velocidad (5) y suerte (3), o convertirlos en parámetros si prefieres
}

// Override del método diff para el jefe
void boss::diff() {
    cout << "⚠️ JEFE FINAL: " << getNombre() << " ha aparecido. Prepárate para la batalla definitiva." << endl;
}
