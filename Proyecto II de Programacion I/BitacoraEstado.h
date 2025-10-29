#pragma once
#include "Colaborador.h"
#include "Fecha.h"
#include <string>
using namespace std;

class BitacoraEstado
{
private:
	string bitaco;
public:
	BitacoraEstado(int estado, Colaborador* c, Fecha* fAtc);
	~BitacoraEstado();
	void setBita(string esta);
	string bitacora();
};

