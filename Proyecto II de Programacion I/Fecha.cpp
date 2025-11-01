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

string Fecha::toString() {
    stringstream ss;
    ss << dia << "/" << mes << "/" << anio;
    return ss.str();
}