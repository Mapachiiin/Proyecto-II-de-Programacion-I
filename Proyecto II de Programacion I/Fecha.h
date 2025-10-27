#pragma once
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
		Fecha* obtenerFechaActual();
		string toString();
};

