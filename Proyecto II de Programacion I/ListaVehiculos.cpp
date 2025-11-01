#include "ListaVehiculos.h"
#include "NodoVehiculo.h"
#include <string>
using namespace std;

	ListaVehiculos::ListaVehiculos(): inicio(nullptr), tam(0) {}
	ListaVehiculos::~ListaVehiculos(){
		NodoVehiculo* actual = inicio;
		while (actual) {
			NodoVehiculo* siguiente = actual->getNodoSig();
			delete actual;
			actual = siguiente;
		}
		inicio = nullptr;
		tam = 0;
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
	void ListaVehiculos::mostrarVehiculosDetallados(){ //Profe, esto es solo para que quedara bonito :D
		if (!inicio) {
			cout << "No hay vehículos en la lista." << endl;
			return;
		}
		int cont = 1;
		NodoVehiculo* actual = inicio;
		while (actual) {
			Vehiculo* v = actual->getDato();
			cout << "╔═══════════════════════════════════════════════════════════════╗" << endl;
			cout << "║  [" << cont << "] Placa: " << v->getPlaca() << " | Modelo: " << v->getModelo()
				<< " | Marca: " << v->getMarca() << endl;
			cout << "║  Categoria: " << v->getCategoria() << " | Licencia: " << v->getLicencia()
				<< " | Precio: ₡" << v->getPrecio() << " | Estado: " << v->getEstado() << endl;
			cout << "╚═══════════════════════════════════════════════════════════════╝" << endl;
			actual = actual->getNodoSig();
			cont++;
		}
	}
	void ListaVehiculos::mostrarVehiculosSimple(){
		if (!inicio) {
			cout << "No hay vehículos en la lista." << endl;
			return;
		}
		NodoVehiculo* actual = inicio;
		int contador = 1;

		while (actual) {
			Vehiculo* v = actual->getDato();
			cout << " " << contador << ". " << v->getPlaca()
				<< " - " << v->getModelo()
				<< " (" << v->getMarca()
				<< ") - ₡" << v->getPrecio() << "/día" << endl;

			actual = actual->getNodoSig();
			contador++;
		}
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
	bool ListaVehiculos::buscarVehiculoPorPlaca(string placa){
		NodoVehiculo* actual = inicio;
		while (actual) {
			if(actual->getDato()->getPlaca()==placa){
				return true;
			}
			actual = actual->getNodoSig();
		}
		return false;
	}
	Vehiculo* ListaVehiculos::obtenerVehiculoPorPlaca(string placa){
		NodoVehiculo* actual = inicio;
		while (actual) {
			if(actual->getDato()->getPlaca()==placa){
				return actual->getDato();
			}
			actual = actual->getNodoSig();
		}
		return nullptr;
	}
	void ListaVehiculos::cambioEstadoVehiculo(string placa, int nuevoEstado, Colaborador* c, Fecha* fA){
		if (!c) return;
		NodoVehiculo* actual = inicio;
		while (actual) {
			if(actual->getDato()->getPlaca()==placa){
				actual->getDato()->cambiarEstado(nuevoEstado, c, fA);
				return;
			}
			actual = actual->getNodoSig();
		}
	}
	bool ListaVehiculos::eliminarVehiculo(string placa){
		if (!inicio) return false;
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
				delete actual;
				return true;
			}
			anterior = actual;
			actual = actual->getNodoSig();
		}
		return false;
	}
	void ListaVehiculos::trasladoVehiculoEntreSucursales(string placa, ListaVehiculos* destino) {}
	/*if (!destino) return;
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
	return; */