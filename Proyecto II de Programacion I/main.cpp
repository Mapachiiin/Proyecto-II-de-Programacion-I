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
Cadena de Rent A Car “D-R-T Car Rental”
Fecha de entrega: Domingo 02 de noviembre 2025.
Porcentaje de la Calificación del Curso: 15%
Modalidad: Individual o en parejas
Objetivo general:
Aplicar la definición y el uso de las estructuras de datos listas enlazadas y arreglos
bidimensionales (matrices), implementadas como clases de tipo colección, punteros,
memoria dinámica, herencia y relaciones entre clases, al diseñar e implementar un
programa para la gestión operativa de una empresa de renta de vehículos.
Objetivos específicos:
? Resolver el problema en forma eficiente y aplicando los principios del Paradigma
de Programación Orientada a Objetos (POO).
? Realizar un adecuado diseño de clases para que el sistema sea flexible y
escalable.
? Implementar adecuadamente la herencia de clases.
? Definir e implementar correctamente las relaciones entre clases.
? Definir y utilizar adecuada y eficientemente arreglos bidimensionales dinámicos
y listas enlazadas, exclusivamente. No se permiten otras estructuras de datos.
? Administrar eficientemente el uso de memoria dinámica.
? Implementar correctamente el código requerido en el lenguaje C++.
? Crear una interfaz de usuario en consola que permita interactuar con la
aplicación de forma amigable e intuitiva.
? Implementar todas las funcionalidades de la aplicación que se especifican.
Cadena de Renta A Car “D-R-T Car Rental”:
La empresa de renta de automóviles “D-R-T Car Rental” le ha contratado para que
desarrolle un sistema de información para el control operativo y logístico de la
empresa, así como para el apoyo a la toma de decisiones. Para esto, la empresa le
ha compartido información sobre su organización y operaciones.

Actualmente D-R-T Car Rental tiene 10 sucursales ubicadas en distintas partes del
país, las cuales son identificadas con un número único de sucursal 

La empresa se encuentra en proceso de expansión, tanto regional como local, lo que implica que está
en proceso de apertura de nuevas sucursales en distintos puntos del país, por lo que
el sistema debe permitir registrar nuevas sucursales.


	Tabla de evaluación y calificación del proyecto :

	Para cada rubro especificado a continuación se verificará el cumplimiento de todo lo
		especificado al respecto en este documento.

	Es necesario que se haga un correcto, adecuado y eficiente diseño e implementación
		de clases y relaciones entre clases, de acuerdo con el POO.

	Como se mencionó anteriormente, el sistema debe permitir al usuario ingresar todos
		los datos requeridos para probar las funcionalidades.

	Aunque cada rubro tiene una calificación individual, si la ausencia o mal
		funcionamiento de una funcionalidad impide probar otra, se perderán los puntos de
		los rubros asociados a ambas funcionalidades.


	Planteles, Parqueos y Vehículos :
Creación de planteles de sucursal.Al crear un plantel de una sucursal
		se debe ingresar la cantidad de espacios de estacionamiento disponibles
		en el plantel, organizados por filas y columnas.Al crear un plantel se
		debe mostrar gráficamente la distribución de los espacios de
		estacionamiento disponibles en el plantel. (5 pts).

Ingreso, eliminación y visualización de vehículos de una sucursal.
		Recuerde que, al ingresar un vehículo, se debe vincular a un plantel y
		espacio de estacionamiento específicos.Además, para estacionar un
		vehículo, el sistema debe generar una recomendación de los espacios de
		estacionamiento más adecuados. (9 pts).

Reubicación de un vehículo en un plantel y un espacio de estacionamiento
		dentro de la misma sucursal. (3 pts).

Visualización de la distribución de espacios de estacionamiento de un
		plantel, mostrando el estado de cada uno de los espacios de
		estacionamiento(disponibles y ocupados).Debe permitir al usuario
		ingresar un número de espacio de estacionamiento especifico, y mostrar
		la placa del vehículo estacionado en dicho espacio. (5 pts).

Cambio de estado de un vehículo(de acuerdo con la tabla de estados
			presentada en el enunciado) y registro del cambio en la bitácora.(4 pts).

(OPCIONAL) Traslado de vehículos de una sucursal a otra.Debe permitir
		reubicar n vehículos de la sucursal A a la Sucursal B.Solo se pueden
		reubicar los vehículos que no se encuentren alquilador.Al trasladar los
		vehículos se deben ubicar en espacios de estacionamiento específicos de
		la sucursal B, de acuerdo con las recomendaciones de espacios generadas
		por el sistema. (7 pts).

		Solicitudes y Contratos:
Creación y visualización de solicitudes(de cada solicitud se debe
			mostrar todo su detalle : sucursal, código, id cliente, placa del
			vehículo, días de alquiler, fecha de inicio, fecha de entrega, precio
			diario y total, estado, colaborador, etc.). (6 pts).

Aprobación o rechazo de una solicitud de alquiler. (1 pto).
Recepción de vehículo en alquiler y finalización del contrato.(3pts).
	
		Reportes de Cliente:
Historial del cliente, reporte de todas las solicitudes y contratos de
		alquiler realizados por un cliente especifico, detallando el código del
		contrato / solicitud y la placa del vehículo. (9 pts).

Reporte de clientes por cantidad de contratos : Ordena en la lista los
		clientes por cantidad de alquileres realizados, iniciando por el cliente
		que más alquileres haya hecho.Debe incluir el id y el nombre del
		cliente, así como el código de los contratos de alquiler realizados. (8 pts).
	
		Reportes de Planteles y Vehículos:
Estados de un vehículo especifico, se debe mostrar la bitácora con todos
		los cambios de estado que ha tenido un vehículo especifico, incluyendo:
	estado anterior, nuevo estado, fecha del cambio y colaborador que realizó
		el cambio de estado. (6 pts).

Reporte de contratos para vehículo especifico.Muestra todos los
		contratos de alquiler para un vehículo especifico, detallando : placa del
		vehículo, id de contrato, id del cliente, días de alquiler, fecha de
		inicio, fecha de devolución, estado. (10 pts).

Reporte de porcentaje de ocupación de los planteles.Se debe mostrar,
		por sucursal, el porcentaje de ocupación actual de todos sus planteles.
		(7 pts).

		Reportes de alquileres:
Visualización de todos los contratos por sucursal, ordenados del más
		reciente al más antiguo, incluir: código, estado, fecha de inicio,
		fecha de devolución, id del cliente, placa del vehículo, precio diario
		y total, colaborador. (8 pts).

Reporte alquileres por colaborador.Reporte de alquileres realizados por
		un colaborador especifico, incluir : id y nombre del colaborador, código
		del contrato, placa del vehículo y id del cliente. (10 pts).

		Total 100

		*/


	return 0;
}