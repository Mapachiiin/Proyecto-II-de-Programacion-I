#include "EspacioEstacionamiento.h"
#include <string>

EspacioEstacionamiento::EspacioEstacionamiento(int capMax) {
    if (capMax <= 0) {
        nF = 0;
        nC = 0;
        espacios = nullptr;
        return;
    }
	if (capMax % 7 == 0) {
		nF = 7;
		nC = capMax / 7;
    }
    else if (capMax % 5 == 0) {
        nF = 5;
        nC = capMax / 5;
    }
    else if (capMax % 2 == 0) {
		nF = 2;
		nC = capMax / 2;
	}
    else if (capMax % 3 == 0) {
        nF = 3;
        nC = capMax / 3;
    }
	else if (esPrimo(capMax)) {
		nF = 1;
		nC = capMax;
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
}                                                                                                                                                                                            vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         

EspacioEstacionamiento::~EspacioEstacionamiento() {
    if(espacios){
	for (int i = 0;i < nF;i++) {
		delete[] espacios[i];
}
	delete[] espacios;
    }
}

string EspacioEstacionamiento::espacioRecomendado() {
    int maxVecinos=0, mejorF=-1, mejorC=-1; //Los -1 es para que no entre al ultimo if si no hay ningun espacio disponible
    string mejorEspa = "";
    for (int i = 0; i < nF; i++) {
        for (int j = 0; j < nC; j++) {
            if (espacios[i][j] == nullptr) {
                int vecinosLibres = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int p = -1; p <= 1; p++) {
                        if (k == 0 && p == 0) continue; //Este if es para no evaluar la celda que se esta probando como un "vecino" aunque realmente no habria problema si no esta jajaj
                        int nf = i + k;
                        int nc = j + p;
                        if (nf >= 0 && nf < nF && nc >= 0 && nc < nC) {
                            if (espacios[nf][nc] == nullptr)
                                vecinosLibres++;
                        }
                    }
                }
                if (vecinosLibres > maxVecinos) {
                    maxVecinos = vecinosLibres;
                    mejorF = i;
                    mejorC = j;
                }
            }
        }
    }
    
    if (mejorF >= 0 && mejorC >= 0) return to_string(mejorF)+to_string(mejorC);

    return "No hay espacios disponibles";
}

int EspacioEstacionamiento::contarEspaciosVacios() {
    int eT = 0;
    for (int i = 0;i < nF;i++) {
        for (int j = 0;j < nC;j++) {
            if (!espacios[i][j]) eT++;
        }
    }
    return eT;
}

void EspacioEstacionamiento::eliminarVehiAlquilado(Vehiculo* elimi) {
    for (int i = 0;i < nF;i++) {
        for (int j = 0;j < nC;j++) {
            if (espacios[i][j] == elimi) { espacios[i][j] = nullptr; return; }
        }
    }
}

bool EspacioEstacionamiento::esPrimo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i*i < num;i++) {
        if (num % i == 0) return false;
    }
    return true;
}