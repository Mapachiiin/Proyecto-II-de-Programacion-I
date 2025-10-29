#pragma once
#include "NodoBitacoraEstado.h"
#include "Colaborador.h"
#include "Fecha.h"

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
