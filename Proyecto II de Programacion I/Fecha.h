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

    string toString();
};