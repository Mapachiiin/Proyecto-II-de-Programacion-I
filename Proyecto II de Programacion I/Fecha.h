#pragma once
#include <string>
using namespace std;
class Fecha
{
private:
	int dia;
	int mes;
	int anio;
public:
	Fecha();
	Fecha(int dia, int mes, int anio);
	~Fecha();
	int getDia();
	int getMes();
	int getAnio();
	static Fecha* obtenerFechaActual();
	string toString();
};