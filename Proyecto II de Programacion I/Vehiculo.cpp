#include "Vehiculo.h"
#include <sstream>

using namespace std;

Vehiculo::Vehiculo(string plac, string mode, string marc, char cat, char lice) : placa(plac), model(mode), marca(marc), licencia(lice), estadoActual(estadoRevision){
	if (cat == 'A' || cat == 'B' || cat == 'C' || cat == 'D') {
		switch (cat) {
		case 'A':
		{
			precio = 0;
			cate = "Economico";
				break;
		}
		case 'B':
		{
			precio = 0;
			cate = "Estandar";
				break;
		}
		case 'C':
		{
			precio = 0;
			cate = "Lujo";
				break;
		}
		case 'D':
		{
			precio = 0;
			cate = "4x4";
				break;
		}
		}
	} else { 
		precio = 0;
		cate = "No determinado";
	}
}

string Vehiculo::getPlaca() { return placa; }
int Vehiculo::getEstado() { return estadoActual; }
bool Vehiculo::puedeCambiarEstado(int estadoActual, int estadoNuevo) {
	if (estadoActual < 0 || estadoActual>4 || estadoNuevo < 0 || estadoNuevo>4) return false;
	return transPermitida[estadoActual][estadoNuevo];
}

void Vehiculo::cambiarEstado(int estado, Colaborador* cola, Fecha* fAct) {
	if (puedeCambiarEstado(estadoActual, estado)) {
		this->estadoActual = estado;
		listaBE->agregarBitacora(estado, cola, fAct); // CAMBIAR ESTA VERGA, LA BITACORA NECESITA UN PICHAZO DE COSAS MAAAAAAAAAAAAAAAAS
	}
	else {
		return;
	}
	
	
}
string Vehiculo::toString() {
	stringstream ss;
	ss << "Placa: " << placa << "\n";
	ss << "Modelo: " << model << "\n";
	ss << "Marca: " << marca << "\n";
	ss << "Categoria: " << cate << "\n";
	ss << "Licencia requerida: " << licencia << "\n";
	ss << "Precio diario: " << precio << "\n";
	ss << "Estado actual: " << estado[estadoActual] << "\n";
	return ss.str();
}
