#pragma once
#include "NodoVehiculo.h"
class ListaVehiculos
{
private: 
	NodoVehiculo* inicio;
	int tam;
public:
	ListaVehiculos();
	~ListaVehiculos();
	void agregarVehiculo(Vehiculo* v);
	void eliminarVehiculo(string placa);
};

