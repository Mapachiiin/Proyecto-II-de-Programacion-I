#include "Vehiculo.h"
#include <sstream>

using namespace std;

Vehiculo::Vehiculo(string plac, string mode, string marc, char cat, char lice) : placa(plac), model(mode), marca(marc), licencia(lice), estadoActual(estadoRevision), precio(0), categoria('N') {
	listaBE = new ListaBitacorasEstado();
	if (cat == 'A' || cat == 'B' || cat == 'C' || cat == 'D') {
		switch (cat) {
		case 'A':
		{
			precio = 50000;
			cate = "Economico";
			categoria = 'A';
			break;
		}
		case 'B':
		{
			precio = 75000;
			cate = "Estandar";
			categoria = 'B';
			break;
		}
		case 'C':
		{
			precio = 150000;
			cate = "Lujo";
			categoria = 'C';
			break;
		}
		case 'D':
		{
			precio = 120000;
			cate = "4x4";
			categoria = 'D';
			break;
		}
		}
	}
	else {
		precio = 0;
		cate = "No determinado";
		categoria = 'N';
	}
}
Vehiculo::~Vehiculo() {
	delete listaBE;
}
string Vehiculo::estado[5] = { "Disponible", "Alquilado", "Devuelto", "Revision", "Lavado" };
bool Vehiculo::transPermitida[5][5] = {
{ false, true, false, true, true },  // Desde Disponible
{ false, false, true, false, false},  // Desde Alquilado
{ false, false, false, true, true },  // Desde Devuelto
{ false, false, false, false, true },  // Desde Revision
{ true, false, false, true, false }   // Desde Lavado
};
string Vehiculo::getPlaca() { return placa; }
string Vehiculo::getModelo() { return model; }
string Vehiculo::getMarca() { return marca; }
string Vehiculo::getCategoria() { return cate; }
char Vehiculo::getCategoriaChar() { return categoria; }
string Vehiculo::getEstadoNombre() { return estado[estadoActual]; }
int Vehiculo::getPrecio() { return precio; }
char Vehiculo::getLicencia() { return licencia; }
int Vehiculo::getEstado() { return estadoActual; }
bool Vehiculo::puedeCambiarEstado(int estActual, int estNuevo) {
	if (estActual < 0 || estActual>4 || estNuevo < 0 || estNuevo>4) return false;
	return transPermitida[estActual][estNuevo];
}
void Vehiculo::cambiarEstado(int nEstado, Colaborador* cola, Fecha* fAct) {
	if (!cola || !fAct) return;
	if (!puedeCambiarEstado(estadoActual, nEstado)) {
		cout << "Cambio de estado no permitido" << endl << estado[estadoActual] << " -> " << estado[nEstado] << endl;
		return;
	}
	if (puedeCambiarEstado(estadoActual, nEstado)) {
		listaBE->agregarBitacora(estadoActual, nEstado, cola, fAct);
		cout << "Cambio de estado realizado exitosamente: " << estado[estadoActual] << " -> " << estado[nEstado] << endl;
		this->estadoActual = nEstado;
		return;
	}
	else {
		return;
	}


}
void Vehiculo::mostrarBitacora() {
	listaBE->mostrarBitacora();
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
