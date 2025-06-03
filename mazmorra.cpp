#include "mazmorra.h"

using namespace std;

mazmorra::mazmorra() : salaActual(0), totalSalas(10) {
    generarMazmorra();
}

void mazmorra::generarMazmorra() {
    srand(time(0));
    for (int sala = 0; sala < totalSalas; ++sala) {
        if (sala == 9) {
            enemigos.push_back(new villanos("Señor del Caos Eterno", 150, 38, 25, 15, 6, VillainType::BOSS));
        } else if (sala == 4) {
            enemigos.push_back(new villanos("Súcubo del Abismo", 90, 20, 30, 16, 6, VillainType::MINIBOSS));
        } else if (sala == 7) {
            enemigos.push_back(new villanos("Guardia del Trono Caído", 80, 28, 22, 8, 6, VillainType::MINIBOSS));
        } else if (sala == 8) {
            enemigos.push_back(new villanos("Espíritu del Laberinto", 85, 21, 25, 10, 8, VillainType::MINIBOSS));
        } else {
            // Demonios comunes
            int tipo = rand() % 4;
            switch (tipo) {
                case 0:
                    enemigos.push_back(new villanos("Demonio de Fuego", 60, 20, 15, 8, 8, VillainType::DEMONIO));
                break;
                case 1:
                    enemigos.push_back(new villanos("Sombra Infernal", 55, 27, 16, 7, 5, VillainType::DEMONIO));
                break;
                case 2:
                    enemigos.push_back(new villanos("Alma Maldita", 65, 24, 14, 16, 7, VillainType::DEMONIO));
                break;
                case 3:
                    enemigos.push_back(new villanos("Bestia del Vacío", 70, 15, 14, 6, 6, VillainType::DEMONIO));
                break;
            }
        }
    }
}

void mazmorra::avanzarSala() {
    if (!esFinal()) salaActual++;
}

int mazmorra::getSalaActual() const {
    return salaActual;
}

bool mazmorra::esFinal() const {
    return salaActual >= totalSalas;
}

villanos* mazmorra::enemigoActual() const {
    if (salaActual < (int)enemigos.size()) {
        return enemigos[salaActual];
    }
    return nullptr;
}
