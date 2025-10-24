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
	void agregarCliente(Cliente* c);
	void mostrarClientes();
	void eliminarCliente(string cedula);
	void historialCliente(string cedula);
	void reporteClientesPorCantidadDeContratos();
};

