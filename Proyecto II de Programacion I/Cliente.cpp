#include "Cliente.h"
#include <string>
#include <sstream>
using namespace std;

Cliente::Cliente(): descuento(0.0), actiEco(" "), paisResi(" ") {}
Cliente::Cliente(string ced, string nom, string pais) : paisResi(pais), descuento(0.0), actiEco(" ") {
	setCedula(ced);
	setNombre(nom);
}
Cliente::Cliente(string ced, string nom, string pais, string actiE, double des): paisResi(pais), actiEco(actiE), descuento(des) {
	setCedula(ced);
	setNombre(nom);
}
Cliente::~Cliente(){}

string Cliente::toString(){
	stringstream ss;
	ss << "Cedula: " << getCedula() << endl;
	ss << "Nombre: " << getNombre() << endl;
	ss << "Pais de Residencia: " << paisResi << endl;
	if (actiEco != " ") {
		ss << "Actividad Economica: " << actiEco << endl;
		ss << "Descuento: " << descuento << "%" << endl;
	}
	return ss.str();
}