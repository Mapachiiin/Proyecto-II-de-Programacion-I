#pragma once
#include "NodoColaborador.h"

class ListaColaboradores
{
private:
	NodoColaborador* inicio;
	int tam;
public:
	ListaColaboradores();
	~ListaColaboradores();
	void agregarColaborador(Colaborador* c);
	bool eliminarColaborador(string cedula);
	void mostrarColaboradores();
	void reportesAlquilerPorColaboradores();
};

