#include "ListaVehiculos.h"

	ListaVehiculos::ListaVehiculos(): inicio(nullptr), tam(0) {}

	ListaVehiculos::~ListaVehiculos(){
		NodoVehiculo* actual = inicio;
		while (actual != nullptr) {
			NodoVehiculo* siguiente = actual->getNodoSig();
			delete actual;
			actual = siguiente;
		}
	}

	void ListaVehiculos::agregarVehiculo(Vehiculo* v){
		if (!v) return;
		NodoVehiculo* nuevo = new NodoVehiculo(v);
		if (inicio == nullptr) {
			inicio = nuevo;
		}
		else {
			NodoVehiculo* actual = inicio;
			while (actual->getNodoSig() != nullptr) {
				actual = actual->getNodoSig();
			}
			actual->setNodoSig(nuevo);
		}
		tam++;
	}

	void ListaVehiculos::mostrarVehiculo(Vehiculo* v){
		if (!v) return;
		NodoVehiculo* actual = inicio;
		while (actual) {
			if(actual->getDato()==v){
				cout << actual->getDato()->toString() << endl;
				return;
			}
			actual = actual->getNodoSig();
		}
		return;
	}

	void ListaVehiculos::cambioEstadoVehiculo(string placa, int nuevoEstado, Colaborador* c){
		if (!c) return;
		NodoVehiculo* actual = inicio;
		while (actual) {
			if(actual->getDato()->getPlaca()==placa){
				actual->getDato()->cambiarEstado(nuevoEstado);
				return;
			}
			actual = actual->getNodoSig();
		}
	}

	double ListaVehiculos::reporteDePorcentajeDeOcupacionDelPlantel(EspacioEstacionamiento* espacios){
		if (!espacios) return 0.0;
		int totalEspacios = espacios->getCapMax();
		if (totalEspacios == 0) return 0.0;
		int espaciosVacios = espacios->contarEspaciosVacios();
		double ocupacion = ((totalEspacios - espaciosVacios) / (double)totalEspacios) * 100.0;
		return ocupacion;
	}

	void ListaVehiculos::trasladoVehiculoEntreSucursales(string placa, ListaVehiculos* destino) {
		if (!destino) return;
		NodoVehiculo* actual = inicio;
		NodoVehiculo* anterior = nullptr;
		while (actual) {
			if (actual->getDato()->getPlaca() == placa) {
				if (anterior) {
					anterior->setNodoSig(actual->getNodoSig());
				}
				else {
					inicio = actual->getNodoSig();
				}
				tam--;
				destino->agregarVehiculo(actual->getDato());
				delete actual;
				return;
			}
			anterior = actual;
			actual = actual->getNodoSig();
		}
		return;
	}

	void ListaVehiculos::eliminarVehiculo(string placa){
		NodoVehiculo* actual = inicio;
		NodoVehiculo* anterior = nullptr;
		while (actual->getNodoSig()) {
			if (actual->getDato()->getPlaca() == placa) {
				if (anterior) {
					anterior->setNodoSig(actual->getNodoSig());
				}
				else {
					inicio = actual->getNodoSig();
				}
				tam--;
				delete actual;
				return;
			}
			anterior = actual;
			actual = actual->getNodoSig();
		}
	}