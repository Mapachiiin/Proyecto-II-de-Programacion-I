#pragma once
#include "Persona.h"
class Cliente : public Persona 

	/*
	
	La empresa atiende a dos tipos de cliente: personas f�sicas y personas jur�dicas.
Para ambos se requiere saber la identificaci�n, el nombre y su pa�s de residencia.
En el caso de los clientes de tipo persona jur�dica se requiere saber adem�s su
actividad econ�mica (texto) y el porcentaje de descuento que se le aplica a la empresa
(no todas las personas jur�dicas tienen el mismo descuento).

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

