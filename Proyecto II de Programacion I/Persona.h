#pragma once
#include <iostream>
using namespace std;

class Persona
{
protected:
	string nombre;
	string apellido;
	int edad;
	string cedula;
public:
	Persona();
	~Persona();
	string getNombre() const;
	string getApellido() const;
	int getEdad() const;
	string getCedula() const;
	void setNombre(string nom);
	void setApellido(string ape);
	void setEdad(int ed);
	void setCedula(string ced);

};

