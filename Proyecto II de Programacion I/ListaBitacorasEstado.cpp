#include "ListaBitacorasEstado.h"
#include "NodoBitacoraEstado.h"
#include "BitacoraEstado.h"

ListaBitacorasEstado::ListaBitacorasEstado() :inicio(nullptr), tam(0) {}
ListaBitacorasEstado::~ListaBitacorasEstado() {
	NodoBitacoraEstado* actual = inicio;
	while (actual) {
		NodoBitacoraEstado* siguiente = actual->getNodoSig();
		delete actual;
		actual = siguiente;
	}
	inicio = nullptr;
	tam = 0;
}
void ListaBitacorasEstado::agregarBitacora(int estado, Colaborador* c, Fecha* fAtc) {
	BitacoraEstado* estadoBit = new BitacoraEstado(estado, c, fAtc);
	NodoBitacoraEstado* nuevo = new NodoBitacoraEstado(estadoBit);
	if (inicio == nullptr) {
		inicio = nuevo;
	}
	else {
		NodoBitacoraEstado* temp = inicio;
		while (temp->getNodoSig() != nullptr) {
			temp = temp->getNodoSig();
		}
		temp->setNodoSig(nuevo);
	}
	tam++;
}