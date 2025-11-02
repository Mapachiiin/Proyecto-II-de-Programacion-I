#include "ListaSucursales.h"
#include "NodoSucursal.h"

ListaSucursales::ListaSucursales(): inicio(nullptr), tam(0) {}
ListaSucursales::~ListaSucursales(){
	NodoSucursal* actual = inicio;
	while (actual) {
		NodoSucursal* siguiente = actual->getSiguiente();
		delete actual;
		actual = siguiente;
	}
	inicio = nullptr;
	tam = 0;
}
void ListaSucursales::agregarSucursal(Sucursal* s){
	if (!s) return;
	NodoSucursal* nuevo = new NodoSucursal(s);
	if (!inicio) inicio = nuevo;
	else{
		NodoSucursal* actual = inicio;
		while (actual->getSiguiente()) { actual = actual->getSiguiente(); }
		actual->setSiguiente(nuevo);
	}
	tam++;
}
bool ListaSucursales::eliminarSucursal(int numSucur){
	if (!inicio) return false;
	if (numSucur < 0) return false;

	NodoSucursal* actual = inicio;
	NodoSucursal* anterior = nullptr;

	while (actual) {
		if (actual->getSucursal()->getNumSucursal() == numSucur) break;
		anterior = actual;
		actual = actual->getSiguiente();
	}

	if (!actual) return false;

	if (!anterior) {
		inicio = actual->getSiguiente();
	} else {
		anterior->setSiguiente(actual->getSiguiente());
	}

	delete actual;
	tam--;
	return true;
}
void ListaSucursales::mostrarSucursales(){
	if (!inicio) {
		cout << "No hay sucursales disponibles." << endl;
		return;
	}
	NodoSucursal* actual = inicio;
	cout << "Lista de Sucursales:" << endl;
	while (actual) {
		cout << "Sucursal Numero: " << actual->getSucursal()->getNumSucursal() << endl;
		actual = actual->getSiguiente();
	}
}
Sucursal* ListaSucursales::obtenerSucursal(int numSucursal){
	if (!inicio) return nullptr;
	NodoSucursal* actual = inicio;
	while (actual) {
		if (actual->getSucursal()->getNumSucursal() == numSucursal) {
			return actual->getSucursal();
		}
		actual = actual->getSiguiente();
	}
	return nullptr;
}
int ListaSucursales::getTam() { return tam; }
bool ListaSucursales::existeSucursal(int numSucursal){
	if (!inicio) return false;
	NodoSucursal* actual = inicio;
	while (actual) {
		if (actual->getSucursal()->getNumSucursal() == numSucursal) {
			return true;
		}
		actual = actual->getSiguiente();
	}
	return false;
}