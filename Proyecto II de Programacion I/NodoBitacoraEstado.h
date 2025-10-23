#pragma once
#include "BitacoraEstado.h"
class NodoBitacoraEstado
{
private:
	BitacoraEstado* dato;
	NodoBitacoraEstado* sig;
public:
	NodoBitacoraEstado(BitacoraEstado* c);
	~NodoBitacoraEstado();
	void setDato();
	BitacoraEstado* getDato();
	void setNodoSig();
	NodoBitacoraEstado* getNodoSig();
};

