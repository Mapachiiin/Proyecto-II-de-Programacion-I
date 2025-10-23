#include "SoliAlquiyContra.h"

SoliAlquiyContra::SoliAlquiyContra(string cod, string cCli, string cCola, string codSucur, string pVehi, int dA, Fecha* fIni, Fecha* fEnt, int pXD): codig(cod), cedClie(cCli), cedCola(cCola), codSucu(codSucur), plaVehi(pVehi), diasAlqui(dA), fechaIni(fIni), fechaEntrega(fEnt), preXDia(pXD), preTotal(pXD*dA), estadoSoli("Pendiente"), esContrato(false), estadoContrato("") {}
SoliAlquiyContra::~SoliAlquiyContra(){
	delete fechaIni;
	delete fechaEntrega;
}