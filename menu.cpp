#include "menu.h"
#include <iostream>
using namespace std;

menu::menu() : juegoPrincipal() {
    cout << "=============================\n";
    cout << "  ¡Bienvenido a Mazmorra RPG!\n";
    cout << "=============================\n\n";
}

void menu::mostrarMenu() {
    int opcion;
    do {
        cout << "1. Iniciar juego\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                juegoPrincipal.iniciarJuego();
            break;
            case 0:
                cout << "Gracias por jugar. ¡Hasta pronto!\n";
            break;
            default:
                cout << "Opción inválida. Intenta de nuevo.\n";
            break;
        }

        cout << endl;
    } while (opcion != 0);
}
