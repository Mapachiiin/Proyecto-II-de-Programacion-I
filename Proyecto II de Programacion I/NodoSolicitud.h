#pragma once
#include "SolicitudAlquiler.h"
class NodoSolicitud
{
	SolicitudAlquiler* dato;
	NodoSolicitud* sig;
	NodoSolicitud(SolicitudAlquiler* c);
};

