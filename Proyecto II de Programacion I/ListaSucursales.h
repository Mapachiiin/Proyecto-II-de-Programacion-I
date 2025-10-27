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
	bool eliminarSucursal(int numSucur);
	void mostrarSucursales();
	Sucursal* obtenerSucursal(int numSucursal);
};

