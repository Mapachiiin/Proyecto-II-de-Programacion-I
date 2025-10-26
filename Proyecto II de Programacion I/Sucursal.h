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
Ingreso, eliminación y visualización de
Sucursales(2 pts)
Clientes por sucursal(2 pts)
Colaborares por sucursal(2 pts)

Cada sucursal tiene una cartera de clientes, un inventario de vehículos y un conjunto
de colaboradores.

Los vehículos se pueden eliminar del inventario de vehículos al cumplir su periodo
de vida útil, lo cual provocará que sean eliminados, tanto del plantel como del
estacionamiento en el que estaban. Nota: no se puede eliminar un vehículo el cual se
encuentra alquilado.

Es normal que las sucursales intercambien vehículos entre sí, por lo cual el sistema
debe permitirlo, obviamente no se pueden trasladar vehículos en alquiler.
Cada vez que un vehículo cambia de estado, el cambio se debe registrar en una bitácora
de estados del vehículo, la cual contiene todos sus estados anteriores. Cada entrada
de la bitácora debe tener el estado anterior, el estado actual, el empleado que
realizó el cambio y la fecha del cambio de estado. Esta bitácora puede crecer
“indefinidamente” para cada vehículo.

*/
