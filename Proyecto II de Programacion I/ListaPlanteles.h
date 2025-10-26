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
	void visualizacionGraficaDePlanteles(char letra);
	bool eliminarPlantel(char letra);
};

