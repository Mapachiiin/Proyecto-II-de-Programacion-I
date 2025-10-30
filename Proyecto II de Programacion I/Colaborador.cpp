#include "Colaborador.h"
#include <string>
#include <sstream>
using namespace std;

Colaborador::Colaborador(string ced, string nom, Fecha fecha){
	this->fechaIngre= fecha.obtenerFechaActual();
	setCedula(ced);
	setNombre(nom);
}
Colaborador::~Colaborador(){}

string Colaborador::toString(){
	stringstream ss;
	ss << "Colaborador: " << nombre << " | Cedula: " << cedula << " | Fecha de Ingreso: " << fechaIngre.toString();
	return ss.str();
}
