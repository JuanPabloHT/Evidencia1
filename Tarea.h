#ifndef TAREA_H
#define TAREA_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Tarea {
public:
    string descripcion;
    int prioridad;
    string fecha_entrega;
    Tarea* siguiente;

    Tarea(string desc, int pri, string fecha) 
        : descripcion(desc), prioridad(pri), fecha_entrega(fecha), siguiente(nullptr) {}
};

Tarea* dividirMitad(Tarea* cabeza);
Tarea* merge(Tarea* izquierda, Tarea* derecha);
Tarea* mergeSort(Tarea* cabeza);
int contarAltaPrioridad(Tarea* nodo);

class ListaEnlazadaTareas {
private:
    Tarea* cabeza;

public:
    ListaEnlazadaTareas() : cabeza(nullptr) {}

    void agregarTarea(string descripcion, int prioridad, string fecha_entrega) {
        Tarea* nueva_tarea = new Tarea(descripcion, prioridad, fecha_entrega);
        nueva_tarea->siguiente = cabeza;
        cabeza = nueva_tarea;
        cout << "Tarea agregada: " << descripcion << endl;
    }

    void eliminarTarea(string descripcion) {
        Tarea* actual = cabeza;
        Tarea* anterior = nullptr;
        while (actual != nullptr) {
            if (actual->descripcion == descripcion) {
                if (anterior != nullptr) {
                    anterior->siguiente = actual->siguiente;
                } else {
                    cabeza = actual->siguiente;
                }
                delete actual;
                cout << "Tarea eliminada: " << descripcion << endl;
                return;
            }
            anterior = actual;
            actual = actual->siguiente;
        }
        cout << "Tarea no encontrada: " << descripcion << endl;
    }

    void mostrarTareas() {
        Tarea* actual = cabeza;
        while (actual != nullptr) {
            cout << "Descripcion: " << actual->descripcion 
                 << ", Prioridad: " << actual->prioridad 
                 << ", Fecha de entrega: " << actual->fecha_entrega << endl;
            actual = actual->siguiente;
        }
    }

    Tarea* getCabeza() {
        return cabeza;
    }

    void setCabeza(Tarea* nuevaCabeza) {
        cabeza = nuevaCabeza;
    }

    Tarea* buscarPorDescripcion(string descripcion) {
        Tarea* actual = cabeza;
        while (actual != nullptr) {
            if (actual->descripcion == descripcion) {
                return actual;
            }
            actual = actual->siguiente;
        }
        return nullptr;
    }

    void ordenarPorPrioridad() {
        cabeza = mergeSort(cabeza);
        cout << "Tareas ordenadas por prioridad." << endl;
    }

    int contarTareasAltaPrioridad() {
        return contarAltaPrioridad(cabeza);
    }

    void guardarEnArchivo(const string& nombreArchivo) {
        ofstream archivo(nombreArchivo);

        if (!archivo) {
            cout << "No se pudo abrir el archivo para guardar las tareas." << endl;
            return;
        }

        Tarea* temp = cabeza;
        while (temp != nullptr) {
            archivo << temp->descripcion << "\n";
            archivo << temp->prioridad << "\n";
            archivo << temp->fecha_entrega << "\n";
            temp = temp->siguiente;
        }

        archivo.close();
        cout << "Tareas guardadas en el archivo " << nombreArchivo << endl;
    }

    void cargarDesdeArchivo(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);

        if (!archivo) {
            cout << "No se pudo abrir el archivo para cargar las tareas." << endl;
            return;
        }

        string descripcion;
        int prioridad;
        string fecha_entrega;

        while (getline(archivo, descripcion) && archivo >> prioridad >> ws && getline(archivo, fecha_entrega)) {
            agregarTarea(descripcion, prioridad, fecha_entrega);
        }

        archivo.close();
        cout << "Tareas cargadas desde el archivo " << nombreArchivo << endl;
    }
};

Tarea* mergeSort(Tarea* cabeza) {
    if (cabeza == nullptr || cabeza->siguiente == nullptr) {
        return cabeza;
    }
    Tarea* mitad = dividirMitad(cabeza);
    Tarea* izquierda = mergeSort(cabeza);
    Tarea* derecha = mergeSort(mitad);
    return merge(izquierda, derecha);
}

Tarea* dividirMitad(Tarea* cabeza) {
    Tarea* rapido = cabeza;
    Tarea* lento = cabeza;
    Tarea* anterior = nullptr;

    while (rapido != nullptr && rapido->siguiente != nullptr) {
        anterior = lento;
        lento = lento->siguiente;
        rapido = rapido->siguiente->siguiente;
    }

    if (anterior != nullptr) {
        anterior->siguiente = nullptr;
    }
    return lento;
}

Tarea* merge(Tarea* izquierda, Tarea* derecha) {
    if (!izquierda) return derecha;
    if (!derecha) return izquierda;

    if (izquierda->prioridad < derecha->prioridad) {
        izquierda->siguiente = merge(izquierda->siguiente, derecha);
        return izquierda;
    } else {
        derecha->siguiente = merge(izquierda, derecha->siguiente);
        return derecha;
    }
}

int contarAltaPrioridad(Tarea* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    if (nodo->prioridad == 1) {
        return 1 + contarAltaPrioridad(nodo->siguiente);
    } else {
        return contarAltaPrioridad(nodo->siguiente);
    }
}

#endif

