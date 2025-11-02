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
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
EspacioEstacionamiento::~EspacioEstacionamiento() {
    if(espacios){
	for (int i = 0;i < nF;i++) {
		if(espacios[i]) delete[] espacios[i];
}
	delete[] espacios;
    }
}
int EspacioEstacionamiento::getCapMax() { return nF * nC; }
int EspacioEstacionamiento::getnF() { return nF; }
int EspacioEstacionamiento::getnC() { return nC; }
string EspacioEstacionamiento::espacioRecomendado() {
    if (!espacios) return "No hay espacios disponibles";
    int maxVecinos = -1, mejorF = -1, mejorC = -1;
    for (int i = 0; i < nF; i++) {
        for (int j = 0; j < nC; j++) {
            if (espacios[i][j] == nullptr) {
                int veciLibres = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int p = -1; p <= 1; p++) {
                        if (k == 0 && p == 0) continue;
                        int nf = i + k;
                        int nc = j + p;
                        if (nf >= 0 && nf < nF && nc >= 0 && nc < nC) {
                            if (espacios[nf][nc] == nullptr)
                                veciLibres++;
                        }
                    }
                }
                if (veciLibres > maxVecinos) {
                    maxVecinos = veciLibres;
                    mejorF = i;
                    mejorC = j;
                }
            }
        }
    }

    if (mejorF >= 0 && mejorC >= 0) {
        int numeroEspacio = (mejorF * nC) + mejorC + 1;
        return "Espacio recomendado: " + to_string(numeroEspacio) +" (Fila " + to_string(mejorF) + ", Columna " + to_string(mejorC) + ")";
    }

    return "No hay espacios disponibles";
}
int EspacioEstacionamiento::cambiarVehiculoDeEspacio(Vehiculo* v, int posVieja, int posNueva) {
    if (!v || !espacios) return -1;
    int filaVieja = posVieja / nC;
    int colVieja = posVieja % nC;
    int filaNueva = posNueva / nC;
    int colNueva = posNueva % nC;
    if (filaVieja < 0 || filaVieja >= nF || colVieja < 0 || colVieja >= nC ||
        filaNueva < 0 || filaNueva >= nF || colNueva < 0 || colNueva >= nC) {
        return -2;
    }
    if (espacios[filaVieja][colVieja] != v) {
        return -3;
    }
    if (espacios[filaNueva][colNueva] != nullptr) {
        return -4;
    }
    espacios[filaNueva][colNueva] = v;
    espacios[filaVieja][colVieja] = nullptr;
    return 0; 
}
int EspacioEstacionamiento::obtenerFilaVehiculo(Vehiculo* v) {
    if (!v || !espacios) return -1;
    for (int i = 0;i < nF;i++) {
        for (int j = 0;j < nC;j++) {
            if (espacios[i][j] == v) return i;
        }
    }
    return -2; // Vehiculo no encontrado
}
int EspacioEstacionamiento::obtenerColumnaVehiculo(Vehiculo* v) {
    if (!v || !espacios) return -1;
    for (int i = 0;i < nF;i++) {
        for (int j = 0;j < nC;j++) {
            if (espacios[i][j] == v) return j;
        }
    }
    return -2; // Vehiculo no encontrado
}
int EspacioEstacionamiento::contarEspaciosVacios() {
    int eT = 0;
    if(espacios){
    for (int i = 0;i < nF;i++) {
        for (int j = 0;j < nC;j++) {
            if (!espacios[i][j]) eT++;
        }
    }
    }
    return eT;
}
bool EspacioEstacionamiento::eliminarVehi(string placa) {
    if (espacios) {
        for (int i = 0;i < nF;i++) {
            for (int j = 0;j < nC;j++) {
                if (espacios[i][j]->getPlaca() == placa) { espacios[i][j] = nullptr; return true; }
            }
        }
    }
    return false;
}
bool EspacioEstacionamiento::esPrimo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i*i < num;i++) {
        if (num % i == 0) return false;
    }
    return true;
}
bool EspacioEstacionamiento::agregarVehiculoEnEspacio(Vehiculo* v, int F, int C) {
    if (F >= 0 && F < nF && C >= 0 && C < nC && !espacios[F][C]) {
        espacios[F][C] = v;
        return true;
    }
	cout << "Espacio no disponible o fuera de rango" << endl;
    return false;
}
bool EspacioEstacionamiento::estaOcupado(int f, int c) {
    if (f >= 0 && f < nF && c >= 0 && c < nC) {
        return espacios[f][c] != nullptr;
    }
    return false;
}
Vehiculo* EspacioEstacionamiento::getVehiculoEnEspacio(int f, int c) {
    if (f >= 0 && f < nF && c >= 0 && c < nC) {
        return espacios[f][c];
    }
    return nullptr;
}