#include "NodoBitacoraEstado.h"
NodoBitacoraEstado::NodoBitacoraEstado(BitacoraEstado* c) : dato(c), sig(nullptr) {}
NodoBitacoraEstado::~NodoBitacoraEstado(){}
void NodoBitacoraEstado::setDato(BitacoraEstado* c){ this->dato = c; }
BitacoraEstado* NodoBitacoraEstado::getDato(){ return dato; }
void NodoBitacoraEstado::setNodoSig(NodoBitacoraEstado* sig){ this->sig = sig; }
NodoBitacoraEstado* NodoBitacoraEstado::getNodoSig(){ return sig; }