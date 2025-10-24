#pragma once
#include "NodoSoliyContra.h"
class ListaSolicitudes
{
private:
	NodoSoliyContra* inicio;
	int tam;

public:
	ListaSolicitudes();
	~ListaSolicitudes();
	void agregarSolicitud(SoliAlquiyContra* s);
	void mostrarSolicitudesSucursal();
	void mostrarSolictudEspecifica(string codigo);
	void aprobaRechaSolicitud(string codigo);
	void recepcionVehiculoDevuelto(string placa, int diasUsados);
	void reportesSolicitudesPorVehiculo(Vehiculo* v);
};

