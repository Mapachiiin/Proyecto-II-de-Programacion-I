#include "SoliAlquiyContra.h"
#include <sstream>
using namespace std;

SoliAlquiyContra::SoliAlquiyContra(string cod, Cliente* Cli, Colaborador* Cola, string codSucur, string pVehi, int dA, Fecha* fIni, Fecha* fEnt, int pXD): codig(cod), cliente(Cli), colaborador(Cola), codSucu(codSucur), plaVehi(pVehi), diasAlqui(dA), fechaIni(fIni), fechaEntrega(fEnt), preXDia(pXD), preTotal(pXD*dA), estadoSoli("Pendiente"), esContrato(false), estadoContrato(""), diasNoUsados(0), reIntegro(0), diasAtraso(0), multa(0) {}
SoliAlquiyContra::~SoliAlquiyContra(){
	delete fechaIni;
	delete fechaEntrega;
}
void SoliAlquiyContra::cambiarEstadoSoli(string est){ 
	if(est!="Aprobada" && est!="Pendiente" && est!="Rechazada" && est!="Anulada") return;
	estadoSoli = est; 
}

string SoliAlquiyContra::getEstadoContrato() { return estadoContrato; }
string SoliAlquiyContra::getPlaVehi() { return plaVehi; }
string SoliAlquiyContra::getCodigo() { return codig; }
bool SoliAlquiyContra::getEsContrato() { return esContrato; }
string SoliAlquiyContra::getEstadoSoli(){ return estadoSoli; }
Cliente* SoliAlquiyContra::getCli() { return cliente; }
Colaborador* SoliAlquiyContra::getCola() { return colaborador; }

void SoliAlquiyContra::convertirAContrato(){
	if (estadoSoli != "Aprobada") return;
	estadoContrato = "Aprobado pendiente de ejecucion";
	esContrato = true;
}
void SoliAlquiyContra::setEstadoAlquilado(string est){
	estadoContrato = "Aprobado en alquiler";
}
void SoliAlquiyContra::finalizarContrato(int diasUsados) {
	if (esContrato == false) return;

	if (diasUsados < diasAlqui) {
		diasNoUsados = diasAlqui - diasUsados;
		reIntegro = preXDia * 0.7 * diasNoUsados;
		preTotal -= reIntegro;
		estadoContrato = "Finalizado con reintegro";

	}
	else if (diasUsados > diasAlqui) {
		diasAtraso = diasUsados - diasAlqui;
		multa = preXDia * 1.3 * diasAtraso;
		preTotal += multa;
		estadoContrato = "Finalizado con multa";
	}
	else {
		estadoContrato = "Finalizado sin cargos adicionales";
	}
}
void SoliAlquiyContra::calcularPrecioTotal() {
	preTotal = preXDia * diasAlqui;
}
string SoliAlquiyContra::mostrarInfo() {

	stringstream info;
	if(esContrato){
		info << "-----Contrato de Alquiler-----"<<endl;
		info << "Estado del contrato: " << estadoContrato <<endl;
	} else {
		info << "-----Solicitud de Alquiler-----"<<endl;
		info << "Estado de la solicitud: " << estadoSoli << endl;
	}

	info << "Codigo: " << codig << endl;
	info << "Cliente: " << cliente->getNombre() << endl;
	info << "Colaborador: " << colaborador->getNombre() << endl;
	info << "Sucursal: " << codSucu << endl;
	info << "Placa: " << plaVehi << endl;
	info << "Dias de alquiler: " << diasAlqui << endl;
	info << "Fecha de inicio: " << fechaIni->mostrarFecha() << endl;
	info << "Fecha de entrega: " << fechaEntrega->mostrarFecha() << endl;
	info << "Precio por dia: " << preXDia << endl;
	info << "Precio total: " << preTotal << endl;
	if(reIntegro>0){
		info << "Reintegro por entrega anticipada: " << reIntegro << endl;
		info << "Dias no usados: " << diasNoUsados << endl;
	}
	if(multa>0){
		info << "Multa por entrega tardia: " << multa << endl;
		info << "Dias de atraso: " << diasAtraso << endl;
	}
	return info.str();
}