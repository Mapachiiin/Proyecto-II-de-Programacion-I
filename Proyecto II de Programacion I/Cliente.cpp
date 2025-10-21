#include "Cliente.h"
#include <string>
#include <sstream>
using namespace std;

Cliente::Cliente(string ced, string nom, string pais) : paisResi(pais), desc(0.0), actiEco(" ") {
	setCedula(ced);
	setNombre(nom);
}
Cliente::Cliente(string ced, string nom, string pais, string actiE, double des): paisResi(pais), actiEco(actiE), desc(des) {
	setCedula(ced);
	setNombre(nom);
}
Cliente::~Cliente(){}

string Cliente::toString(){}
