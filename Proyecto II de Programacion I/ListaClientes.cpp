#include "ListaClientes.h"
#include "NodoCliente.h"

ListaClientes::ListaClientes() : inicio(nullptr), tam(0) {}
NodoCliente* ListaClientes::getInicio() { return inicio; }
ListaClientes::~ListaClientes() {
	NodoCliente* actual = inicio;
	while (actual) {
		NodoCliente* siguiente = actual->getNodoSig();
		delete actual;
		actual = siguiente;
	}
	inicio = nullptr;
	tam = 0;
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
			if(actual->getDato()->getActiEco()==" "){
			cout << "Cliente: " << actual->getDato()->getNombre() << " | Cedula: " << actual->getDato()->getCedula() << endl;
			}
			else {
			cout << "Cliente: " << actual->getDato()->getNombre() << " | Cedula: " << actual->getDato()->getCedula() << "| Actividad economica: "<< actual->getDato()->getActiEco() <<" con un descuento de " << actual->getDato()->getDescuento()<< "%" << endl;
			}
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
bool ListaClientes::eliminarNodoSinDelete(string cedula) {
	if (!inicio) return false;
	NodoCliente* actual = inicio;
	NodoCliente* anterior = nullptr;
	while (actual) {
		if (actual->getDato()->getCedula() == cedula) {
			if (anterior) {
				anterior->setNodoSig(actual->getNodoSig());
			}
			else {
				inicio = actual->getNodoSig();
			}
			actual->soltarDato();
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
int ListaClientes::getTam() { return tam; }
