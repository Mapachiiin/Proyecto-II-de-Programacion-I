#pragma once
#include <string>
#include "BitacoraEstado.h"
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
Alquilado         SI      Actual      SI         NO          NO
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
	char licencia;
	double precio;
	string estado;
	BitacoraEstado** bitaVehi;
public:
	Vehiculo(string plac, string mode, string marc, char cate, char lice);
	string getEstado();
	string toString();
};

