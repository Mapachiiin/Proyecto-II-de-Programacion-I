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
	void mostrarVehiculosSimple();
	void mostrarVehiculosDetallados();
	bool buscarVehiculoPorPlaca(string placa);
	Vehiculo* obtenerVehiculoPorPlaca(string placa);
	void cambioEstadoVehiculo(string placa, int nuevoEstado, Colaborador* c, Fecha* fA);
	void trasladoVehiculoEntreSucursales(string placa, ListaVehiculos* destino);
	bool eliminarVehiculo(string placa);
};

