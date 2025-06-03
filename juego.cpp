#include "juego.h"
#include <iostream>
#include "descanso.h"

using namespace std;

juego::juego()
    : inventarioGeneral({}, 50), dungeon(nullptr) {}

vector<string> juego::ambientes() const {
    return {
        "La Cripta de Uldor", "Bosque de los Susurros", "Arenas de Arrakis", "Catacumbas de Valyria",
        "Cumbres de Angmar", "Llanuras de Rhûn", "Fortaleza de Karsakh", "Gruta de Morghul",
        "Torre de Erebos", "Abismo de Skorn", "El Corazón de la Tormenta"
    };
}

void juego::iniciarJuego() {
    seleccionarHeroes();
    dungeon = new mazmorra();
    jugarMazmorra();
}

void juego::seleccionarHeroes() {
    auto opciones = heroes::opcHeroes();
    cout << "Selecciona 3 héroes para tu equipo:\n";
    for (size_t i = 0; i < opciones.size(); ++i) {
        cout << i + 1 << ") " << opciones[i]->getNombre() << " [HP: " << opciones[i]->getHP()
             << ", ATK: " << opciones[i]->getAtk() << ", DEF: " << opciones[i]->getDef() << "]\n";
    }
    while (equipo.size() < 3) {
        int seleccion;
        cout << "Héroe #" << equipo.size() + 1 << ": ";
        cin >> seleccion;
        if (seleccion >= 1 && seleccion <= (int)opciones.size()) {
            equipo.push_back(opciones[seleccion - 1]);
        } else {
            cout << "Selección inválida. Intenta de nuevo.\n";
        }
    }
}

