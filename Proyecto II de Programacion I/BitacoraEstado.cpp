#include "BitacoraEstado.h"
#include <iostream>
#include <sstream>
using namespace std;

	BitacoraEstado::BitacoraEstado(): bitaco(""){}
	BitacoraEstado::~BitacoraEstado(){}
	void BitacoraEstado::setBita(string esta) {
		bitaco = esta;
	}
	string BitacoraEstado::bitacora(){
		return bitaco;
	}
