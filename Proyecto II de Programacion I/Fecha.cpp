#include "Fecha.h"
#include <sstream>
#include <ctime>
using namespace std;

Fecha* Fecha::fechaActualPtr = nullptr;

Fecha::Fecha() : dia(0), mes(0), anio(0) {}
Fecha::Fecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {}
Fecha::~Fecha() {}

void Fecha::inicializarFechaGlobal() {
    if (fechaActualPtr == nullptr) {
        time_t t = time(nullptr);
        tm now_tm;
        localtime_s(&now_tm, &t);
        int dia = now_tm.tm_mday;
        int mes = now_tm.tm_mon + 1;
        int anio = now_tm.tm_year + 1900;

        fechaActualPtr = new Fecha(dia, mes, anio);
    }
}
void Fecha::liberarFechaGlobal() {
    if (fechaActualPtr != nullptr) {
        delete fechaActualPtr;
        fechaActualPtr = nullptr;
    }
}
Fecha* Fecha::obtenerFechaActualPtr() {
    if (fechaActualPtr == nullptr) {
        inicializarFechaGlobal();
    }
    return fechaActualPtr;
}
Fecha* Fecha::clonar() {
    return new Fecha(this->dia, this->mes, this->anio);
}
int Fecha::getDia() { return dia; }
int Fecha::getMes() { return mes; }
int Fecha::getAnio() { return anio; }
bool Fecha::esAnioBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}
int Fecha::diasEnMes(int mes, int anio) {
    switch (mes) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return esAnioBisiesto(anio) ? 29 : 28;
    default:
        return 30;
    }
}

Fecha* Fecha::agregarDias(int dias) {
    int nDia = this->dia;
    int nMes = this->mes;
    int nAnio = this->anio;
    nDia += dias;
    while (nDia > diasEnMes(nMes, nAnio)) {
        nDia -= diasEnMes(nMes, nAnio);
        nMes++;
        if (nMes > 12) {
            nMes = 1;
            nAnio++;
        }
    }
    return new Fecha(nDia, nMes, nAnio);
}

string Fecha::toString() {
    stringstream ss;
    ss << dia << "/" << mes << "/" << anio;
    return ss.str();
}