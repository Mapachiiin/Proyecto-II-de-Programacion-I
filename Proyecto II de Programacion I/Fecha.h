#pragma once
class Fecha
{
	private:
	int dia;
	int mes;
	int anio;
	public:
		Fecha();
		Fecha(int d, int m, int a);
		~Fecha();
		int getDia();
		int getMes();
		int getAnio();
		void setDia(int d);
		void setMes(int m);
		void setAnio(int a);
		void mostrarFecha();
};

