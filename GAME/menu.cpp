#include "menu.h"
using namespace std;

void menu::mostrarMenu() {
    int opcion;
    do {
        cout << "======================" << endl;
        cout << "    MENÚ PRINCIPAL    " << endl;
        cout << "======================" << endl;
        cout << "1. Iniciar juego" << endl;
        cout << "2. Seleccionar héroes" << endl;
        cout << "3. Jugar mazmorra" << endl;
        cout << "4. Ver inventario" << endl;
        cout << "5. Guardar puntaje" << endl;
        cout << "0. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                juegoPrincipal.iniciarJuego();
            break;
            case 2:
                juegoPrincipal.seleccionarHeroes();
            break;
            case 3:
                juegoPrincipal.jugarMazmorra();
            break;
            case 4:
                // Suponiendo que quieres mostrar el inventario general del juego
                    juegoPrincipal.getInventario().mostrarInventario();
            break;
            case 5:
                juegoPrincipal.guardarScore();
            break;
            case 0:
                cout << "Saliendo del juego..." << endl;
            break;
            default:
                cout << "Opción inválida. Intenta de nuevo." << endl;
            break;
        }

        cout << endl;

    } while (opcion != 0);
}
