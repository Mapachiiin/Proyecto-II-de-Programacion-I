#include "Colaborador.h"
#include <string>
#include <sstream>
using namespace std;

Colaborador::Colaborador(string ced, string nom, int dia, int mes, int annio){
	this->fechaIngre= new Fecha(dia, mes, annio);
	setCedula(ced);
	setNombre(nom);
}
Colaborador::~Colaborador(){
	delete fechaIngre;
}
string Colaborador::toString(){}
