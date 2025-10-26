#include "Plantel.h"

Plantel::Plantel() : letra(' '), tipo(" "), capMax(0) { estacionamiento = new EspacioEstacionamiento(capMax); }

Plantel::Plantel(char letra, string tipo, int capMax) {
	this->letra = letra;
	this->tipo = tipo;
	this->capMax = capMax;
	estacionamiento = new EspacioEstacionamiento(capMax);
}

Plantel::~Plantel() {
	delete estacionamiento;
}

char Plantel::getLetra() { return letra; }
string Plantel::getTipo() { return tipo; }
int Plantel::getCapMax() { return capMax; }
EspacioEstacionamiento* Plantel::getEstacionamiento() { return estacionamiento; }
