#pragma once
#include "Colaborador.h"
#include "Fecha.h"
#include <string>
#include <sstream>
using namespace std;

class BitacoraEstado
{
private:
    int estadoAnterior; 
    int nuevoEstado;  
    Colaborador* colaborador;
    Fecha* fechaCambio; 
    static string nombresEstados[5];

public:
    BitacoraEstado(int estadoAnt, int estadoNvo, Colaborador* c, Fecha* fCambio);
    ~BitacoraEstado();

    int getEstadoAnterior();
    int getNuevoEstado();
    Colaborador* getColaborador();
    Fecha* getFechaCambio();

    string toString();
};

