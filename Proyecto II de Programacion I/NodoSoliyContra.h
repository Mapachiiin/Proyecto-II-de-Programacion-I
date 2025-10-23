#pragma once
#include "SoliAlquiyContra.h"
class NodoSoliyContra
{
private:
	SoliAlquiyContra* dato;
	NodoSoliyContra* sig;
public:
	NodoSoliyContra(SoliAlquiyContra* c);
	~NodoSoliyContra();
	void setDato();
	SoliAlquiyContra* getDato();
	void setNodoSig();
	NodoSoliyContra* getNodoSig();
};

