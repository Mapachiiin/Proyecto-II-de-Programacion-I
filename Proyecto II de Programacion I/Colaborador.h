#pragma once
#include "Persona.h"
#include "Fecha.h"
class Colaborador:public Persona {
private:
	Fecha* fechaIngre;
public:
	Colaborador(string ced, string nom, Fecha* fecha);
	~Colaborador();
	string toString();
};
