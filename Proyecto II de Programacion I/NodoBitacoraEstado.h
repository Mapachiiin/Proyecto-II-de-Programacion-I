#pragma once
#include "BitacoraEstado.h"
class NodoBitacoraEstado
{
public:
	BitacoraEstado* dato;
	NodoBitacoraEstado* sig;
	NodoBitacoraEstado(BitacoraEstado* c);
};

