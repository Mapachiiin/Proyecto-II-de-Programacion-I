#pragma once
#include "Cliente.h"

class NodoCliente
{
public:
	Cliente* dato;
	NodoCliente* sig;
	NodoCliente(Cliente* c);
};
