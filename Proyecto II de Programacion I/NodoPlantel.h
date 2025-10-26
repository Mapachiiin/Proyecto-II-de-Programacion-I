#pragma once
#include "Plantel.h"

class NodoPlantel
{
private:
	Plantel* dato;
	NodoPlantel* sig;
public:
	NodoPlantel(Plantel* dato);
	~NodoPlantel();
	void setDato(Plantel* dato);
	Plantel* getDato();
	void setNodoSig(NodoPlantel* sig);
	NodoPlantel* getNodoSig();
};

