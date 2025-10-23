#pragma once
#include "Cliente.h"

class NodoCliente
{
private:
	Cliente* dato;
	NodoCliente* sig;
public:
	NodoCliente(Cliente* c);
	~NodoCliente();
	void setDato();
	Cliente* getDato();
	void setNodoSig();
	NodoCliente* getNodoSig();
};
