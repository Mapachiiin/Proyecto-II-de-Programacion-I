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
				<< " | Precio: " << v->getPrecio()<<" colones " << " | Estado: " << v->getEstado() << endl;
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
				<< ") - " << v->getPrecio() <<" colones" << "/dia" << endl;

			actual = actual->getNodoSig();
			contador++;
		}
	}
	void ListaVehiculos::mostrarVehiculosAlquilados(){
		if (!inicio) {
			cout << "No hay vehículos en la lista." << endl;
			return;
		}
		NodoVehiculo* actual = inicio;
		int contador = 1;
		while (actual) {
			Vehiculo* v = actual->getDato();
			if (v->getEstadoNombre() == "Alquilado") {
				cout << " " << contador << ". " << v->getPlaca()
					<< " - " << v->getModelo()
					<< " (" << v->getMarca()
					<< ") - " << v->getPrecio() <<" colones" << "/dia" << endl;
				contador++;
			}
			actual = actual->getNodoSig();
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
	int ListaVehiculos::getTam(){ return tam; }
	bool ListaVehiculos::eliminarVehiculo(string placa) {
		if (!inicio) return false;
		NodoVehiculo* actual = inicio;
		NodoVehiculo* anterior = nullptr;
		while (actual) {
			if (actual->getDato()->getPlaca() == placa) {
				if (anterior == nullptr) inicio = actual->getNodoSig();
				else anterior->setNodoSig(actual->getNodoSig());
				delete actual->getDato(); 
				delete actual;
				tam--;
				return true;
			}
			anterior = actual;
			actual = actual->getNodoSig();
		}
		return false;
	}
	bool ListaVehiculos::eliminarNodoVehiSinDelete(string placa) {// Retorna true si elimina el nodo luego de soltar el dato, false si no lo encuentra, si quisiera intercambiar vehiculos, simplemente haria que devuelva el nodo en vez de un booleano y vincularia ese mismo nodo a otro vehiculo
		if (!inicio) return false;
		NodoVehiculo* actual = inicio;
		NodoVehiculo* anterior = nullptr;
		while (actual) {
			if (actual->getDato()->getPlaca() == placa) {
				if (anterior == nullptr) {
					inicio = actual->getNodoSig();
				}
				else {
					anterior->setNodoSig(actual->getNodoSig());
				}
				tam--;
				actual->soltarDato();
				delete actual;
				return true;
			}
			anterior = actual;
			actual = actual->getNodoSig();
		}
		return false;
	}