#pragma once
#include "NodoSucursal.h"
class ListaSucursales
{
private:
	NodoSucursal* inicio;
	int tam;
public:
	ListaSucursales();
	~ListaSucursales();
	void agregarSucursal(Sucursal* s);
	int getTam();
	bool eliminarSucursal(int numSucur);
	void mostrarSucursales();
	Sucursal* obtenerSucursal(int numSucursal);
	bool existeSucursal(int numSucursal);
};

