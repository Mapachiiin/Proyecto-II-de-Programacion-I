#pragma once
#include "NodoColaborador.h"
#include <string>
using namespace std;

class ListaColaboradores
{
private:
	NodoColaborador* inicio;
	int tam;
public:
	ListaColaboradores();
	~ListaColaboradores();
	int getTam();
	bool agregarColaborador(Colaborador* c);
	Colaborador* buscarColaboradorPorCed(string cedula);
	bool eliminarColaborador(string cedula);
	void mostrarColaboradores();
};

