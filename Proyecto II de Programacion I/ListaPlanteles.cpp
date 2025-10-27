#include "ListaPlanteles.h"

static const string RED = "\033[31m";
static const string GREEN = "\033[32m"; //Para que se vea mas bonito jajajjaja
static const string ORIGINAL = "\033[0m";

ListaPlanteles::ListaPlanteles() :inicio(nullptr), tam(0) {}
ListaPlanteles::~ListaPlanteles() {
	if (!inicio) return;
	if( tam==1){
		delete inicio;
		return;
	}
	NodoPlantel* actual = inicio;
	NodoPlantel* anterior = nullptr;
	while (actual) {
		if (anterior) {
			delete anterior;
		}
		anterior = actual;
		actual = actual->getNodoSig();
	}

}
void ListaPlanteles::agregarPlantel(Plantel* p) {
	if (!p) return;
	NodoPlantel* nuevo = new NodoPlantel(p);
	if (!inicio) {
		inicio = nuevo;
		tam++;
		return;
	}
	else {
		NodoPlantel* actual = inicio;
		while (actual->getNodoSig()) {
			actual = actual->getNodoSig();
		}
		actual->setNodoSig(nuevo);
		tam++;
}
}	

void ListaPlanteles::mostrarPlanteles() {
	NodoPlantel* actual = inicio;
	while (actual){
		if (actual->getDato()) {
			cout << "Plantel: " << actual->getDato()->getLetra() << " | Tipo: " << actual->getDato()->getTipo() << " | Capacidad Maxima: " << actual->getDato()->getCapMax() << endl;
		}
		actual = actual->getNodoSig();
	}
}
void ListaPlanteles::visualizacionGraficaDePlanteles(char letra) {
	NodoPlantel* actual = inicio;
	while (actual) {
		if (actual->getDato() && actual->getDato()->getLetra() == letra) {
			cout << "| Plantel: " << actual->getDato()->getLetra() << endl << " | Tipo: " << actual->getDato()->getTipo() << endl << " | Capacidad Maxima: " << actual->getDato()->getCapMax() << endl << endl;
			EspacioEstacionamiento* espacio = actual->getDato()->getEstacionamiento();
			if (espacio) {
				int nC = espacio->getnC();
				int nF = espacio->getnF();
				for (int i = 0; i < nF; i++) {
					for (int j = 0; j < nC; j++) {
						int numVerdadero = i * nC + j + 1;
						string codigoEspacio;
						codigoEspacio.push_back(actual->getDato()->getLetra()); //No sabia que no podia sumar un char a un string directamente
						if (numVerdadero < 10) codigoEspacio +=  "0" + to_string(numVerdadero); // estaba haciendo codigoEspacio = actual->getDato()->getLetra() + "0" + to_string(numVerdadero);
						else codigoEspacio += to_string(numVerdadero);
						bool ocupado = espacio->estaOcupado(i, j);
						if (ocupado) {
							cout << RED << "[" << codigoEspacio << " - X] " << ORIGINAL << " ";
						}
						else {
							cout << GREEN << "[" << codigoEspacio << " - O] " << ORIGINAL << " ";
						}
					}
					cout << endl;
				}
			}
			return;
		}
		actual = actual->getNodoSig();
	}
	cout << "No se encontro el plantel con la letra: " << letra << endl;
}
bool ListaPlanteles::eliminarPlantel(char letra) {
	if (!inicio) return;
	NodoPlantel* actual = inicio;
	NodoPlantel* anterior = nullptr;
	while(actual) {
		if (actual->getDato() && actual->getDato()->getLetra() == letra) {
			if (!anterior) {
				inicio = actual->getNodoSig();
			}
			else {
				anterior->setNodoSig(actual->getNodoSig());
			}
			delete actual;
			tam--;
			return true;
		}
		anterior = actual;
		actual = actual->getNodoSig();
	}
	return false;
}