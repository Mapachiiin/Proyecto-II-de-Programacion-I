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
	void soltarDato();
	void setDato(Cliente* c);
	Cliente* getDato();
	void setNodoSig(NodoCliente* n);
	NodoCliente* getNodoSig();
};
