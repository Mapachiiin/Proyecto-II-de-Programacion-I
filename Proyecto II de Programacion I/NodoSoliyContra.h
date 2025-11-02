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
	void soltarDato();
	void setDato(SoliAlquiyContra* c);
	SoliAlquiyContra* getDato();
	void setNodoSig(NodoSoliyContra* sig);
	NodoSoliyContra* getNodoSig();
};