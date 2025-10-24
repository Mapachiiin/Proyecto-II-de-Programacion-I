#include "BitacoraEstado.h"
#include <iostream>
#include <sstream>
using namespace std;

	BitacoraEstado::BitacoraEstado(int estado, Colaborador* c, Fecha* fAtc): bitaco(""){}
	BitacoraEstado::~BitacoraEstado(){}
	void BitacoraEstado::setBita(string esta) {
		bitaco = esta;
	}
	string BitacoraEstado::bitacora(){
		return bitaco;
	}
