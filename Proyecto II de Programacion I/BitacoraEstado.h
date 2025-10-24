#pragma once

class BitacoraEstado
{
private:
	string bitaco;
public:
	BitacoraEstado(int estado, Colaborador* c, Fecha* fAtc);
	~BitacoraEstado();
	void setBita(string esta);
	string bitacora();
};

