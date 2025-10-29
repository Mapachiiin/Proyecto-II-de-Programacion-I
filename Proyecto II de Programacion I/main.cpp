#include <iostream>
#include "Control.h"
#include "Quemados.h"

using namespace std;

int main() {
	Control* menu = new Control();
	menu->menuPrincipal();
	delete menu;
	/*
	
	Proyecto 2
Cadena de Rent A Car �D-R-T Car Rental�
Fecha de entrega: Domingo 02 de noviembre 2025.
Porcentaje de la Calificaci�n del Curso: 15%
Modalidad: Individual o en parejas
Objetivo general:
Aplicar la definici�n y el uso de las estructuras de datos listas enlazadas y arreglos
bidimensionales (matrices), implementadas como clases de tipo colecci�n, punteros,
memoria din�mica, herencia y relaciones entre clases, al dise�ar e implementar un
programa para la gesti�n operativa de una empresa de renta de veh�culos.
Objetivos espec�ficos:
? Resolver el problema en forma eficiente y aplicando los principios del Paradigma
de Programaci�n Orientada a Objetos (POO).
? Realizar un adecuado dise�o de clases para que el sistema sea flexible y
escalable.
? Implementar adecuadamente la herencia de clases.
? Definir e implementar correctamente las relaciones entre clases.
? Definir y utilizar adecuada y eficientemente arreglos bidimensionales din�micos
y listas enlazadas, exclusivamente. No se permiten otras estructuras de datos.
? Administrar eficientemente el uso de memoria din�mica.
? Implementar correctamente el c�digo requerido en el lenguaje C++.
? Crear una interfaz de usuario en consola que permita interactuar con la
aplicaci�n de forma amigable e intuitiva.
? Implementar todas las funcionalidades de la aplicaci�n que se especifican.
Cadena de Renta A Car �D-R-T Car Rental�:
La empresa de renta de autom�viles �D-R-T Car Rental� le ha contratado para que
desarrolle un sistema de informaci�n para el control operativo y log�stico de la
empresa, as� como para el apoyo a la toma de decisiones. Para esto, la empresa le
ha compartido informaci�n sobre su organizaci�n y operaciones.

Actualmente D-R-T Car Rental tiene 10 sucursales ubicadas en distintas partes del
pa�s, las cuales son identificadas con un n�mero �nico de sucursal 

La empresa se encuentra en proceso de expansi�n, tanto regional como local, lo que implica que est�
en proceso de apertura de nuevas sucursales en distintos puntos del pa�s, por lo que
el sistema debe permitir registrar nuevas sucursales.


	Tabla de evaluaci�n y calificaci�n del proyecto :

	Para cada rubro especificado a continuaci�n se verificar� el cumplimiento de todo lo
		especificado al respecto en este documento.

	Es necesario que se haga un correcto, adecuado y eficiente dise�o e implementaci�n
		de clases y relaciones entre clases, de acuerdo con el POO.

	Como se mencion� anteriormente, el sistema debe permitir al usuario ingresar todos
		los datos requeridos para probar las funcionalidades.

	Aunque cada rubro tiene una calificaci�n individual, si la ausencia o mal
		funcionamiento de una funcionalidad impide probar otra, se perder�n los puntos de
		los rubros asociados a ambas funcionalidades.


	Planteles, Parqueos y Veh�culos :
Creaci�n de planteles de sucursal.Al crear un plantel de una sucursal
		se debe ingresar la cantidad de espacios de estacionamiento disponibles
		en el plantel, organizados por filas y columnas.Al crear un plantel se
		debe mostrar gr�ficamente la distribuci�n de los espacios de
		estacionamiento disponibles en el plantel. (5 pts).

Ingreso, eliminaci�n y visualizaci�n de veh�culos de una sucursal.
		Recuerde que, al ingresar un veh�culo, se debe vincular a un plantel y
		espacio de estacionamiento espec�ficos.Adem�s, para estacionar un
		veh�culo, el sistema debe generar una recomendaci�n de los espacios de
		estacionamiento m�s adecuados. (9 pts).

Reubicaci�n de un veh�culo en un plantel y un espacio de estacionamiento
		dentro de la misma sucursal. (3 pts).

Visualizaci�n de la distribuci�n de espacios de estacionamiento de un
		plantel, mostrando el estado de cada uno de los espacios de
		estacionamiento(disponibles y ocupados).Debe permitir al usuario
		ingresar un n�mero de espacio de estacionamiento especifico, y mostrar
		la placa del veh�culo estacionado en dicho espacio. (5 pts).

Cambio de estado de un veh�culo(de acuerdo con la tabla de estados
			presentada en el enunciado) y registro del cambio en la bit�cora.(4 pts).

(OPCIONAL) Traslado de veh�culos de una sucursal a otra.Debe permitir
		reubicar n veh�culos de la sucursal A a la Sucursal B.Solo se pueden
		reubicar los veh�culos que no se encuentren alquilador.Al trasladar los
		veh�culos se deben ubicar en espacios de estacionamiento espec�ficos de
		la sucursal B, de acuerdo con las recomendaciones de espacios generadas
		por el sistema. (7 pts).

		Solicitudes y Contratos:
Creaci�n y visualizaci�n de solicitudes(de cada solicitud se debe
			mostrar todo su detalle : sucursal, c�digo, id cliente, placa del
			veh�culo, d�as de alquiler, fecha de inicio, fecha de entrega, precio
			diario y total, estado, colaborador, etc.). (6 pts).

Aprobaci�n o rechazo de una solicitud de alquiler. (1 pto).
Recepci�n de veh�culo en alquiler y finalizaci�n del contrato.(3pts).
	
		Reportes de Cliente:
Historial del cliente, reporte de todas las solicitudes y contratos de
		alquiler realizados por un cliente especifico, detallando el c�digo del
		contrato / solicitud y la placa del veh�culo. (9 pts).

Reporte de clientes por cantidad de contratos : Ordena en la lista los
		clientes por cantidad de alquileres realizados, iniciando por el cliente
		que m�s alquileres haya hecho.Debe incluir el id y el nombre del
		cliente, as� como el c�digo de los contratos de alquiler realizados. (8 pts).
	
		Reportes de Planteles y Veh�culos:
Estados de un veh�culo especifico, se debe mostrar la bit�cora con todos
		los cambios de estado que ha tenido un veh�culo especifico, incluyendo:
	estado anterior, nuevo estado, fecha del cambio y colaborador que realiz�
		el cambio de estado. (6 pts).

Reporte de contratos para veh�culo especifico.Muestra todos los
		contratos de alquiler para un veh�culo especifico, detallando : placa del
		veh�culo, id de contrato, id del cliente, d�as de alquiler, fecha de
		inicio, fecha de devoluci�n, estado. (10 pts).

Reporte de porcentaje de ocupaci�n de los planteles.Se debe mostrar,
		por sucursal, el porcentaje de ocupaci�n actual de todos sus planteles.
		(7 pts).

		Reportes de alquileres:
Visualizaci�n de todos los contratos por sucursal, ordenados del m�s
		reciente al m�s antiguo, incluir: c�digo, estado, fecha de inicio,
		fecha de devoluci�n, id del cliente, placa del veh�culo, precio diario
		y total, colaborador. (8 pts).

Reporte alquileres por colaborador.Reporte de alquileres realizados por
		un colaborador especifico, incluir : id y nombre del colaborador, c�digo
		del contrato, placa del veh�culo y id del cliente. (10 pts).

		Total 100

		*/


	return 0;
}