void juego::jugarMazmorra() {
    vector<string> ambientess = ambientes();
    int ambienteIndex = 0;

    while (!dungeon->esFinal()) {
        cout << "\n=== Entorno: " << ambientess[ambienteIndex++] << " ===\n";

        villanos* enemigo = dungeon->enemigoActual();
        cout << "Enemigo: " << enemigo->getNombre() << " [HP: " << enemigo->getHP() << "]\n";

        while (enemigo->getHP() > 0) {
            for (heroes* h : equipo) {
                if (!h->alive() || enemigo->getHP() <= 0) continue;

                cout << "\n=========================\n";
                cout << "Turno de " << h->getNombre() << ":\n";
                cout << "1. Atacar\n2. Usar Poción\n3. Ver Inventario\n4. Usar ítem del Inventario\n";

                int opcion;
                cin >> opcion;

                if (opcion == 1) {
                    // === HÉROE ===
                    cout << "\n========= HÉROE =========\n";
                    if (h->getNombre() == "Guerrero") {
                        cout << h->getNombre() << " lanza una poderosa estocada con su hoja sagrada.\n";
                    } else if (h->getNombre() == "Mago") {
                        cout << h->getNombre() << " conjura un rayo ígneo que rompe el aire con un estallido.\n";
                    } else if (h->getNombre() == "Arquero") {
                        cout << h->getNombre() << " suelta una flecha encantada que silba a través del campo.\n";
                    } else {
                        cout << h->getNombre() << " ataca con destreza.\n";
                    }

                    int ataques = 1;
                    if (h->getSpd() > enemigo->getSpd()) {
                        ataques = 2;
                    } else if (h->getSpd() == enemigo->getSpd()) {
                        ataques = 1;
                    }

                    for (int i = 0; i < ataques; ++i) {
                        int dano = h->getAtk() - enemigo->getDef();
                        if (dano < 0) dano = 0;

                        if (i == 1) {
                            cout << h->getNombre() << " se mueve con agilidad mística, desatando un segundo golpe antes de que el enemigo pueda reaccionar.\n";
                        }

                        enemigo->recibirDaño(dano);
                        int hpActual = h->getHP();
                        cout << h->getNombre() << " recibió " << dano << " de daño. ";
                        if (!h->alive()) {
                            cout << "⚔️ " << h->getNombre() << " ha caído en combate...\n";
                        } else if (hpActual <= 25) {
                            cout << "⚠️ ¡" << h->getNombre() << " está gravemente herido! HP restante: " << hpActual << "\n";
                        } else {
                            cout << "HP restante: " << hpActual << "\n";
                        }


                        if (enemigo->getHP() <= 0) break;
                        else if (opcion == 4) {
                            h->mostrarInventario();
                            cout << "Selecciona el índice del ítem para usar: ";
                            int idx;
                            cin >> idx;
                            h->usarItemInventario(idx);  // Debes tener esta función en la clase `heroes`
                        }


                    }


                    cout << "\n========= VILLANO =========\n";

                    bool esquiva = false;
                    int diferencia = h->getLck() - enemigo->getLck();

                    if (diferencia > 0) {
                        int probabilidad = min(50, diferencia * 10); // Máximo 50% de evasión
                        int suerte = rand() % 100;
                        if (suerte < probabilidad) {
                            esquiva = true;
                            cout << h->getNombre() << " esquiva el ataque gracias a su aguda suerte (" << probabilidad << "% de probabilidad).\n";
                        }
                    }


                    int ataquesVillano = (enemigo->getSpd() > h->getSpd()) ? 2 : 1;


                    if (!esquiva) {
                        for (int i = 0; i < ataquesVillano; ++i) {
                            if (i == 1) {
                                cout << enemigo->getNombre() << " acelera con furia, descargando un segundo golpe cubierto en sombras.\n";
                            } else {
                                cout << enemigo->getNombre() << " contraataca con ferocidad...\n";
                            }
                            cout << h->getNombre() << " tenía " << h->getHP() << " HP.\n";

                            enemigo->atacar(h);

                        }
                    }



                    cout << "\n=========================\n";
                    h->avanzarTurno();
                }
                else if (opcion == 2) {
                    h->usarPocion();
                }
                else if (opcion == 3) {
                    h->mostrarInventario();
                } else {
                    cout << "Opción inválida.\n";
                }
            }
        }

        cout << "\n¡Has vencido a " << enemigo->getNombre() << "!\n";

        int recompensa = 10;
        if (enemigo->getTipo() == VillainType::MINIBOSS) recompensa += 5;
        else if (enemigo->getTipo() == VillainType::BOSS) recompensa = 0;

        for (heroes* h : equipo) {
            if (h->alive()) {
                h->ganarDinero(recompensa);
                if (recompensa > 0)
                    cout << h->getNombre() << " recibe " << recompensa << " monedas.\n";
            }
        }

        if (enemigo->getTipo() == VillainType::BOSS) {
            cout << "\nCon un rugido que estremeció la tierra, el Señor del Caos cae...\n";
            cout << "\"Tu voluntad ha quebrado la oscuridad. No solo sobreviviste... Eres ahora el más fuerte de esta tierra.\"\n";
            cout << "La calma retorna a un mundo que había olvidado la esperanza.\n";
        }

        if (enemigo->getTipo() != VillainType::BOSS) {
            cout << "\nHas alcanzado un punto de descanso.\n";
            AreaDescanso::mostrarOpciones(equipo, inventarioGeneral, tiendA);
        }

        dungeon->avanzarSala();
    }
    cout << "\n¡Felicidades! Has superado todas las salas.\n";
}

void juego::loot() {
    int recompensa = 50;
    for (heroes* h : equipo) {
        if (h->alive()) {
            h->ganarDinero(recompensa);
            cout << h->getNombre() << " recibió " << recompensa << " monedas.\n";
        }
    }
}

void juego::avanzarTurno() {
    for (heroes* h : equipo) {
        h->avanzarTurno();
    }
}

inventario& juego::getInventario() {
    return inventarioGeneral;
}

juego::~juego() {
    delete dungeon;
    for (heroes* h : equipo) {
        delete h;
    }
}
