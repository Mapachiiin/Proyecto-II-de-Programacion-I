#include "NodoSucursal.h"

NodoSucursal::NodoSucursal(Sucursal* s) :sucursal(s), siguiente(nullptr) {}
NodoSucursal::~NodoSucursal() {
	delete sucursal;
	sucursal = nullptr;
	siguiente = nullptr;
}
Sucursal* NodoSucursal::getSucursal() { return sucursal; }
void NodoSucursal::setSucursal(Sucursal* s) { this->sucursal = s; }
NodoSucursal* NodoSucursal::getSiguiente() { return siguiente; }
void NodoSucursal::setSiguiente(NodoSucursal* sig) { this->siguiente = sig; }