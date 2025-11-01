#include "ListaColaboradores.h"
#include "NodoColaborador.h"
#include <iostream>
using namespace std;

ListaColaboradores::ListaColaboradores() : inicio(nullptr), tam(0) {}
ListaColaboradores::~ListaColaboradores(){
    NodoColaborador* actual = inicio;
	while (actual) {
		NodoColaborador* temp = actual->getNodoSig();
		delete actual;
        actual = temp;
	}
    inicio = nullptr;
    tam = 0;
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
int ListaColaboradores::getTam() { return tam; }
