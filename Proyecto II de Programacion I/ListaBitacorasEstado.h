#pragma once
#include "NodoBitacoraEstado.h"

class ListaBitacorasEstado
{
private:
	NodoBitacoraEstado* inicio;
	int tam;
public:
	ListaBitacorasEstado();
	~ListaBitacorasEstado();
	void agregarBitacora(int estado, Colaborador* c, Fecha* fAtc);
};

