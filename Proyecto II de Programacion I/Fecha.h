#pragma once
class Fecha
{
	private:
	int dia;
	int mes;
	int anio;
	public:
		Fecha(int dia, int mes, int annio);
		~Fecha();
		int getDia();
		int getMes();
		int getAnio();
		Fecha* obtenerFechaActual();
};

