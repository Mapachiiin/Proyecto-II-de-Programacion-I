#pragma once
#include "NodoPlantel.h"

class ListaPlanteles
{
private:
	NodoPlantel* inicio;
	int tam;
public:
	ListaPlanteles();
	~ListaPlanteles();
	void agregarPlantel(Plantel* p);
	void mostrarPlanteles();
	bool existeLetraPlantel(char letra);
	Plantel* obtenerPlantelPorLetra(char letra);
	void visualizacionGraficaDePlanteles(char letra);
	bool eliminarPlantel(char letra);
	double reporteDePorcentajeDeOcupacionDeLosPlanteles();
};

