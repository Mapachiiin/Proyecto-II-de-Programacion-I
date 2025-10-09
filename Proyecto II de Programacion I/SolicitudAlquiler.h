#pragma once
class SolicitudAlquiler

/*

Para alquilar un vehículo primeramente se genera una solicitud de alquiler. Cada
solicitud debe tener un código o ID único, la identificación del cliente, del
colaborador responsable, de la sucursal, la placa del vehículo, la cantidad de días
de alquiler, la fecha de inicio, la fecha de entrega, el precio de alquiler (por día
y en total) y un estado: aprobada, pendiente, rechazada, anulada.
Cuando una solicitud de alquiler es aprobada, dicha solicitud se convierte en un
contrato de alquiler y deja de ser una solicitud de alquiler. Los posibles estados
del contrato son los siguientes:
 Aprobado en alquiler.
 Aprobado pendiente de ejecución.
 Finalizado (finalizado con multa, finalizado con reintegro, finalizado sin
cargos adicionales)

 Al ser devuelto un vehículo se da por finalizado el contrato, pero antes se debe
verificar que se haya devuelto a tiempo. Al devolver un vehículo se ingresa la placa
del vehículo y la cantidad de días que se utilizó. En caso que se entregue de manera
anticipada, se debe hacer un reintegro del 70% sobre el precio diario del alquiler
por cada día que no se utilizó el vehículo. En caso que la entrega sea tardía, se
debe cobrar una multa del 130% sobre el precio diario del alquiler, por cada día de
atraso.

*/

{
};

