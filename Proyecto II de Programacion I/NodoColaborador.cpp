#include "NodoColaborador.h"

NodoColaborador::NodoColaborador(Colaborador* c) : dato(c), sig(nullptr) {}
NodoColaborador::~NodoColaborador() { delete dato; }
void NodoColaborador::setDato(Colaborador* c) { dato = c; }
Colaborador* NodoColaborador::getDato() { return dato; }
void NodoColaborador::setNodoSig(NodoColaborador* n) { sig = n; }
NodoColaborador* NodoColaborador::getNodoSig() { return sig; }