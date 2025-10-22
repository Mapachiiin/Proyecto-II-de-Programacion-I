#pragma once
#include "Vehiculo.h"
class NodoVehiculo
{
public:
	Vehiculo* dato;
	NodoVehiculo* sig;
	NodoVehiculo(Vehiculo* c);
};

