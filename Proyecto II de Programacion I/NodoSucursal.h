#pragma once
#include "Sucursal.h"
class NodoSucursal
{
private:
	Sucursal* sucursal;
	NodoSucursal* siguiente;
public:
	NodoSucursal(Sucursal* s);
	~NodoSucursal();
	Sucursal* getSucursal();
	void setSucursal(Sucursal* s);
	NodoSucursal* getSiguiente();
	void setSiguiente(NodoSucursal* sig);
};

