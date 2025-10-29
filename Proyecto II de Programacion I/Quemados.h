#pragma once
#include "Control.h"

class Quemados
{
private:
	Control* control;
public:
	Quemados(Control* c);
	~Quemados();
	void quemarDatos();
};