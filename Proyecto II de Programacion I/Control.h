#pragma once
#include "ListaSucursales.h"
#include "Control.h"
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
    void eliminarSucursal();
    void mostrarSucursales();
    //menus y sub menus
    void menuPrincipal();
	void subMenuSucursales();
    void subMenuColaboradores();
	void subMenuClientes();
	void subMenuVehiculosyPlanteles();
	void submenuSolicitudesYContratos();



};

