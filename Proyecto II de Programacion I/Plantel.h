#pragma once
#include "EspacioEstacionamiento.h"
#include "ListaVehiculos.h"
class Plantel
	/*
	Cada una de las sucursales tiene n de planteles
, cada uno éstos dividido en varios espacios de estacionamiento. Cada plantel se identifica con una letra, además registra una capacidad máxima de vehículos que puede alojar y un tipo, el cual puede ser uno de los siguientes:
- (1) Techado y asfaltado
- (2) Techado y lastreado
- (3) Asfaltado
- (4) Lastreado
Cada Plantel tiene m espacios de Estacionamiento. Cada espacio de estacionamientose identifica con un código único, el cual está compuesto por la letra del plantel y un número, por ejemplo: A01, A02, A03, B01, B02, B03. Cada espacio de estacionamiento, además, tiene un estado (disponible u ocupado). Ejemplo:
La sucursal de Heredia tiene dos planteles: el A y el B:
1 Plantel: Es la instalación física destinada al resguardo, operación y mantenimiento de los vehículos de la empresa. En el plantel se realizan actividades como el estacionamiento de las unidades cuando no están en servicio, la limpieza, entre otros. A01
A02
A03
A04
A05
A06
B01 B02 B03 B04 B05 B06 B07 B08 B09 B10 B11 B12 B13 B14 B15 B16 B17 B18 B19 B20 B21 B22 B23 B24 B25 B26 B27 B28 B29 B30  Plantel A
Tipo: 1
Capacidad o estacionamientos: para 6 vehículos
Plantel B Tipo: 2
Capacidad o estacionamientos: para 30 vehículos
	*/
{
private:
char letra;
string tipo;
int capMax;
EspacioEstacionamiento* estacionamiento;
ListaVehiculos* listaVehiculos;

public:
Plantel();
Plantel(char letra, string tipo, int capMax);
~Plantel();
char getLetra();
string getTipo();
int getCapMax();
EspacioEstacionamiento* getEstacionamiento();
ListaVehiculos* getListaVehiculos();
};

