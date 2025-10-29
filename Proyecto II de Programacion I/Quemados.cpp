#include "Quemados.h"
Quemados::Quemados(Control* c): control(c){}
Quemados::~Quemados(){}
void Quemados::quemarDatos(){
	control->agregarSucursal();
}