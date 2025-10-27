#pragma once
#include "ListaSucursales.h"
#include "Control.h"
#include "Sucursal.h"
#include "Colaborador.h"
#include "Cliente.h"
#include "Vehiculo.h"
#include "Plantel.h"
#include "SoliAlquiyContra.h"
#include "Quemados.h"
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
	void submenuSolicitudesYContratos(Sucursal* s);



};

