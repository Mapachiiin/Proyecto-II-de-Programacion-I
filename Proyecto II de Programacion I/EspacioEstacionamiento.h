#pragma once
class EspacioEstacionamiento

	/*
	
	Cuando un veh�culo es alquilado deja disponible su espacio en el estacionamiento y
cuando es devuelto, el sistema debe recomendar un lugar espec�fico para estacionar
el veh�culo que ingresa. El sistema debe recomendar primeramente el plantel de la
sucursal con m�s espacios de estacionamiento disponibles. Una vez elegido el plantel,
el sistema debe recomendar los espacios de estacionamiento con menos veh�culos
ubicados a su alrededor, esto con el objetivo de minimizar el riesgo de choques. El
sistema debe mostrar una vista grafica del plantel recomendado, por ejemplo:
Para alquilar un veh�culo primeramente se genera una solicitud de alquiler. Cada
solicitud debe tener un c�digo o ID �nico, la identificaci�n del cliente, del
colaborador responsable, de la sucursal, la placa del veh�culo, la cantidad de d�as
B00 B01 B02 B03 B04 B05
B10 B11 B12 B13 B14 B15
B20 B21 B22 B23 B24 B25
B30 B31 B32 B33 B34 B35
B40 B41 B42 B43 B44 B45
Espacios de estacionamiento
recomendados:
B40
B30
B05
Nota: El sistema recomienda
y el usuario decide el espacio de
estacionamiento por asignar.

	*/

{
};

