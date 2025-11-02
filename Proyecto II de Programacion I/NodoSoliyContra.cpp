#include "NodoSoliyContra.h"

NodoSoliyContra::NodoSoliyContra(SoliAlquiyContra* c) : dato(c), sig(nullptr) {}
NodoSoliyContra::~NodoSoliyContra() {
	if (dato) delete dato;
	dato = nullptr;
	sig = nullptr;
}
void NodoSoliyContra::setDato(SoliAlquiyContra* c) { this->dato = c; }
void NodoSoliyContra::soltarDato() { dato = nullptr; }
SoliAlquiyContra* NodoSoliyContra::getDato() { return dato; }
void NodoSoliyContra::setNodoSig(NodoSoliyContra* sig) { this->sig = sig; }
NodoSoliyContra* NodoSoliyContra::getNodoSig() { return sig; }