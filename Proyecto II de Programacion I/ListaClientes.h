#pragma once
#include "NodoCliente.h"
class ListaClientes
{
private:
	NodoCliente* inicio;
	int tam;
public:
	ListaClientes();
	~ListaClientes();
	NodoCliente* getInicio();
	void agregarCliente(Cliente* c);
	void mostrarClientes();
	bool eliminarCliente(string cedula);
	Cliente* buscarClientePorCedula(string cedula);
};

