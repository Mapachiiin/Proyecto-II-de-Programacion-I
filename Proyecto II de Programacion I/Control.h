#pragma once
#include "ListaSucursales.h"
#include "Sucursal.h"
#include "Colaborador.h"
#include "Cliente.h"
#include "Vehiculo.h"
#include "Plantel.h"
#include "SoliAlquiyContra.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Control
{
private:
    ListaSucursales* listaSucursales;
public:
    Control();
    ~Control();
    void agregarSucursal();
    bool eliminarSucursal(int numSucursal);
    void mostrarSucursales();
    //menus y sub menus
    void menuPrincipal();
	void subMenuSucursales(int numSucursal);
    void subMenuColaboradores(Sucursal* s);
	void subMenuClientes(Sucursal* s);
    void subMenuVehiculosyPlanteles(Sucursal* s);
	//void submenuSolicitudesYContratos(Sucursal* s);

	//Funciones para no hacer mis switch tan largos :D
	void funcionAgregarPlantel(Sucursal* s);
	void funcionAgregarVehiculo(Sucursal* s); 
    void funcionEliminarVehiculo(Sucursal* s);
    void funcionVisualizacionVehiculo(Sucursal* s);
	void funcionReubicarVehiculo(Sucursal* s);
	void funcionCambioEstadoVehiculo(Sucursal* s);
	void funcionEstadosVehiculo(Sucursal* s);
	void funcionPorcentajeOcupacionPlanteles(Sucursal* s);
	void funcionTrasladoVehiculosEntreSucursales(Sucursal* s);


};

