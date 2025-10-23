#pragma once
#include "NodoSoliyContra.h"
class ListaSolicitudes
{
private:
	NodoSoliyContra* inicio;
	int tam;

public:
	ListaSolicitudes();
	~ListaSolicitudes();
	void agregarSolicitud(SoliAlquiyContra* s);
	void eliminarSolicitud(string codigo);
};

