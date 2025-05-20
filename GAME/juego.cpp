#include "juego.h"
#include <iostream>
using namespace std;

// Método para iniciar el juego (resetear todo)
void juego::iniciarJuego() {
    cout << "=== Iniciando el juego ===" << endl;
    dungeon = new mazmorra();  // nueva mazmorra
    inventarioGeneral = inventario(); // reiniciar inventario (requiere constructor sin argumentos)
    equipo.clear(); // limpia el equipo actual
    cout << "¡Juego iniciado con éxito!" << endl;
}

// Método para seleccionar héroes (simple ejemplo de 2 héroes)
void juego::seleccionarHeroes() {
    cout << "Seleccionando héroes..." << endl;

    heroes* h1 = new heroes("Ares", 100, 20, 10, 5, 3, 100);
    heroes* h2 = new heroes("Athena", 90, 15, 12, 6, 5, 120);

    equipo.push_back(h1);
    equipo.push_back(h2);

    cout << "Héroes seleccionados:" << endl;
    for (auto h : equipo) {
        h->mostrarStat();
    }
}

// Jugar mazmorra (avanza por salas y muestra progreso)
void juego::jugarMazmorra() {
    if (!dungeon) {
        cout << "Debes iniciar el juego primero." << endl;
        return;
    }

    while (!dungeon->esFinal()) {
        cout << "\nEstás en la sala " << dungeon->getSalaActual() << "." << endl;
        cout << "Simulando combate..." << endl;

        // Aquí se podría añadir combate real
        dungeon->avanzarSala();
    }

    cout << "¡Has completado la mazmorra!" << endl;
}

// Muestra menú principal (opcional aquí, usado en menu.cpp)
void juego::mostrarMenuPrincipal() {
    cout << "Bienvenido al juego de RPG por turnos." << endl;
}

// Guardar score (puede escribir en un archivo)
void juego::guardarScore() {
    ofstream archivo("score.txt", ios::app);
    if (!archivo) {
        cout << "Error al guardar el score." << endl;
        return;
    }

    archivo << "Score guardado: " << endl;
    for (auto h : equipo) {
        archivo << h->getNombre() << " - Dinero: " << h->getDinero() << endl;
    }

    archivo.close();
    cout << "Puntaje guardado en 'score.txt'." << endl;
}
