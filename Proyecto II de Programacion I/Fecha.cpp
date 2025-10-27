#include "Fecha.h"
#include <ctime>

Fecha::Fecha(int d, int m, int an) : dia(d), mes(m), anio(an) {}
Fecha::~Fecha() {}
Fecha* Fecha::obtenerFechaActual() {
    time_t t = time(nullptr);
    int dia = localtime(&t)->tm_mday;
    int mes = localtime(&t)->tm_mon + 1;
    int anio = localtime(&t)->tm_year + 1900;

    static Fecha fecha(dia, mes, anio);
    return &fecha;
}
int Fecha::getDia() {return dia;}
int Fecha::getMes() {return mes;}
int Fecha::getAnio() {return anio;}