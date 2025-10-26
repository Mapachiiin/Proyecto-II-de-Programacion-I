#pragma once
#include "NodoVehiculo.h"
#include "EspacioEstacionamiento.h"
#include "Colaborador.h"

class ListaVehiculos
{
private: 
	NodoVehiculo* inicio;
	int tam;
public:
	ListaVehiculos();
	~ListaVehiculos();
	void agregarVehiculo(Vehiculo* v);
	void mostrarVehiculo(Vehiculo* v);
	void cambioEstadoVehiculo(string placa, int nuevoEstado, Colaborador* c, Fecha* fA);
	double reporteDePorcentajeDeOcupacionDelPlantel(EspacioEstacionamiento* espacios);
	void trasladoVehiculoEntreSucursales(string placa, ListaVehiculos* destino);
	bool eliminarVehiculo(string placa);
};

