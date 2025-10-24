#include "ListaSolisyContras.h"
#include <iostream>
using namespace std;

ListaSolisyContras::ListaSolisyContras(): inicio(nullptr), tam(0) {}
ListaSolisyContras::~ListaSolisyContras() {
	NodoSoliyContra* actual = inicio;
	NodoSoliyContra* siguiente = actual->getNodoSig();
	while (actual) {
		if (siguiente) {
			delete actual;
			actual = siguiente;
			siguiente = actual->getNodoSig();
		}
		else {
			delete actual;
			actual = nullptr;
		}
	}
}
void ListaSolisyContras::agregarSolicitud(SoliAlquiyContra* s){
	if (!s) return;

	NodoSoliyContra* nuevo = new NodoSoliyContra(s);
	if (!inicio) {
		inicio = nuevo;
		tam++;
	}
	else {
		NodoSoliyContra* actual = inicio;
		while (actual->getNodoSig()) {
			actual = actual->getNodoSig();
		}
		actual->setNodoSig(nuevo);
		tam++;
	}
}
void ListaSolisyContras::mostrarSolicitudOContraSucursal(bool sOC) {
	if (!inicio) return;

	NodoSoliyContra* actual = inicio;
	if (sOC) {
		while (actual) {
			if (actual->getDato()) {
				if (actual->getDato()->getEsContrato()) {
					cout << "Contrato: " << actual->getDato()->getCodigo() << " | Estado: " << actual->getDato()->getEstadoContrato() << endl;
				}
			}
			actual = actual->getNodoSig();
		}
		return;
	}
	if (!sOC) {
		while (actual) {
			if (actual->getDato()) {
				if (!actual->getDato()->getEsContrato()) {
					cout << "Solicitud: " << actual->getDato()->getCodigo() << " | Estado : " << actual->getDato()->getEstadoSoli() << endl;
				}
			}
			actual = actual->getNodoSig();
		}
		return;
	}
}
void ListaSolisyContras::mostrarSolicitudEspecifica(string codigo){
	NodoSoliyContra* actual = inicio;
	while (actual){
		if (actual->getDato()->getCodigo() == codigo) {
			cout<<actual->getDato()->mostrarInfo() << endl;
			return;
		}
		actual = actual->getNodoSig();
	}
}
void ListaSolisyContras::aprobaRechaSolicitud(string codigo){
	NodoSoliyContra* actual = inicio;
	bool finalizado = false;
	while (actual) {
		if (actual->getDato()->getCodigo() == codigo) {
			while(!finalizado){
			string estadoActual = actual->getDato()->getEstadoSoli();
			if (estadoActual == "Pendiente") {
				char decision;
				cout << "Desea aprobar o rechazar la solicitud " << codigo << "? (A/R): ";
				cin >> decision;
				if (decision == 'A' || decision == 'a') {
					actual->getDato()->cambiarEstadoSoli("Aprobada");
					actual->getDato()->convertirAContrato();
					cout << "Solicitud " << codigo << " aprobada y convertida en contrato." << endl;
					finalizado = true;	
				}
				else if (decision == 'R' || decision == 'r') {
					actual->getDato()->cambiarEstadoSoli("Rechazada");
					cout << "Solicitud " << codigo << " rechazada." << endl;
					finalizado = true;
				}
				else {
					cout << "Decision invalida. Vuelvalo a intentar." << endl;
					continue;
				}
			}
			else {
				cout << "La solicitud " << codigo << " no esta en estado pendiente." << endl;
				break;
			}
		}
		}
		actual = actual->getNodoSig();
	}
	cout << "Solicitud con codigo: " << codigo << " no encontrada." << endl;
}
void ListaSolisyContras::recepcionVehiculoDevuelto(string placa, int diasUsados){
	NodoSoliyContra* actual = inicio;
	while (actual) {
		if (actual->getDato()->getEsContrato()) {
			if (actual->getDato()->getPlaVehi() == placa) {
				actual->getDato()->finalizarContrato(diasUsados);
				cout << "Contrato para el vehiculo con placa " << placa << " " << actual->getDato()->getEstadoContrato() << endl;
				return;
			}
		}
		actual = actual->getNodoSig();
	}
	cout << "No se encontro un contrato asociado a la placa: " << placa << endl;
}
void ListaSolisyContras::reportesSolicitudesPorVehiculo(string placa){
	NodoSoliyContra* actual = inicio;
	int cont = 0;
	while (actual) {
		if (actual->getDato()->getPlaVehi() == placa) {
			if(actual->getDato()->getEsContrato()){
				cout << "Contrato asociado a la placa: " << placa << ", Codigo:\n" << actual->getDato()->getCodigo() << endl;
				cont++;
			} else {
				cout << "Solicitud asociada a la placa: " << placa << ", Codigo:\n" << actual->getDato()->getCodigo() << endl;
				cont++;
			}
		}
		actual = actual->getNodoSig();
	}
	if(cont==0) {
		cout << "No se encontraron solicitudes o contratos asociados a la placa: " << placa << endl;
	}
}