#include "ListaClientes.h"

ListaClientes::ListaClientes() : inicio(nullptr), tam(0) {}
NodoCliente* ListaClientes::getInicio() { return inicio; }
ListaClientes::~ListaClientes() {
	if (!inicio) return;
	NodoCliente* actual = inicio;
	NodoCliente* siguiente = actual->getNodoSig();
	while (actual) {
		if (siguiente) {
			delete actual;
			actual = siguiente;
			siguiente = actual->getNodoSig();
		}
		else {
			delete actual;
			actual = nullptr;
		}
	}
}
void ListaClientes::agregarCliente(Cliente* c){
	if (!c) return;
	NodoCliente* nuevo = new NodoCliente(c);
	if (!inicio) {
		inicio = nuevo;
		tam++;
	}
	else {
		NodoCliente* actual = inicio;
		while (actual->getNodoSig()) {
			actual = actual->getNodoSig();
		}
		actual->setNodoSig(nuevo);
		tam++;
	}
}
void ListaClientes::mostrarClientes(){
if (!inicio) return;
	NodoCliente* actual = inicio;
	while (actual) {
		if (actual->getDato()) {
			cout << "Cliente: " << actual->getDato()->getNombre() << " | Cedula: " << actual->getDato()->getCedula() << endl;
		}
		actual = actual->getNodoSig();
	}
}
bool ListaClientes::eliminarCliente(string cedula){
	if (!inicio) return false;
	if(inicio->getDato()->getCedula() == cedula){
		NodoCliente* aEliminar = inicio;
		inicio = inicio->getNodoSig();
		delete aEliminar;
		tam--;
		return true;
	}
	NodoCliente* actual = inicio;
	NodoCliente* anterior = nullptr;
	while (actual) {
		if (actual->getDato()->getCedula() == cedula) {
			if (anterior) {
				anterior->setNodoSig(actual->getNodoSig());
			}
			delete actual;
			tam--;
			return true;
		}
		anterior = actual;
		actual = actual->getNodoSig();
	}
	return false;
}
Cliente* ListaClientes::buscarClientePorCedula(string cedula) {
	if (!inicio) return nullptr;
	NodoCliente* actual = inicio;
	while (actual) {
		if (actual->getDato()->getCedula() == cedula) {
			return actual->getDato();
		}
		actual = actual->getNodoSig();
	}
	return nullptr;
}
