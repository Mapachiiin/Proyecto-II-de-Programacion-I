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
	void eliminarSucursal(int numSucur);
};

