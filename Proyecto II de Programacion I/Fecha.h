#pragma once
#include <string>
using namespace std;
class Fecha
{
private:
	int dia;
	int mes;
	int anio;
	static Fecha* fechaActualPtr;
	int diasEnMes(int mes, int anio);
	bool esAnioBisiesto(int anio);
public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    ~Fecha();
    int getDia();
    int getMes();
    int getAnio();
    static Fecha* obtenerFechaActualPtr();
    Fecha* clonar();
    static void inicializarFechaGlobal();
    static void liberarFechaGlobal();
	Fecha* agregarDias(int dias);
    string toString();
};