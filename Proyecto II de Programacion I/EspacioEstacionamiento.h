#pragma once
#include "Vehiculo.h"
#include <iostream>
using namespace std;

class EspacioEstacionamiento
	/*
	Cuando un veh�culo es alquilado deja disponible su espacio en el estacionamiento y cuando es devuelto, el sistema debe recomendar un lugar espec�fico para estacionar
el veh�culo que ingresa. El sistema debe recomendar primeramente el plantel de la sucursal con m�s espacios de estacionamiento disponibles. Una vez elegido el plantel,
el sistema debe recomendar los espacios de estacionamiento con menos veh�culos ubicados a su alrededor, esto con el objetivo de minimizar el riesgo de choques. El
sistema debe mostrar una vista grafica del plantel recomendado, por ejemplo: Para alquilar un veh�culo primeramente se genera una solicitud de alquiler. Cada
solicitud debe tener un c�digo o ID �nico, la identificaci�n del cliente, del colaborador responsable, de la sucursal, la placa del veh�culo, la cantidad de d�as
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

