#pragma once
#include "NodoSoliyContra.h"


class ListaSolisyContras
{
private:
	NodoSoliyContra* inicio;
	int tam;

public:
	ListaSolisyContras();
	~ListaSolisyContras();
	bool buscarSolicitudPorCodigo(string codigo);
	SoliAlquiyContra* obtenerSolicitudPorCodigo(string codigo);
	void agregarSolicitud(SoliAlquiyContra* s);
	void mostrarSolicitudOContraSucursal(bool sOC);
	void mostrarSolicitudEspecifica(string codigo);
	void mostrarContratosPorVehiculo(string placa);
	bool tieneVehiContrato(string placa);
	void aprobaRechaSolicitud(string codigo);
	void recepcionVehiculoDevuelto(string placa, int diasUsados);
	void reportesSolicitudesPorVehiculo(string placa);
	void historialPorCliente(string cedula);
	void reporteClientesPorCantidadDeContratos();
	void reportesAlquilerPorColaborador(string cedula);
	void mostrarContratosOrdenados();
	int getTam();
};

