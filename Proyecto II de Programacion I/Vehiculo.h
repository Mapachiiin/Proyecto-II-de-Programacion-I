#pragma once
#include <string>
#include "BitacoraEstado.h"
using namespace std;

class Vehiculo
	/*
	
	Cada vehículo tiene una placa, modelo, marca, ubicación dentro del plantel y una de
las siguientes categorías:
- A: económico
- B: Estándar
- C: Lujo
- D: 4x4
Cada categoría se relaciona con el precio diario de alquiler. Todos los vehículos de
cada categoría deben tener el mismo precio de alquiler, es decir, todos los vehículos
de tipo A deben tener el mismo precio de alquiler, así mismo, todos los vehículos de
tipo B y así sucesivamente.
De cada automóvil interesa su marca, modelo, placa, tipo de licencia requerida,
categoría, precio y estado. El estado debe ser uno de los siguientes posibles:
- Disponible
- Alquilado
- Devuelto
- Revisión
- Lavado
Cada vez que la empresa compra un vehículo nuevo debe incluirse en el sistema con
todos sus datos, incluyendo su estado en “Revisión”, así como su asignación a una
sucursal, plantel y espacio de estacionamiento.
La siguiente tabla muestra cómo pueden cambiar los estados de un vehículo, por
ejemplo, si analizamos la primera fila, podemos observar como un vehículo puede pasar
de Disponible a Alquilado, Revisión o a Lavado, pero no puede pasar a Devuelto, pues
no tendría sentido por estar disponible.

Próximo Estado
Estado Actual Disponible Alquilado Devuelto    Revisión    Lavado
Disponible     Actual       SI        NO         SI          SI
Alquilado         SI      Actual      SI         NO          NO
Devuelto          NO        NO      Actual       SI          SI
Revisión          NO        NO        NO       Actual        SI
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

