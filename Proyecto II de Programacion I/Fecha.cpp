#include "Fecha.h"
#include <ctime>
#include <string>
using namespace std;

Fecha::Fecha() : dia(0), mes(0), anio(0) {}
Fecha::Fecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {}
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
string Fecha::toString() {
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
}