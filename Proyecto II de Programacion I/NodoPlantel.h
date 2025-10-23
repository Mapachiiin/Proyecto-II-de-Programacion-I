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
	void setDato();
	Plantel getDato();
	void setNodoSig();
	NodoPlantel* getNodoSig();
};

