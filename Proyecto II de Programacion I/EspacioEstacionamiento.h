#pragma once
#include "Vehiculo.h"
#include <iostream>
using namespace std;

class EspacioEstacionamiento
	/*
	Cuando un vehículo es alquilado deja disponible su espacio en el estacionamiento y cuando es devuelto, el sistema debe recomendar un lugar específico para estacionar
el vehículo que ingresa. El sistema debe recomendar primeramente el plantel de la sucursal con más espacios de estacionamiento disponibles. Una vez elegido el plantel,
el sistema debe recomendar los espacios de estacionamiento con menos vehículos ubicados a su alrededor, esto con el objetivo de minimizar el riesgo de choques. El
sistema debe mostrar una vista grafica del plantel recomendado, por ejemplo: Para alquilar un vehículo primeramente se genera una solicitud de alquiler. Cada
solicitud debe tener un código o ID único, la identificación del cliente, del colaborador responsable, de la sucursal, la placa del vehículo, la cantidad de días
Espacios de estacionamiento
recomendados: Donde al rededor hay la menor cantidad de vehiculos
Nota: El sistema recomienda
y el usuario decide el espacio de estacionamiento por asignar. */
{
private:
	Vehiculo*** espacios;
	int nF, nC;
public:
	EspacioEstacionamiento(int capMax);
	~EspacioEstacionamiento();
	string espacioRecomendado();
	int cambiarVehiculoDeEspacio(Vehiculo* v, int posVieja, int posNueva);
	int obtenerFilaVehiculo(Vehiculo* v);
	int obtenerColumnaVehiculo(Vehiculo* v);
	int getCapMax();
	int getnF();
	int getnC();
	bool estaOcupado(int nF, int nC);
	int contarEspaciosVacios();
	void eliminarVehiAlquilado(Vehiculo* elimi);
	bool esPrimo(int num);
	bool agregarVehiculoEnEspacio(Vehiculo* v, int nF, int nC);
};

