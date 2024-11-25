#include <iostream>
#include <string>
#include "Tarea.h"

using namespace std;

void mostrarMenu() {
    cout << "\n--- Menú de Tareas ---" << endl;
    cout << "1. Agregar tarea" << endl;
    cout << "2. Eliminar tarea" << endl;
    cout << "3. Mostrar tareas" << endl;
    cout << "4. Ordenar tareas por prioridad" << endl;
    cout << "5. Contar tareas de alta prioridad" << endl;
    cout << "6. Guardar tareas en archivo" << endl;
    cout << "7. Cargar tareas desde archivo" << endl;
    cout << "8. Salir" << endl;
    cout << "Elija una opción: ";
}

int main() {
    ListaEnlazadaTareas listaTareas;
    int opcion;
    string descripcion;
    int prioridad;
    string fecha_entrega;
    string nombreArchivo = "tareas.txt";

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();  

        switch (opcion) {
            case 1: 
                cout << "Descripción de la tarea: ";
                getline(cin, descripcion);
                cout << "Prioridad (1 - alta, 2 - media, 3 - baja): ";
                cin >> prioridad;
                cin.ignore(); 
                cout << "Fecha de entrega (dd/mm/yyyy): ";
                getline(cin, fecha_entrega);
                listaTareas.agregarTarea(descripcion, prioridad, fecha_entrega);
                break;

            case 2: 
                cout << "Descripción de la tarea a eliminar: ";
                getline(cin, descripcion);
                listaTareas.eliminarTarea(descripcion);
                break;

            case 3: 
                cout << "\n------ Tareas actuales ------" << endl;
                listaTareas.mostrarTareas();
                break;

            case 4: 
                listaTareas.ordenarPorPrioridad();
                break;

            case 5: 
                cout << "Número de tareas de alta prioridad: " << listaTareas.contarTareasAltaPrioridad() << endl;
                break;

            case 6: 
                listaTareas.guardarEnArchivo(nombreArchivo);
                break;

            case 7: 
                listaTareas.cargarDesdeArchivo(nombreArchivo);
                break;

            case 8: 
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opción no valida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 8);

    return 0;
}


