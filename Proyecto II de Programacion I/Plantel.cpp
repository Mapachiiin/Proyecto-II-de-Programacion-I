#include "Plantel.h"

Plantel::Plantel() : letra(' '), tipo(" "), capMax(0) {
	estacionamiento = new EspacioEstacionamiento(capMax); 
	listaVehiculos = new ListaVehiculos();
}

Plantel::Plantel(char letra, string tipo, int capMax) {
	this->letra = letra;
	this->tipo = tipo;
	this->capMax = capMax;
	estacionamiento = new EspacioEstacionamiento(capMax);
	listaVehiculos = new ListaVehiculos();
}
Plantel::~Plantel() {
	delete estacionamiento;
	delete listaVehiculos;
}
char Plantel::getLetra() { return letra; }
ListaVehiculos* Plantel::getListaVehiculos() { return listaVehiculos; }
string Plantel::getTipo() { return tipo; }
int Plantel::getCapMax() { return capMax; }
EspacioEstacionamiento* Plantel::getEstacionamiento() { return estacionamiento; }
