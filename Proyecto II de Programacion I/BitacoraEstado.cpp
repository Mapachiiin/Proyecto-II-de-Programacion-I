#include "BitacoraEstado.h"
#include <iostream>
#include <sstream>
using namespace std;


string BitacoraEstado::nombresEstados[5] = { "Disponible", "Alquilado", "Devuelto", "Revision", "Lavado" };

BitacoraEstado::BitacoraEstado(int estadoAnt, int estadoNvo, Colaborador* c, Fecha* fCambio) : estadoAnterior(estadoAnt), nuevoEstado(estadoNvo), colaborador(c), fechaCambio(fCambio) {}
BitacoraEstado::~BitacoraEstado() {}
int BitacoraEstado::getEstadoAnterior() { return estadoAnterior; }
int BitacoraEstado::getNuevoEstado() { return nuevoEstado; }
Colaborador* BitacoraEstado::getColaborador() { return colaborador; }
Fecha* BitacoraEstado::getFechaCambio() { return fechaCambio; }

string BitacoraEstado::toString() {
    stringstream ss;
    ss << "Estado Anterior: " << nombresEstados[estadoAnterior] <<endl;
    ss << "Nuevo Estado: " << nombresEstados[nuevoEstado] << endl;
    ss << "Fecha del cambio: " << fechaCambio->toString() << endl;
    ss << "Colaborador: " << colaborador->getNombre()
        << " ( Cedula: " << colaborador->getCedula() << " )" << endl;
    return ss.str();
}
