#include "ListaBitacorasEstado.h"
#include "NodoBitacoraEstado.h"
#include "BitacoraEstado.h"

ListaBitacorasEstado::ListaBitacorasEstado() :inicio(nullptr), tam(0) {}
ListaBitacorasEstado::~ListaBitacorasEstado() {
	while (inicio != nullptr) {
		NodoBitacoraEstado* temp = inicio;
		inicio = inicio->getNodoSig();
		delete temp;
	}
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