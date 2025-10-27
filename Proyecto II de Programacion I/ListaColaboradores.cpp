#include "ListaColaboradores.h"
ListaColaboradores::ListaColaboradores() : inicio(nullptr), tam(0) {}
ListaColaboradores::~ListaColaboradores(){
	while (inicio) {
		NodoColaborador* temp = inicio;
		inicio = inicio->getNodoSig();
		delete temp;
	}
}
bool ListaColaboradores::agregarColaborador(Colaborador* c){
	if (!c) return false;
	NodoColaborador* nuevo = new NodoColaborador(c);
	if (!inicio) {
		inicio = nuevo;
		tam++;
		return true;
	}
	else {
		NodoColaborador* actual = inicio;
		while (actual->getNodoSig()) {
			actual = actual->getNodoSig();
		}
		actual->setNodoSig(nuevo);
		tam++;
	}
	return true;
}
#include "ListaColaboradores.h"
#include "NodoColaborador.h"
#include <iostream>

using namespace std;

ListaColaboradores::ListaColaboradores() : inicio(nullptr), tam(0) {}
ListaColaboradores::~ListaColaboradores() {
    if (!inicio) return;
    NodoColaborador* actual = inicio;
    NodoColaborador* siguiente = nullptr;
    while (actual) {
        siguiente = actual->getNodoSig();
        delete actual;
        actual = siguiente;
    }
}
bool ListaColaboradores::agregarColaborador(Colaborador* c) {
    if (!c) return;
    NodoColaborador* nuevo = new NodoColaborador(c);
    if (!inicio) {
        inicio = nuevo;
        tam++;
    }
    else {
        NodoColaborador* actual = inicio;
        while (actual->getNodoSig()) {
            actual = actual->getNodoSig();
        }
        actual->setNodoSig(nuevo);
        tam++;
    }
}
Colaborador* ListaColaboradores::buscarColaboradorPorCed(string cedula) {
    NodoColaborador* actual = inicio;
    while (actual) {
        if (actual->getDato() && actual->getDato()->getCedula() == cedula) {
            return actual->getDato();
        }
        actual = actual->getNodoSig();
    }
    return nullptr;
}

bool ListaColaboradores::eliminarColaborador(string cedula) {
    if (!inicio) return false;

    if (inicio->getDato() && inicio->getDato()->getCedula() == cedula) {
        NodoColaborador* temp = inicio;
        inicio = inicio->getNodoSig();
        delete temp;
        tam--;
        return true;
    }

    NodoColaborador* actual = inicio->getNodoSig();
    NodoColaborador* anterior = inicio;

    while (actual) {
        if (actual->getDato() && actual->getDato()->getCedula() == cedula) {
            anterior->setNodoSig(actual->getNodoSig());
            delete actual;  
            tam--;
            return true;
        }
        anterior = actual;
        actual = actual->getNodoSig();
    }

    return false;
}
void ListaColaboradores::mostrarColaboradores() {
    if (!inicio) {
        cout << "No hay colaboradores en la lista." << endl;
        return;
    }
    NodoColaborador* actual = inicio;
    while (actual) {
        if (actual->getDato()) {
            cout << "Colaborador: " << actual->getDato()->getNombre() << ", Cedula: " << actual->getDato()->getCedula() << endl;
        }
        actual = actual->getNodoSig();
    }
}
