#include "ListaSolisyContras.h"
#include "ListaClientes.h"
#include "ListaColaboradores.h"
#include <iostream>
#include <string>
using namespace std;

ListaSolisyContras::ListaSolisyContras(): inicio(nullptr), tam(0) {}
ListaSolisyContras::~ListaSolisyContras() {
	NodoSoliyContra* actual = inicio;
	while (actual) {
		NodoSoliyContra* siguiente = actual->getNodoSig();
		delete actual; 
		actual = siguiente;
	}
	inicio = nullptr;
	tam = 0;
}
bool ListaSolisyContras::buscarSolicitudPorCodigo(string codigo){
	NodoSoliyContra* actual = inicio;
	while (actual) {
		if (actual->getDato()->getCodigo() == codigo) {
			return true;
		}
		actual = actual->getNodoSig();
	}
	return false;
}
SoliAlquiyContra* ListaSolisyContras::obtenerSolicitudPorCodigo(string codigo){
	NodoSoliyContra* actual = inicio;
	while (actual) {
		if (actual->getDato()->getCodigo() == codigo) {
			return actual->getDato();
		}
		actual = actual->getNodoSig();
	}
	return nullptr;
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
void ListaSolisyContras::mostrarContratosPorVehiculo(string placa){
	NodoSoliyContra* actual = inicio;
	while (actual) {
		if (actual->getDato()->getEsContrato()) {
			if (actual->getDato()->getPlaVehi() == placa) {
				cout << actual->getDato()->mostrarInfo() << endl;
			}
		}
		actual = actual->getNodoSig();
	}
}
bool ListaSolisyContras::tieneVehiContrato(string placa) {
	NodoSoliyContra* actual = inicio;
	while (actual) {
		if (actual->getDato()->getEsContrato()) {
			if (actual->getDato()->getPlaVehi() == placa) return true;
		}
		actual = actual->getNodoSig();
	}
	return false;
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
void ListaSolisyContras::historialPorCliente(string cedula) {
	NodoSoliyContra* actual = inicio;
	int cont = 0;
	while (actual) {
		if (actual->getDato()->getCli()->getCedula() == cedula) {
			if (actual->getDato()->getEsContrato()) {
				cout << cont + 1 << ". Contrato asociado al cliente "<< actual->getDato()->getCli()->getNombre()<<" con cedula: " << cedula << ", Codigo: \n" << actual->getDato()->getCodigo() << endl;
				cont++;
			}
			else {
				cout << cont + 1 << ". Solicitud asociada al cliente "<< actual->getDato()->getCli()->getNombre()<<" con cedula: " << cedula << ", Codigo:\n" << actual->getDato()->getCodigo() << endl;
				cont++;
			}
		}
		actual = actual->getNodoSig();
	}
	if (cont == 0) {
		cout << "No se encontraron solicitudes o contratos asociados al cliente con cedula: " << cedula << endl;
	}
}
void ListaSolisyContras::reporteClientesPorCantidadDeContratos() {
	if (!inicio) {
		cout << "No hay solicitudes/contratos." << endl;
		return;
	}
	ListaClientes* lista = new ListaClientes();
	NodoSoliyContra* actual = inicio;
	while (actual) {
		SoliAlquiyContra* soli = actual->getDato();
		if (soli && soli->getCli()) {
			if (!lista->buscarClientePorCedula(soli->getCli()->getCedula())) {
				lista->agregarCliente(soli->getCli());
			}
		}
		actual = actual->getNodoSig();
	}
	cout << " Clientes ordenados por cantidad de contratos:" << endl << endl;
	while (lista->getInicio()) {
		NodoCliente* nAct = lista->getInicio();
		NodoCliente* nMax = nullptr;
		int maxCount = -1;
		while (nAct) {
			Cliente* cliente = nAct->getDato();
			if (!cliente) {
				nAct = nAct->getNodoSig();
				continue;
			}
			string ced = cliente->getCedula();
			int count = 0;
			NodoSoliyContra* Actual2 = inicio;
			while (Actual2) {
				SoliAlquiyContra* soli = Actual2->getDato();
				if (soli && soli->getCli() && soli->getCli()->getCedula() == ced && soli->getEsContrato()) {
					count++;
				}
				Actual2 = Actual2->getNodoSig();
			}

			if (count > maxCount) {
				maxCount = count;
				nMax = nAct;
			}

			nAct = nAct->getNodoSig();
		}
		if (maxCount <= 0 || !nMax || !nMax->getDato()) break;
		Cliente* cMax = nMax->getDato();
		cout << "Cedula: " << cMax->getCedula()
			<< " | Nombre: " << cMax->getNombre()
			<< " | Numero de contratos: " << maxCount << endl;
		lista->eliminarNodoSinDelete(cMax->getCedula());
	}
	delete lista;
}
void ListaSolisyContras::reportesAlquilerPorColaborador(string cedula) {
	if (!inicio) {
		cout << "No hay solicitudes/contratos." << endl;
		return;
	}
	NodoSoliyContra* actual = inicio;
	int cont = 0;
	while (actual) {
		if (actual->getDato() && actual->getDato()->getCola()) {
			if (actual->getDato()->getCola()->getCedula() == cedula) {
				if (cont == 0) {
					cout << "Colaborador: " << actual->getDato()->getCola()->getNombre() << " ha realizado los siguientes alquileres: " << endl;
					cont++;
				}
				if (actual->getDato()->getEsContrato()) {
					cout << "Contrato de alquiler asociado al colaborador " << actual->getDato()->getCola()->getNombre() << ", Codigo:\n" << actual->getDato()->getCodigo() << endl;
				}
				if (!actual->getDato()->getEsContrato()) {
					cout << "Solicitud de alquiler asociada al colaborador " << actual->getDato()->getCola()->getNombre() << ", Codigo:\n" << actual->getDato()->getCodigo() << endl;
				}
			}
			actual = actual->getNodoSig();
		}
	}
}
int ListaSolisyContras::getTam() { return tam; }
void ListaSolisyContras::mostrarContratosOrdenados() { //Este metodo muestra los contratos ordenados del mas reciente al mas antiguo, ya que la naturaleza de la lista es agregar al final los mas recientes, por lo que simplemente se invierte (misma logica que el proyecto 1 jeje)
	if (!inicio) {
		cout << "No hay contratos en esta sucursal." << endl;
		return;
	}
	NodoSoliyContra* listaInvertida = nullptr;
	NodoSoliyContra* actual = inicio;
	int totalContratos = 0;
	while (actual) {
		if (actual->getDato()->getEsContrato()) {
			NodoSoliyContra* nuevoNodo = new NodoSoliyContra(actual->getDato());
			nuevoNodo->setNodoSig(listaInvertida);
			listaInvertida = nuevoNodo;
			totalContratos++;
		}
		actual = actual->getNodoSig();
	}

	if (totalContratos == 0) {
		cout << "No hay contratos en esta sucursal." << endl;
		return;
	}

	cout << " Contratos del mas reciente al mas antiguo " << endl;
	cout << "Total de contratos: " << totalContratos << endl << endl;

	actual = listaInvertida;
	while (actual) {
		actual->getDato()->mostrarInfo();
		cout << "---------------------------------------" << endl << endl;
		actual = actual->getNodoSig();
	}
	while (listaInvertida) {
		NodoSoliyContra* temp = listaInvertida;
		listaInvertida = listaInvertida->getNodoSig();
		delete temp;
	}
}