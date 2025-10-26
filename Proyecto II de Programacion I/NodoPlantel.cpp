#include "NodoPlantel.h"
NodoPlantel::NodoPlantel(Plantel * dato) : dato(dato), sig(nullptr) {}
NodoPlantel::~NodoPlantel(){}
void NodoPlantel::setDato(Plantel* dato) { this->dato = dato; }
Plantel* NodoPlantel::getDato() { return dato; }
void NodoPlantel::setNodoSig(NodoPlantel* sig) { this->sig = sig; }
NodoPlantel* NodoPlantel::getNodoSig() { return sig; }