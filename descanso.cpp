#include "descanso.h"
#include <iostream>
using namespace std;

void AreaDescanso::mostrarOpciones(vector<heroes*>& equipo, inventario& inv, tienda& t){
     curarEquipo(equipo);

    int opcion;
    do {
        cout << "\n--- Área de Descanso ---\n";
        cout << "1. Ver inventario\n";
        cout << "2. Ir a tienda\n";
        cout << "3. Continuar a la siguiente mazmorra\n";
        cout << "4. Equipar ítems del inventario\n";

        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                inv.mostrarInventario();
            break;
            case 2:
                t.mostrarProductos(equipo, inv);



            break;
            case 3:
                cout << "Saliendo del área de descanso...\n";
            break;
            

            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 3);
}


void AreaDescanso::curarEquipo(vector<heroes*>& equipo) {
    for (heroes* h : equipo) {
        h->curarse(100);
    }
    cout << "Todos los héroes han sido curados automáticamente al llegar al área de descanso.\n";
}
