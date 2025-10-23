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
	void setDato();
	Colaborador* getDato();
	void setNodoSig();
	NodoColaborador* getNodoSig();
};

