#include "NodoVehiculo.h"

NodoVehiculo::NodoVehiculo(Vehiculo* c) : dato(c), sig(nullptr) {}
NodoVehiculo::~NodoVehiculo(){}
void NodoVehiculo::setDato(Vehiculo* d) { dato = d; }
Vehiculo* NodoVehiculo::getDato() { return dato; }
void NodoVehiculo::setNodoSig(NodoVehiculo* s) { sig = s; }
NodoVehiculo* NodoVehiculo::getNodoSig() { return sig; }
void NodoVehiculo::soltarDato() { dato = nullptr; }