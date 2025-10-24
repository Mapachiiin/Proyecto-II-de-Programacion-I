#pragma once
#include "Persona.h"
class Cliente : public Persona 

	/*
	
	La empresa atiende a dos tipos de cliente: personas físicas y personas jurídicas.
Para ambos se requiere saber la identificación, el nombre y su país de residencia.
En el caso de los clientes de tipo persona jurídica se requiere saber además su
actividad económica (texto) y el porcentaje de descuento que se le aplica a la empresa
(no todas las personas jurídicas tienen el mismo descuento).

	*/
{
private:
	string paisResi;
	string actiEco;
	double descuento;

public:
	Cliente();
	Cliente(string ced, string nom, string pais);
	Cliente(string ced, string nom, string pais, string actiEco, double desc);
	~Cliente();
	string toString();

};

