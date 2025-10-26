#include "NodoCliente.h"

NodoCliente::NodoCliente(Cliente* c) : dato(c), sig(nullptr) {}
NodoCliente::~NodoCliente() { delete dato; }
void NodoCliente::setDato(Cliente* c) { dato = c; }
Cliente* NodoCliente::getDato() { return dato; }
void NodoCliente::setNodoSig(NodoCliente* n) { sig = n; }
NodoCliente* NodoCliente::getNodoSig() { return sig; }