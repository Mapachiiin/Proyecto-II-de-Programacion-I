#pragma once
#include <string>
#include "ListaBitacorasEstado.h"
#include "Colaborador.h"
#include "Fecha.h"
using namespace std;

class Vehiculo
	/*

	Cada veh�culo tiene una placa, modelo, marca, ubicaci�n dentro del plantel y una de
las siguientes categor�as:
- A: econ�mico
- B: Est�ndar
- C: Lujo
- D: 4x4
Cada categor�a se relaciona con el precio diario de alquiler. Todos los veh�culos de
cada categor�a deben tener el mismo precio de alquiler, es decir, todos los veh�culos
de tipo A deben tener el mismo precio de alquiler, as� mismo, todos los veh�culos de
tipo B y as� sucesivamente.
De cada autom�vil interesa su marca, modelo, placa, tipo de licencia requerida,
categor�a, precio y estado. El estado debe ser uno de los siguientes posibles:
- Disponible
- Alquilado
- Devuelto
- Revisi�n
- Lavado
Cada vez que la empresa compra un veh�culo nuevo debe incluirse en el sistema con
todos sus datos, incluyendo su estado en �Revisi�n�, as� como su asignaci�n a una
sucursal, plantel y espacio de estacionamiento.
La siguiente tabla muestra c�mo pueden cambiar los estados de un veh�culo, por
ejemplo, si analizamos la primera fila, podemos observar como un veh�culo puede pasar
de Disponible a Alquilado, Revisi�n o a Lavado, pero no puede pasar a Devuelto, pues
no tendr�a sentido por estar disponible.

							Pr�ximo Estado
Estado Actual Disponible Alquilado Devuelto    Revisi�n    Lavado
Disponible     Actual       SI        NO         SI          SI
Alquilado         NO      Actual      SI         NO          NO
Devuelto          NO        NO      Actual       SI          SI
Revisi�n          NO        NO        NO       Actual        SI
Lavado            SI        NO        NO         SI        Actual

	*/

{
private:
	string placa;
	string model;
	string marca;
	string cate;
	char categoria;
	char licencia;
	double precio;
	static const int estadoDisponible = 0;
	static const int estadoAlquilado = 1;
	static const int estadoDevuelto = 2;
	static const int estadoRevision = 3;
	static const int estadoLavado = 4;
	int estadoActual;
	ListaBitacorasEstado* listaBE;
public:
	static string estado[5];
	static bool transPermitida[5][5];
	Vehiculo(string plac, string mode, string marc, char cate, char lice);
	~Vehiculo();
	void mostrarBitacora();
	bool puedeCambiarEstado(int estadoActual, int estadoNuevo);
	string getPlaca();
	string getModelo();
	string getMarca();
	string getCategoria();
	double getPrecio();
	string getEstadoNombre();
	char getCategoriaChar();
	char getLicencia();
	int getEstado();
	void cambiarEstado(int estado, Colaborador* c, Fecha* fAtc);
	string toString();
};

