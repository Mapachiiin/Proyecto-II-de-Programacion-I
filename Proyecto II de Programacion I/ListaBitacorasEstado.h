#pragma once
#include "NodoBitacoraEstado.h"

class ListaBitacorasEstado {
private:
    NodoBitacoraEstado* inicio;
    int tam;

public:
    ListaBitacorasEstado();
    ~ListaBitacorasEstado();
    void agregarBitacora(int estadoAnt, int estadoNvo, Colaborador* c, Fecha* fCambio);
	void mostrarBitacora();
    bool estaVacia();
    int getTam();
};