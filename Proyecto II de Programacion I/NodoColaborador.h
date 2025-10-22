#pragma once
#include "Colaborador.h"
class NodoColaborador
{
public:
	Colaborador* dato;
	NodoColaborador* sig;
	NodoColaborador(Colaborador* c);
};

