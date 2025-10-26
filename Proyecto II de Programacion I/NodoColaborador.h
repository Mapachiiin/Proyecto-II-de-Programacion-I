#pragma once
#include "Colaborador.h"
class NodoColaborador
{
private:
	Colaborador* dato;
	NodoColaborador* sig;
public:
	NodoColaborador(Colaborador* c);
	~NodoColaborador();
	void setDato(Colaborador* c);
	Colaborador* getDato();
	void setNodoSig(NodoColaborador* n);
	NodoColaborador* getNodoSig();
};

