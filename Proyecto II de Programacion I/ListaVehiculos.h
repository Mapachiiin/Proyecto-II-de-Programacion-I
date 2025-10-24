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
	void mostrarVehiculo(Vehiculo* v);
	void reasignarVehiculo(Vehiculo* v, ListaVehiculos* destino);
	void cambioEstadoVehiculo(string placa, string nuevoEstado, Colaborador* c);
	double reporteDePorcentajeDeOcupacionDelPlantel(EspacioEstacionamiento* espacios);
	void trasladoVehiculoEntreSucursales(string placa, ListaVehiculos* destino);
	void eliminarVehiculo(string placa);
};

