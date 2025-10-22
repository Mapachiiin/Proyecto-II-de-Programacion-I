#include "EspacioEstacionamiento.h"

EspacioEstacionamiento::EspacioEstacionamiento(int capMax) {
	if (esPrimo(capMax)) {
		nF = 1;
		nC = capMax;
	}
	else if (capMax % 2 == 0) {
		nF = 2;
		nC = capMax / 2;
	}
	else if (capMax % 7 == 0) {
		nF = 7;
		nC = capMax / 7;
	}
	else {
		nF = 1;
		nC = capMax;
	}
	espacios = new Vehiculo * *[nF];
	for (int i = 0;i < nF;i++) {
		espacios[i] = new Vehiculo * [nC];
		for (int j = 0; j < nC;j++) {
			espacios[i][j] = nullptr;
		}
	}
}

EspacioEstacionamiento::~EspacioEstacionamiento(){
	for (int i = 0;i < nF;i++) {
		delete[] espacios[i];
}
	delete[] espacios;
}
string EspacioEstacionamiento::espacioRecomendado(){
	int temp=0;
	int aux=0;
	string espaReco = "";
	for (int i = 0;i < nF;i++) {
		for (int j = 0;j < nC;j++) {

		}
	}

}
bool EspacioEstacionamiento::esPrimo(int num) {

}