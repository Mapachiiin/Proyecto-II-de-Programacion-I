#pragma once
#include <iostream>
using namespace std;

class Persona
{
protected:
	string nombre;
	int edad;
	string cedula;
public:
	Persona();
	~Persona();
	string getNombre() const;
	int getEdad() const;
	string getCedula() const;
	void setNombre(string nom);
	void setEdad(int ed);
	void setCedula(string ced);

};

