#pragma once
#include <string>
#include "ListaColaboradores.h"
#include "ListaPlanteles.h"
#include "ListaSolisyContras.h"
#include "ListaClientes.h"
using namespace std;

class Sucursal
{
private:
	int numSucursal;
	ListaPlanteles* planteles;
	ListaSolisyContras* solicitudes;
	ListaClientes* clientes;
	ListaColaboradores* colaboradores;
public:
	Sucursal();
	~Sucursal();
	int getNumSucursal();
	void agregarPlantel(Plantel* p);
	void eliminarPlantel(string letra);
	void agregarSolicitud(SoliAlquiyContra* s);
	void agregarCliente(Cliente* c);
	void eliminarCliente(string cedula);
	void agregarColaborador(Colaborador* c);
	void eliminarColaborador(string cedula);

};

/*
Ingreso, eliminaci�n y visualizaci�n de
Sucursales(2 pts)
Clientes por sucursal(2 pts)
Colaborares por sucursal(2 pts)

Cada sucursal tiene una cartera de clientes, un inventario de veh�culos y un conjunto
de colaboradores.

Los veh�culos se pueden eliminar del inventario de veh�culos al cumplir su periodo
de vida �til, lo cual provocar� que sean eliminados, tanto del plantel como del
estacionamiento en el que estaban. Nota: no se puede eliminar un veh�culo el cual se
encuentra alquilado.

Es normal que las sucursales intercambien veh�culos entre s�, por lo cual el sistema
debe permitirlo, obviamente no se pueden trasladar veh�culos en alquiler.
Cada vez que un veh�culo cambia de estado, el cambio se debe registrar en una bit�cora
de estados del veh�culo, la cual contiene todos sus estados anteriores. Cada entrada
de la bit�cora debe tener el estado anterior, el estado actual, el empleado que
realiz� el cambio y la fecha del cambio de estado. Esta bit�cora puede crecer
�indefinidamente� para cada veh�culo.

*/
