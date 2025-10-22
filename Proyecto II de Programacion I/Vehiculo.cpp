#include "Vehiculo.h"

Vehiculo::Vehiculo(string plac, string mode, string marc, char cat, char lice) : placa(plac), model(mode), marca(marc), licencia(lice), estado("Revision") {
	if (cat == 'A' || cat == 'B' || cat == 'C' || cat == 'D') {
		switch (cat) {
		case 'A':
		{
			precio = 0;
			cate = "Economico";
				break;
		}
		case 'B':
		{
			precio = 0;
			cate = "Estandar";
				break;
		}
		case 'C':
		{
			precio = 0;
			cate = "Lujo";
				break;
		}
		case 'D':
		{
			precio = 0;
			cate = "4x4";
				break;
		}
		}
	} else { 
		precio = 0;
		cate = "No determinado";
	}
}
string Vehiculo::getEstado() { return estado; }
