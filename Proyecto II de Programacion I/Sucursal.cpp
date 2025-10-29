#include "Sucursal.h"

Sucursal::Sucursal() {
	numSucursal = 0;
	planteles = new ListaPlanteles;
	solicitudes = new ListaSolisyContras;
	clientes = new ListaClientes;
	colaboradores = new ListaColaboradores;
}
Sucursal::Sucursal(int num) {
	numSucursal = num;
	planteles = new ListaPlanteles;
	solicitudes = new ListaSolisyContras;
	clientes = new ListaClientes;
	colaboradores = new ListaColaboradores;
}
Sucursal::~Sucursal() {
	delete planteles;
	delete solicitudes;
	delete clientes;
	delete colaboradores;
}
int Sucursal::getNumSucursal() { return numSucursal; }
ListaPlanteles* Sucursal::getPlanteles() { return planteles; }
ListaSolisyContras* Sucursal::getSolicitudes() { return solicitudes; }
ListaClientes* Sucursal::getClientes() { return clientes; }
ListaColaboradores* Sucursal::getColaboradores() { return colaboradores; }
void Sucursal::agregarPlantel(Plantel* p) { planteles->agregarPlantel(p); }
void Sucursal::eliminarPlantel(char letra) { planteles->eliminarPlantel(letra); }
void Sucursal::agregarSolicitud(SoliAlquiyContra* s) { solicitudes->agregarSolicitud(s); }
void Sucursal::agregarCliente(Cliente* c) { clientes->agregarCliente(c); }
void Sucursal::eliminarCliente(string cedula) { clientes->eliminarCliente(cedula); }
void Sucursal::agregarColaborador(Colaborador* c) { colaboradores->agregarColaborador(c); }
void Sucursal::eliminarColaborador(string cedula) { colaboradores->eliminarColaborador(cedula); }
