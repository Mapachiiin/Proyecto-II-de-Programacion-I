#include "Fecha.h"
#include <sstream>
#include <ctime>
using namespace std;



Fecha::Fecha() : dia(0), mes(0), anio(0) {}
Fecha::Fecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {}
Fecha::~Fecha() {}
Fecha* Fecha::obtenerFechaActual() {
    time_t t = time(nullptr);
    tm now_tm;
	localtime_s(&now_tm, &t);
    int dia = now_tm.tm_mday;
    int mes = now_tm.tm_mon + 1;
    int anio = now_tm.tm_year + 1900;

    static Fecha fecha(dia, mes, anio);
    return &fecha;
}
int Fecha::getDia() { return dia;}
int Fecha::getMes() { return mes;}
int Fecha::getAnio() {return anio;}
string Fecha::toString() {
    stringstream ss;
    ss << dia << "/" << mes << "/" << anio;
    return ss.str();
}