#include "ListaBitacorasEstado.h"
#include <iostream>
using namespace std;

ListaBitacorasEstado::ListaBitacorasEstado() : inicio(nullptr), tam(0) {}
ListaBitacorasEstado::~ListaBitacorasEstado() {
    NodoBitacoraEstado* actual = inicio;
    while (actual) {
        NodoBitacoraEstado* siguiente = actual->getNodoSig();
        delete actual; 
        actual = siguiente;
    }
    inicio = nullptr;
    tam = 0;
}

void ListaBitacorasEstado::agregarBitacora(int estAnt, int estNvo, Colaborador* c, Fecha* fCambio) {
    if (!c || !fCambio) return;
    BitacoraEstado* nuevaBitacora = new BitacoraEstado(estAnt, estNvo, c, fCambio);
    NodoBitacoraEstado* nuevoNodo = new NodoBitacoraEstado(nuevaBitacora);
    if (!inicio) {
        inicio = nuevoNodo;
    }
    else {
        NodoBitacoraEstado* actual = inicio;
        while (actual->getNodoSig()) {
            actual = actual->getNodoSig();
        }
        actual->setNodoSig(nuevoNodo);
    }
    tam++;
}

void ListaBitacorasEstado::mostrarBitacora() {
    if (!inicio) {
        cout << "No hay registros en la bitacora de este vehiculo." << endl;
        return;
    }

    cout << "\n Bitacora " << endl;
    cout << "Cambios totales en los estados del vehiculo: " << tam << endl << endl;

    NodoBitacoraEstado* actual = inicio;
    int cont = 1;

    while (actual) {
        cout << "--- Cambio #" << cont << " ---" << endl;
        cout << actual->getDato()->toString() << endl;
        actual = actual->getNodoSig();
        cont++;
    }
    cout << "-------------------------" << endl;
}


bool ListaBitacorasEstado::estaVacia() { return (inicio == nullptr);}
int ListaBitacorasEstado::getTam() { return tam;}