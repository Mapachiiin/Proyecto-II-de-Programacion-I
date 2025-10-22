#pragma once
#include "ContratoAlquiler.h"
class NodoContrato
{
public:
	ContratoAlquiler* dato;
	NodoContrato* sig;
	NodoContrato(ContratoAlquiler* c);
};

