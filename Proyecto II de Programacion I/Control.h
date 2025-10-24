#pragma once
#include "ListaSucursales.h"
class Control
{
private:
    ListaSucursales* listaSucursales;
public:
    Control();
    ~Control();
    void agregarSucursal(const Sucursal& sucursal);
    void eliminarSucursal(int id);
    void mostrarSucursales();
    //menus y sub menus
    void menuPrincipal();
	void subMenuSucursales();
    void subMenuColaboradores();
	void subMenuClientes();
	void subMenuVehiculosyPlanteles();
	void submenuSolicitudesYContratos();



};

