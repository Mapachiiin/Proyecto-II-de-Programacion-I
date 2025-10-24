#pragma once
#include "Vehiculo.h"
class NodoVehiculo
{
private:
	Vehiculo* dato;
	NodoVehiculo* sig;
public:
	NodoVehiculo(Vehiculo* c);
	~NodoVehiculo();
	void setDato(Vehiculo* v);
	Vehiculo* getDato();
	void setNodoSig(NodoVehiculo* n);
	NodoVehiculo* getNodoSig();
};

