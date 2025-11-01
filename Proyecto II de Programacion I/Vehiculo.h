#pragma once
#include <string>
#include "ListaBitacorasEstado.h"
#include "Colaborador.h"
#include "Fecha.h"
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
Alquilado         NO      Actual      SI         NO          NO
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

