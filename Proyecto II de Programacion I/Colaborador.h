#pragma once
#include "Persona.h"
#include "Fecha.h"
class Colaborador:public Persona


{
private:
	Fecha* fechaIngre;
public:
	Colaborador(string ced, string nom, int dia, int mes, int annio);
	~Colaborador();
	string toString();
};
	/*
	 De los colaboradores se requiere saber su identificación, el nombre
y fecha de ingreso como empleado de la empresa.
	*/
